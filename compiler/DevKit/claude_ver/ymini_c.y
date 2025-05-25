%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int line_no;

void yyerror(const char *s);
void emit(const char *op);
void emit_num(const char *op, int num);
void emit_str(const char *op, const char *str);

// Symbol table structures
typedef struct symbol {
    char *name;
    int type;        // 0: int, 1: array, 2: function
    int offset;      // stack offset for variables
    int size;        // array size or function param count
    struct symbol *next;
} Symbol;

Symbol *symbol_table = NULL;
int stack_offset = 0;
int label_counter = 0;
int current_func_params = 0;

// Function prototypes
Symbol* lookup_symbol(const char *name);
void add_symbol(const char *name, int type, int size);
void enter_scope();
void exit_scope();
char* new_label();
void emit_label(const char *label);
void emit_jump(const char *op, const char *label);

// Label stack for nested control structures
char *label_stack[100];
int label_stack_ptr = 0;

void push_label(const char *label) {
    if (label_stack_ptr < 100) {
        label_stack[label_stack_ptr++] = strdup(label);
    }
}

char* pop_label() {
    if (label_stack_ptr > 0) {
        return label_stack[--label_stack_ptr];
    }
    return NULL;
}

%}

%union {
    int number;
    char *string;
}

%token <number> NUMBER
%token <string> IDENTIFIER STRING
%token INT VOID CHAR
%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT
%token BREAK CONTINUE RETURN
%token PRINTF SCANF PRINT
%token INCREMENT DECREMENT
%token PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token LEFT_SHIFT RIGHT_SHIFT
%token LE GE EQ NE AND OR

%type <number> type
%type <string> function_header

%right '=' PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%right '?' ':'
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQ NE
%left '<' '>' LE GE
%left LEFT_SHIFT RIGHT_SHIFT
%left '+' '-'
%left '*' '/' '%'
%right '!' '~' UMINUS UPLUS
%right INCREMENT DECREMENT
%left '[' ']' '(' ')'

%%

program: 
    declaration_list
    ;

declaration_list:
    declaration_list declaration
    | declaration
    ;

declaration:
    var_declaration
    | function_declaration
    ;

var_declaration:
    type IDENTIFIER ';' {
        add_symbol($2, 0, 1);
        emit("ALLOC");
        if ($2) free($2);
    }
    | type IDENTIFIER '[' NUMBER ']' ';' {
        add_symbol($2, 1, $4);
        emit_num("ALLOC", $4);
        if ($2) free($2);
    }
    | type IDENTIFIER '=' expression ';' {
        add_symbol($2, 0, 1);
        emit("ALLOC");
        Symbol *sym = lookup_symbol($2);
        if (sym) emit_num("STORE", sym->offset);
        if ($2) free($2);
    }
    ;

function_declaration:
    function_header compound_statement {
        emit("RET");
        if ($1) {
            emit_label($1);
            free($1);
        }
    }
    ;

function_header:
    type IDENTIFIER '(' parameter_list ')' {
        $$ = strdup($2);
        add_symbol($2, 2, current_func_params);
        emit_str("FUNC", $2);
        current_func_params = 0;
        enter_scope();
        if ($2) free($2);
    }
    | type IDENTIFIER '(' ')' {
        $$ = strdup($2);
        add_symbol($2, 2, 0);
        emit_str("FUNC", $2);
        enter_scope();
        if ($2) free($2);
    }
    ;

parameter_list:
    parameter_list ',' parameter {
        current_func_params++;
    }
    | parameter {
        current_func_params = 1;
    }
    ;

parameter:
    type IDENTIFIER {
        add_symbol($2, 0, 1);
        if ($2) free($2);
    }
    | type IDENTIFIER '[' ']' {
        add_symbol($2, 1, 0);
        if ($2) free($2);
    }
    ;

type:
    INT { $$ = 0; }
    | VOID { $$ = 1; }
    | CHAR { $$ = 2; }
    ;

compound_statement:
    '{' local_declarations statement_list '}' {
        exit_scope();
    }
    ;

local_declarations:
    local_declarations var_declaration
    | /* empty */
    ;

statement_list:
    statement_list statement
    | /* empty */
    ;

statement:
    expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | switch_statement
    ;

expression_statement:
    expression ';' {
        emit("POP");
    }
    | ';'
    ;

