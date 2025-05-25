%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int line_num;
void yyerror(const char *s);

int temp_var_count = 0;
int label_count = 0;
FILE *output_file;

void emit(const char *op, const char *arg1, const char *arg2, const char *result);
char* new_temp();
char* new_label();
void emit_assignment(const char *var, const char *expr);
%}

%union {
    int ival;
    float fval;
    char *sval;
}

%token <ival> INTEGER
%token <fval> FLOAT
%token <sval> ID
%token MAIN IF ELSE WHILE FOR INT FLOAT_TYPE RETURN BREAK CONTINUE FUNCTION VOID
%token EQ NE LE GE AND OR INC DEC PLUS_ASSIGN MINUS_ASSIGN

%type <sval> expression term factor assignment_stmt
%type <sval> relational_expr logical_expr

%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '!' UMINUS
%right INC DEC

%%

program:
    function_list
    ;

function_list:
    function_list function
    | function
    ;

function:
    MAIN '(' ')' compound_stmt {
        emit("HALT", "", "", "");
    }
    | type ID '(' parameter_list ')' compound_stmt {
        emit("RET", "", "", "");
    }
    | VOID ID '(' parameter_list ')' compound_stmt {
        emit("RET", "", "", "");
    }
    | MAIN '(' ')' '{' stmt_list '}' {
        emit("HALT", "", "", "");
    }
    ;

parameter_list:
    parameter_list ',' parameter
    | parameter
    |
    ;

parameter:
    type ID
    ;

type:
    INT
    | FLOAT_TYPE
    ;

compound_stmt:
    '{' stmt_list '}'
    ;

stmt_list:
    stmt_list stmt
    | stmt
    |
    ;

stmt:
    assignment_stmt ';' {
        free($1);
    }
    | compound_stmt
    | if_stmt
    | while_stmt
    | for_stmt
    | return_stmt ';'
    | BREAK ';' {
        emit("JMP", "break_label", "", "");
    }
    | CONTINUE ';' {
        emit("JMP", "continue_label", "", "");
    }
    | expression ';' {
        free($1);
    }
    | type ID ';' {
        free($2);
    }
    | ';'
    ;

assignment_stmt:
    ID '=' expression {
        emit("STORE", $3, "", $1);
        $$ = strdup($1);
        free($1);
        free($3);
    }
    | ID PLUS_ASSIGN expression {
        char *temp = new_temp();
        emit("LOAD", $1, "", temp);
        emit("ADD", temp, $3, temp);
        emit("STORE", temp, "", $1);
        $$ = strdup($1);
        free($1);
        free($3);
    }
    | ID MINUS_ASSIGN expression {
        char *temp = new_temp();
        emit("LOAD", $1, "", temp);
        emit("SUB", temp, $3, temp);
        emit("STORE", temp, "", $1);
        $$ = strdup($1);
        free($1);
        free($3);
    }
    | ID INC {
        char *temp = new_temp();
        emit("LOAD", $1, "", temp);
        emit("ADD", temp, "1", temp);
        emit("STORE", temp, "", $1);
        $$ = strdup($1);
        free($1);
    }
    | ID DEC {
        char *temp = new_temp();
        emit("LOAD", $1, "", temp);
        emit("SUB", temp, "1", temp);
        emit("STORE", temp, "", $1);
        $$ = strdup($1);
        free($1);
    }
    ;

if_stmt:
    IF '(' logical_expr ')' {
        char *false_label = new_label();
        emit("JZ", $3, false_label, "");
    } stmt {
        char *false_label = strdup("L");
        strcat(false_label, "false");
        emit("LABEL", false_label, "", "");
        free($3);
    }
    | IF '(' logical_expr ')' {
        char *false_label = new_label();
        char *end_label = new_label();
        emit("JZ", $3, false_label, "");
    } stmt ELSE {
        char *end_label = strdup("L");
        strcat(end_label, "end");
        emit("JMP", end_label, "", "");
        char *false_label = strdup("L");
        strcat(false_label, "false");
        emit("LABEL", false_label, "", "");
    } stmt {
        char *end_label = strdup("L");
        strcat(end_label, "end");
        emit("LABEL", end_label, "", "");
        free($3);
    }
    ;