selection_statement:
    IF '(' expression ')' statement ELSE statement {
        char *else_label = new_label();
        char *end_label = new_label();
        emit_jump("JZ", else_label);
        emit_jump("JMP", end_label);
        emit_label(else_label);
        emit_label(end_label);
        free(else_label);
        free(end_label);
    }
    | IF '(' expression ')' statement {
        char *end_label = new_label();
        emit_jump("JZ", end_label);
        emit_label(end_label);
        free(end_label);
    }
    ;

iteration_statement:
    WHILE '(' expression ')' statement {
        char *loop_start = new_label();
        char *loop_end = new_label();
        emit_label(loop_start);
        emit_jump("JZ", loop_end);
        emit_jump("JMP", loop_start);
        emit_label(loop_end);
        free(loop_start);
        free(loop_end);
    }
    | FOR '(' expression_statement expression ';' expression ')' statement {
        char *loop_start = new_label();
        char *loop_end = new_label();
        char *loop_inc = new_label();
        emit_label(loop_start);
        emit_jump("JZ", loop_end);
        emit_jump("JMP", loop_inc);
        emit_label(loop_inc);
        emit_jump("JMP", loop_start);
        emit_label(loop_end);
        free(loop_start);
        free(loop_end);
        free(loop_inc);
    }
    | DO statement WHILE '(' expression ')' ';' {
        char *loop_start = new_label();
        emit_label(loop_start);
        emit_jump("JNZ", loop_start);
        free(loop_start);
    }
    ;

switch_statement:
    SWITCH '(' expression ')' '{' case_list '}' {
        char *end_label = new_label();
        emit_label(end_label);
        free(end_label);
    }
    ;

case_list:
    case_list case_statement
    | case_statement
    ;

case_statement:
    CASE NUMBER ':' statement_list {
        char *next_case = new_label();
        emit("DUP");
        emit_num("CONST", $2);
        emit("EQ");
        emit_jump("JZ", next_case);
        emit("POP");
        emit_label(next_case);
        free(next_case);
    }
    | DEFAULT ':' statement_list {
        emit("POP");
    }
    ;

jump_statement:
    RETURN ';' {
        emit("RET");
    }
    | RETURN expression ';' {
        emit("RET");
    }
    | BREAK ';' {
        emit("BREAK");
    }
    | CONTINUE ';' {
        emit("CONTINUE");
    }
    ;

expression:
    assignment_expression
    ;

assignment_expression:
    conditional_expression
    | unary_expression '=' assignment_expression {
        emit("ASSIGN");
    }
    | unary_expression PLUS_ASSIGN assignment_expression {
        emit("PLUS_ASSIGN");
    }
    | unary_expression MINUS_ASSIGN assignment_expression {
        emit("MINUS_ASSIGN");
    }
    | unary_expression MUL_ASSIGN assignment_expression {
        emit("MUL_ASSIGN");
    }
    | unary_expression DIV_ASSIGN assignment_expression {
        emit("DIV_ASSIGN");
    }
    | unary_expression MOD_ASSIGN assignment_expression {
        emit("MOD_ASSIGN");
    }
    ;

conditional_expression:
    logical_or_expression
    | logical_or_expression '?' expression ':' conditional_expression {
        emit("TERNARY");
    }
    ;

logical_or_expression:
    logical_and_expression
    | logical_or_expression OR logical_and_expression {
        emit("OR");
    }
    ;

logical_and_expression:
    inclusive_or_expression
    | logical_and_expression AND inclusive_or_expression {
        emit("AND");
    }
    ;

inclusive_or_expression:
    exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression {
        emit("BOR");
    }
    ;

exclusive_or_expression:
    and_expression
    | exclusive_or_expression '^' and_expression {
        emit("XOR");
    }
    ;

and_expression:
    equality_expression
    | and_expression '&' equality_expression {
        emit("BAND");
    }
    ;

equality_expression:
    relational_expression
    | equality_expression EQ relational_expression {
        emit("EQ");
    }
    | equality_expression NE relational_expression {
        emit("NE");
    }
    ;

relational_expression:
    shift_expression
    | relational_expression '<' shift_expression {
        emit("LT");
    }
    | relational_expression '>' shift_expression {
        emit("GT");
    }
    | relational_expression LE shift_expression {
        emit("LE");
    }
    | relational_expression GE shift_expression {
        emit("GE");
    }
    ;

shift_expression:
    additive_expression
    | shift_expression LEFT_SHIFT additive_expression {
        emit("SHL");
    }
    | shift_expression RIGHT_SHIFT additive_expression {
        emit("SHR");
    }
    ;

additive_expression:
    multiplicative_expression
    | additive_expression '+' multiplicative_expression {
        emit("ADD");
    }
    | additive_expression '-' multiplicative_expression {
        emit("SUB");
    }
    ;

multiplicative_expression:
    unary_expression
    | multiplicative_expression '*' unary_expression {
        emit("MUL");
    }
    | multiplicative_expression '/' unary_expression {
        emit("DIV");
    }
    | multiplicative_expression '%' unary_expression {
        emit("MOD");
    }
    ;

unary_expression:
    postfix_expression
    | INCREMENT unary_expression {
        emit("PRE_INC");
    }
    | DECREMENT unary_expression {
        emit("PRE_DEC");
    }
    | '+' unary_expression %prec UPLUS {
        // No operation needed
    }
    | '-' unary_expression %prec UMINUS {
        emit("NEG");
    }
    | '!' unary_expression {
        emit("NOT");
    }
    | '~' unary_expression {
        emit("BNOT");
    }
    ;

postfix_expression:
    primary_expression
    | postfix_expression '[' expression ']' {
        emit("ARRAY_ACCESS");
    }
    | postfix_expression '(' ')' {
        emit_str("CALL", "function");
    }
    | postfix_expression '(' argument_expression_list ')' {
        emit_str("CALL", "function");
    }
    | postfix_expression INCREMENT {
        emit("POST_INC");
    }
    | postfix_expression DECREMENT {
        emit("POST_DEC");
    }
    | PRINT '(' expression ')' {
        emit("PRINT");
    }
    | PRINTF '(' STRING ')' {
        emit_str("PRINTF", $3);
        if ($3) free($3);
    }
    | PRINTF '(' STRING ',' argument_expression_list ')' {
        emit_str("PRINTF", $3);
        if ($3) free($3);
    }
    | SCANF '(' STRING ',' argument_expression_list ')' {
        emit_str("SCANF", $3);
        if ($3) free($3);
    }
    ;

argument_expression_list:
    assignment_expression
    | argument_expression_list ',' assignment_expression
    ;

primary_expression:
    IDENTIFIER {
        Symbol *sym = lookup_symbol($1);
        if (sym) {
            if (sym->type == 2) { // function
                emit_str("FUNC_ADDR", $1);
            } else {
                emit_num("LOAD", sym->offset);
            }
        } else {
            fprintf(stderr, "Undefined variable: %s\n", $1);
        }
        if ($1) free($1);
    }
    | NUMBER {
        emit_num("CONST", $1);
    }
    | STRING {
        emit_str("STRING", $1);
        if ($1) free($1);
    }
    | '(' expression ')'
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_no, s);
}

void emit(const char *op) {
    printf("%s\n", op);
}

void emit_num(const char *op, int num) {
    printf("%s %d\n", op, num);
}

void emit_str(const char *op, const char *str) {
    printf("%s %s\n", op, str);
}

Symbol* lookup_symbol(const char *name) {
    Symbol *sym = symbol_table;
    while (sym) {
        if (strcmp(sym->name, name) == 0) {
            return sym;
        }
        sym = sym->next;
    }
    return NULL;
}

void add_symbol(const char *name, int type, int size) {
    if (!name) return;
    Symbol *sym = malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->size = size;
    sym->offset = stack_offset++;
    sym->next = symbol_table;
    symbol_table = sym;
}

void enter_scope() {
    // Simple scope management
}

void exit_scope() {
    // Pop symbols from current scope
}

char* new_label() {
    char *label = malloc(20);
    sprintf(label, "L%d", label_counter++);
    return label;
}

void emit_label(const char *label) {
    printf("%s:\n", label);
}

void emit_jump(const char *op, const char *label) {
    printf("%s %s\n", op, label);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    // Initialize with main function call
    emit("START");
    emit_str("CALL", "main");
    emit("HALT");
    
    yyparse();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    return 0;
}