while_stmt:
    WHILE {
        char *start_label = new_label();
        emit("LABEL", start_label, "", "");
    } '(' logical_expr ')' {
        char *end_label = new_label();
        emit("JZ", $4, end_label, "");
    } stmt {
        char *start_label = strdup("L");
        strcat(start_label, "start");
        char *end_label = strdup("L");
        strcat(end_label, "end");
        emit("JMP", start_label, "", "");
        emit("LABEL", end_label, "", "");
        free($4);
    }
    ;

for_stmt:
    FOR '(' assignment_stmt ';' {
        char *start_label = new_label();
        emit("LABEL", start_label, "", "");
    } logical_expr ';' {
        char *body_label = new_label();
        char *end_label = new_label();
        emit("JNZ", $6, body_label, "");
        emit("JMP", end_label, "", "");
        emit("LABEL", body_label, "", "");
    } assignment_stmt ')' stmt {
        char *start_label = strdup("L");
        strcat(start_label, "start");
        char *end_label = strdup("L");
        strcat(end_label, "end");
        emit("JMP", start_label, "", "");
        emit("LABEL", end_label, "", "");
        free($3);
        free($6);
        free($9);
    }
    ;

return_stmt:
    RETURN expression {
        emit("RET", $2, "", "");
        free($2);
    }
    | RETURN
    ;

logical_expr:
    logical_expr AND relational_expr {
        char *temp = new_temp();
        emit("AND", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | logical_expr OR relational_expr {
        char *temp = new_temp();
        emit("OR", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | relational_expr {
        $$ = $1;
    }
    ;

relational_expr:
    expression '<' expression {
        char *temp = new_temp();
        emit("LT", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | expression '>' expression {
        char *temp = new_temp();
        emit("GT", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | expression LE expression {
        char *temp = new_temp();
        emit("LE", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | expression GE expression {
        char *temp = new_temp();
        emit("GE", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | expression EQ expression {
        char *temp = new_temp();
        emit("EQ", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | expression NE expression {
        char *temp = new_temp();
        emit("NE", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | expression {
        $$ = $1;
    }
    ;

expression:
    expression '+' term {
        char *temp = new_temp();
        emit("ADD", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | expression '-' term {
        char *temp = new_temp();
        emit("SUB", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | term {
        $$ = $1;
    }
    ;

term:
    term '*' factor {
        char *temp = new_temp();
        emit("MUL", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | term '/' factor {
        char *temp = new_temp();
        emit("DIV", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | term '%' factor {
        char *temp = new_temp();
        emit("MOD", $1, $3, temp);
        $$ = temp;
        free($1);
        free($3);
    }
    | factor {
        $$ = $1;
    }
    ;

factor:
    '(' expression ')' {
        $$ = $2;
    }
    | ID {
        $$ = strdup($1);
        free($1);
    }
    | INTEGER {
        char *temp = malloc(20);
        sprintf(temp, "%d", $1);
        $$ = temp;
    }
    | FLOAT {
        char *temp = malloc(20);
        sprintf(temp, "%.2f", $1);
        $$ = temp;
    }
    | '-' factor %prec UMINUS {
        char *temp = new_temp();
        emit("NEG", $2, "", temp);
        $$ = temp;
        free($2);
    }
    | '!' factor {
        char *temp = new_temp();
        emit("NOT", $2, "", temp);
        $$ = temp;
        free($2);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}

void emit(const char *op, const char *arg1, const char *arg2, const char *result) {
    if (output_file) {
        if (strlen(arg2) > 0 && strlen(result) > 0) {
            fprintf(output_file, "%s %s %s %s\n", op, arg1, arg2, result);
        } else if (strlen(arg1) > 0 && strlen(result) > 0) {
            fprintf(output_file, "%s %s %s\n", op, arg1, result);
        } else if (strlen(arg1) > 0) {
            fprintf(output_file, "%s %s\n", op, arg1);
        } else {
            fprintf(output_file, "%s\n", op);
        }
    }
}

char* new_temp() {
    char *temp = malloc(20);
    sprintf(temp, "T%d", temp_var_count++);
    return temp;
}

char* new_label() {
    char *label = malloc(20);
    sprintf(label, "L%d", label_count++);
    return label;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.cbc output.sm\n", argv[0]);
        return 1;
    }
    
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }
    
    output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }
    
    extern FILE *yyin;
    yyin = input_file;
    
    if (yyparse() == 0) {
        printf("Compilation successful\n");
    } else {
        printf("Compilation failed\n");
    }
    
    fclose(input_file);
    fclose(output_file);
    return 0;
}