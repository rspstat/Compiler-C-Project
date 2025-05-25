%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// External functions and variables from lexer
extern int yylex(void);
extern int yylineno;
extern char *yytext; // For error reporting

void yyerror(const char *s);

// Forward declarations for symbol table and code generation (conceptual)
// These would be implemented in separate .c files
// --- Symbol Table (Illustrative) ---
typedef struct Symbol {
    char *name;
    int type; // e.g., TYPE_INT, TYPE_CHAR, TYPE_ARRAY, TYPE_FUNCTION
    int scope_level;
    int address; // e.g., stack offset or global address
    int size; // For arrays
    // For functions: list of param types, return type
    struct Symbol *next;
} Symbol;

Symbol *symbol_table_head = NULL;
int current_scope_level = 0;
int next_address_global = 0;
int next_address_local = 0; // Relative to frame pointer

void add_symbol(const char* name, int type, int size_or_val); // Simplified
Symbol* lookup_symbol(const char* name); // Simplified

// --- Code Generation (Illustrative labels/opcodes) ---
int label_count = 0;
char* new_label() {
    char* lbl = (char*)malloc(10);
    sprintf(lbl, "L%d", label_count++);
    return lbl;
}

// Placeholder for printf instructions (emitted to stdout for now)
#define EMIT(...) printf(__VA_ARGS__); printf("\n")

// Placeholder for function argument count tracking
int current_arg_count = 0;

%}

// Define types for semantic values
%union {
    int ival;
    char *sval;
    // You might add nodes for an AST if building one
    struct { int type; char *name; } type_id; // For declarations
    struct { char *truelist; char *falselist; char *nextlist; } controllists; // For control flow backpatching
}

// Token declarations from lexer
%token <sval> T_IDENTIFIER
%token <ival> T_INTEGER_CONSTANT T_CHARACTER_CONSTANT
%token <sval> T_STRING_LITERAL

%token T_INT T_CHAR T_VOID
%token T_IF T_ELSE T_WHILE T_FOR T_DO T_SWITCH T_CASE T_DEFAULT T_BREAK T_CONTINUE T_RETURN
%token T_PRINT T_PRINTF T_SCANF

%token T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN
%token T_INC T_DEC
%token T_EQ T_NE T_LE T_GE
%token T_AND T_OR
%token T_LSHIFT T_RSHIFT

// Define types for non-terminals that need to carry values
%type <ival> type_specifier // Will hold T_INT, T_CHAR, etc. for type checking
%type <ival> expression assignment_expression conditional_expression logical_or_expression logical_and_expression
%type <ival> inclusive_or_expression exclusive_or_expression and_expression equality_expression relational_expression
%type <ival> shift_expression additive_expression multiplicative_expression unary_expression postfix_expression primary_expression
%type <ival> constant_expression constant // Keep track of value if possible
// **CORRECTION: Removed %type declaration for the undefined 'argument_expression_list'**
%type <sval> identifier_declarator // To pass identifier name up


// Operator precedence and associativity
%right '=' T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN
%right '?' ':' // Ternary operator
%left T_OR
%left T_AND
%left '|'
%left '^'
%left '&'
%left T_EQ T_NE
%left '<' '>' T_LE T_GE
%left T_LSHIFT T_RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right T_INC T_DEC '!' '~' // Unary operators (prefix)
// Postfix ++ --, function calls (), array subscript [] have higher precedence implicitly handled by grammar structure

%start program

%%

program:
    external_declaration_list
    ;

external_declaration_list:
    external_declaration
    | external_declaration_list external_declaration
    ;

external_declaration:
    function_definition
    | declaration
    ;

declaration:
    type_specifier declarator_list_opt ';' { EMIT("// End of global/local var declaration"); }
    ;

declarator_list_opt:
    /* empty */
    | declarator_list
    ;

declarator_list:
    declarator
    | declarator_list ',' declarator
    ;

declarator:
    identifier_declarator { EMIT("// Declared var %s", $1); /* add_symbol($1, type, 0 for scalar); */ }
    | identifier_declarator '=' initializer { EMIT("// Declared and initialized var %s", $1); /* add_symbol($1, type, 0); EMIT("POP %s", $1); (after initializer code) */ }
    | identifier_declarator '[' constant_expression ']' { EMIT("// Declared array %s[%d]", $1, $3); /* add_symbol($1, type, $3 as size); */ }
    | identifier_declarator '[' constant_expression ']' '=' initializer_list { EMIT("// Declared and initialized array %s[%d]", $1, $3); /* add_symbol, then code for init list */ }
    ;

identifier_declarator: T_IDENTIFIER { $$ = $1; } ; // Pass identifier name up

initializer:
    expression { EMIT("// Code for initializer expression"); /* Code to evaluate expr, result on stack */ }
    ;

initializer_list:
    '{' initializer_element_list '}' { EMIT("// End array initializer list"); }
    | '{' initializer_element_list ',' '}' { EMIT("// End array initializer list (with trailing comma)"); }
    ;

initializer_element_list:
    initializer { EMIT("// Array element init"); }
    | initializer_element_list ',' initializer { EMIT("// Array element init"); }
    ;


type_specifier:
    T_VOID { $$ = T_VOID; EMIT("// Type: void"); }
    | T_CHAR { $$ = T_CHAR; EMIT("// Type: char"); }
    | T_INT  { $$ = T_INT;  EMIT("// Type: int"); }
    ;

function_definition:
    type_specifier identifier_declarator '(' parameter_list_opt ')' compound_statement {
        EMIT("LABEL FUNC_%s // Start of function %s", $2, $2);
        EMIT("// END_FUNC %s", $2); /* $2 is function name from declarator */
    }
    ;

parameter_list_opt:
    /* empty */
    | parameter_list
    ;

parameter_list:
    parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration:
    type_specifier T_IDENTIFIER { EMIT("// Param: %s type %d", $2, $1); /* Add to symbol table as param */ }
    | type_specifier T_IDENTIFIER '[' ']' { EMIT("// Param: array %s[] type %d", $2, $1); /* Add as array param */ }
    ;

compound_statement:
    '{' { EMIT("// BEGIN_SCOPE"); /* current_scope_level++; next_address_local = 0; */ }
        declaration_list_opt statement_list_opt
    '}' { EMIT("// END_SCOPE"); /* current_scope_level--; */ }
    ;

declaration_list_opt:
    /* empty */
    | declaration_list
    ;

declaration_list: // For local declarations
    declaration
    | declaration_list declaration
    ;

statement_list_opt:
    /* empty */
    | statement_list
    ;

statement_list:
    statement
    | statement_list statement
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
    ';' { EMIT("// Empty statement"); }
    | expression ';' { EMIT("// Expression statement, result potentially discarded or used by POP"); /* If expression has value on stack, might need POP if not used */ }
    ;

selection_statement:
    T_IF '(' expression ')' { char *l_false = new_label(); EMIT("FJMP %s // if false jump", l_false); } statement { char *l_end = new_label(); EMIT("LABEL %s // after if-true block", l_false); }
    | T_IF '(' expression ')' { char *l_else = new_label(); char *l_end = new_label(); EMIT("FJMP %s // if false jump to else", l_else); } statement T_ELSE { EMIT("JMP %s // jump to end after then", l_end); EMIT("LABEL %s // else block", l_else); } statement { EMIT("LABEL %s // end if-else", l_end); }
    ;

iteration_statement:
    T_WHILE { char *l_cond = new_label(); char *l_body_end = new_label(); EMIT("LABEL %s // while condition", l_cond); /* Store l_cond as continue_target, l_body_end as break_target */ }
        '(' expression ')' { EMIT("FJMP %s // while false, jump to end", l_body_end); }
        statement { EMIT("JMP %s // back to while condition", l_cond); EMIT("LABEL %s // end while", l_body_end); }

    | T_DO { char *l_start = new_label(); char *l_cond_check = new_label(); char *l_break_target = new_label(); /* Store l_cond_check as continue_target, l_break_target as break_target */ EMIT("LABEL %s // do-while start", l_start); }
        statement
        T_WHILE { EMIT("LABEL %s // do-while condition check", l_cond_check); } '(' expression ')' ';' { EMIT("TJMP %s // do-while true, jump to start", l_start); EMIT("LABEL %s // end do-while", l_break_target); }

    | T_FOR '(' expression_opt ';' { char* l_cond = new_label(); char* l_inc = new_label(); char* l_body = new_label(); char* l_end = new_label(); /* Store l_inc as continue_target, l_end as break_target */ EMIT("LABEL %s // for condition", l_cond); }
        expression_opt ';' { EMIT("FJMP %s // for false, jump to end", l_end); EMIT("JMP %s // jump to body", l_body); EMIT("LABEL %s // for increment", l_inc); }
        expression_opt ')' { EMIT("JMP %s // back to for condition", l_cond); EMIT("LABEL %s // for body start", l_body); }
        statement { EMIT("JMP %s // jump to for increment", l_inc); EMIT("LABEL %s // end for", l_end); }
    ;

expression_opt:
    /* empty */ { /* No code if empty */ }
    | expression
    ;

jump_statement:
    T_CONTINUE ';' { EMIT("JMP <continue_label> // Continue"); /* Needs loop context for actual label */ }
    | T_BREAK ';'    { EMIT("JMP <break_label> // Break");    /* Needs loop/switch context for actual label */ }
    | T_RETURN ';'   { EMIT("RET // Return void"); }
    | T_RETURN expression ';' { EMIT("// Code for return expression on stack"); EMIT("RET_VAL // Return with value on stack"); }
    ;

switch_statement:
    T_SWITCH '(' expression ')' { char *l_end_switch = new_label(); /* Store l_end_switch for break */ EMIT("// Switch on expression (value on stack)"); }
    '{' case_list_opt default_opt '}' { EMIT("POP // Pop switch expression value if no case matched or after last case without break"); EMIT("LABEL %s // end_switch", l_end_switch); }
    ;

case_list_opt:
    /* empty */
    | case_list
    ;

case_list:
    case_statement
    | case_list case_statement
    ;

case_statement:
    T_CASE constant_expression ':' { char *l_next_case = new_label(); EMIT("DUP // duplicate switch expr"); EMIT("PUSH_CONST %d // case value", $2); EMIT("EQ"); EMIT("FJMP %s // if not equal, jump to next case logic", l_next_case); EMIT("POP // pop switch expr value (now matched)"); EMIT("POP // pop case value (constant)"); /* Begin case block statements */ } statement_list_opt { EMIT("LABEL %s // for fall-through or next case test", l_next_case); }
    ;

default_opt:
    /* empty */
    | T_DEFAULT ':' statement_list_opt { EMIT("LABEL <default_label>"); /* POP switch expr val if not already done */ }
    ;

constant:
    T_INTEGER_CONSTANT { $$ = $1; }
    | T_CHARACTER_CONSTANT { $$ = $1; }
    ;

// Expressions
expression:
    assignment_expression { $$ = $1; }
    ;

assignment_expression:
    conditional_expression { $$ = $1; }
    | unary_expression '=' assignment_expression {
        EMIT("// Assignment: Rvalue ($3) is on stack. Lvalue ($1) address is needed.");
        EMIT("// Code for $1 to ensure its address is on stack (if it's an identifier or array element)");
        EMIT("// (assignment_expression $3 already pushed its value)");
        EMIT("STORE_INDIRECT // Store value from top of stack into address below it"); $$ = $3;
    }
    | unary_expression T_ADD_ASSIGN assignment_expression { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("ADD"); EMIT("STORE_INDIRECT"); }
    | unary_expression T_SUB_ASSIGN assignment_expression { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("SUB"); EMIT("STORE_INDIRECT"); }
    | unary_expression T_MUL_ASSIGN assignment_expression { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("MUL"); EMIT("STORE_INDIRECT"); }
    | unary_expression T_DIV_ASSIGN assignment_expression { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("DIV"); EMIT("STORE_INDIRECT"); }
    | unary_expression T_MOD_ASSIGN assignment_expression { EMIT("// Code for LVAL addr ($1), then RVAL ($3)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("MOD"); EMIT("STORE_INDIRECT"); }
    ;

conditional_expression:
    logical_or_expression { $$ = $1; }
    | logical_or_expression '?' expression ':' conditional_expression {
        char *l_false = new_label();
        char *l_end = new_label();
        EMIT("FJMP %s // If logical_or_expr ($1) is false, jump to false part", l_false);
        // $3 is true expression (value will be on stack)
        EMIT("JMP %s // Jump to end", l_end);
        EMIT("LABEL %s // False part", l_false);
        // $5 is false expression (value will be on stack)
        EMIT("LABEL %s // End conditional", l_end);
        // Result is on stack
    }
    ;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression T_OR logical_and_expression { char *l_true = new_label(); char *l_end = new_label(); EMIT("DUP"); EMIT("TJMP %s // Short-circuit if first is true", l_true); EMIT("POP"); /* $3 is second expression */ EMIT("TJMP %s", l_true); EMIT("PUSH_CONST 0"); EMIT("JMP %s", l_end); EMIT("LABEL %s", l_true); EMIT("PUSH_CONST 1"); EMIT("LABEL %s", l_end); }
    ;

logical_and_expression:
    inclusive_or_expression { $$ = $1; }
    | logical_and_expression T_AND inclusive_or_expression { char *l_false = new_label(); char *l_end = new_label(); EMIT("DUP"); EMIT("FJMP %s // Short-circuit if first is false", l_false); EMIT("POP"); /* $3 is second expression */ EMIT("FJMP %s", l_false); EMIT("PUSH_CONST 1"); EMIT("JMP %s", l_end); EMIT("LABEL %s", l_false); EMIT("PUSH_CONST 0"); EMIT("LABEL %s", l_end); }
    ;

inclusive_or_expression:
    exclusive_or_expression { $$ = $1; }
    | inclusive_or_expression '|' exclusive_or_expression { EMIT("OR_BITWISE"); }
    ;

exclusive_or_expression:
    and_expression { $$ = $1; }
    | exclusive_or_expression '^' and_expression { EMIT("XOR_BITWISE"); }
    ;

and_expression: // Bitwise AND
    equality_expression { $$ = $1; }
    | and_expression '&' equality_expression { EMIT("AND_BITWISE"); }
    ;

equality_expression:
    relational_expression { $$ = $1; }
    | equality_expression T_EQ relational_expression { EMIT("EQ"); }
    | equality_expression T_NE relational_expression { EMIT("NE"); }
    ;

relational_expression:
    shift_expression { $$ = $1; }
    | relational_expression '<' shift_expression  { EMIT("LT"); }
    | relational_expression '>' shift_expression  { EMIT("GT"); }
    | relational_expression T_LE shift_expression { EMIT("LE"); }
    | relational_expression T_GE shift_expression { EMIT("GE"); }
    ;

shift_expression:
    additive_expression { $$ = $1; }
    | shift_expression T_LSHIFT additive_expression { EMIT("SHL"); }
    | shift_expression T_RSHIFT additive_expression { EMIT("SHR"); }
    ;

additive_expression:
    multiplicative_expression { $$ = $1; }
    | additive_expression '+' multiplicative_expression { EMIT("ADD"); }
    | additive_expression '-' multiplicative_expression { EMIT("SUB"); }
    ;

multiplicative_expression:
    unary_expression { $$ = $1; }
    | multiplicative_expression '*' unary_expression { EMIT("MUL"); }
    | multiplicative_expression '/' unary_expression { EMIT("DIV"); }
    | multiplicative_expression '%' unary_expression { EMIT("MOD"); }
    ;

unary_expression:
    postfix_expression { $$ = $1; }
    | T_INC unary_expression { EMIT("// Pre-Increment: code for $2 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("PUSH_CONST 1"); EMIT("ADD"); EMIT("STORE_INDIRECT_NOPOP"); /* leaves new value on stack */ }
    | T_DEC unary_expression { EMIT("// Pre-Decrement: code for $2 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("PUSH_CONST 1"); EMIT("SUB"); EMIT("STORE_INDIRECT_NOPOP"); }
    | '+' unary_expression   { /* No actual op, value is $2 */ EMIT("// Unary plus (no-op)"); }
    | '-' unary_expression   { EMIT("NEG // Negate value from $2"); }
    | '!' unary_expression   { EMIT("NOT_LOGICAL"); }
    | '~' unary_expression   { EMIT("NOT_BITWISE"); }
    ;


postfix_expression:
    primary_expression { $$ = $1; }
    | postfix_expression '[' expression ']' {
        EMIT("// Array access: $1 (base addr), $3 (index expr on stack)");
        EMIT("PUSH_CONST <element_size>"); // e.g. 4 for int
        EMIT("MUL // index * element_size");
        EMIT("ADD // base_addr + offset");
        // Result on stack is the ADDRESS of the element.
        // If used as RVALUE, it needs a LOAD_INDIRECT. This is handled by how it's used.
        // Example: if (a[i] == 0), after this, a LOAD_INDIRECT is needed before EQ
    }
    | T_IDENTIFIER '(' argument_expression_list_opt ')' { // Function call
        EMIT("CALL %s, %d // Call function", $1, current_arg_count);
        current_arg_count = 0; // Reset for next call
        // Result of function call (if any) is on stack
    }
    | postfix_expression T_INC { EMIT("// Post-Increment: code for $1 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("DUP_VAL"); EMIT("ROT_THREE"); /* old_val, addr, old_val -> addr, old_val, old_val */ EMIT("PUSH_CONST 1"); EMIT("ADD"); EMIT("STORE_INDIRECT"); /* consumes addr & new_val, leaves old_val */ }
    | postfix_expression T_DEC { EMIT("// Post-Decrement: code for $1 (LVAL address)"); EMIT("DUP_ADDR"); EMIT("LOAD_INDIRECT"); EMIT("DUP_VAL"); EMIT("ROT_THREE"); EMIT("PUSH_CONST 1"); EMIT("SUB"); EMIT("STORE_INDIRECT"); }
    | T_PRINT '(' expression ')' { EMIT("// Code for print's expression ($3) on stack"); EMIT("PRINT_INT"); } // Specific rule for print
    | T_PRINTF '(' T_STRING_LITERAL argument_list_for_printf_opt ')' { EMIT("PUSH_STRING_CONST \"%s\"", $3); EMIT("PRINTF %d", current_arg_count + 1); current_arg_count = 0; }
    | T_SCANF '(' T_STRING_LITERAL argument_list_for_scanf_opt ')' { EMIT("PUSH_STRING_CONST \"%s\"", $3); EMIT("SCANF %d", current_arg_count +1 ); current_arg_count = 0; }
    ;

argument_list_for_printf_opt:
    /* empty */ { current_arg_count = 0; }
    | ',' argument_expression_list_printf { /* current_arg_count set by list */ }
    ;

argument_expression_list_printf:
    expression { current_arg_count = 1; EMIT("// Arg 1 for printf"); }
    | argument_expression_list_printf ',' expression { current_arg_count++; EMIT("// Arg %d for printf", current_arg_count); }
    ;

argument_list_for_scanf_opt:
    /* empty */ { current_arg_count = 0; }
    | ',' argument_expression_list_scanf { /* current_arg_count set by list */ }
    ;

argument_expression_list_scanf:
    '&' T_IDENTIFIER { current_arg_count = 1; EMIT("PUSH_ADDR %s // Arg 1 for scanf", $2); } // Assuming scanf takes addresses
    | argument_expression_list_scanf ',' '&' T_IDENTIFIER { current_arg_count++; EMIT("PUSH_ADDR %s // Arg %d for scanf", $4, current_arg_count); }
    ;


argument_expression_list_opt: // General arguments for user functions
    /* empty */ { current_arg_count = 0; }
    | argument_expression_list_general
    ;

argument_expression_list_general:
    assignment_expression { current_arg_count = 1; EMIT("// User func Arg 1"); }
    | argument_expression_list_general ',' assignment_expression { current_arg_count++; EMIT("// User func Arg %d", current_arg_count); }
    ;


primary_expression:
    T_IDENTIFIER {
        EMIT("PUSH_VAR_OR_ADDR %s // If LVAL context -> ADDR, if RVAL context -> VAL", $1);
        // This is tricky. The context (LHS of assign, arg to scanf(&arg), array index operation vs. RHS) matters.
        // A common approach is to always push address for identifiers, and then explicitly LOAD if value is needed.
        // Or, have different rules/flags. For now, assume RVALUE use:
        EMIT("PUSH_VAL %s // Push value of variable", $1);
    }
    | constant { EMIT("PUSH_CONST %d", $1); $$ = $1; }
    | T_STRING_LITERAL { EMIT("PUSH_STRING_ADDR \"%s\"", $1); /* Store string in data segment, push address */ }
    | '(' expression ')' { $$ = $2; /* Value is that of inner expression */ }
    ;

constant_expression: // Simplified: only integer constants for array sizes and case labels
    T_INTEGER_CONSTANT { $$ = $1; }
    ;

%%

// Error reporting function
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d near token '%s'\n", s, yylineno, yytext);
}

// Symbol table / code gen stubs (if not defined above or elsewhere)
void add_symbol(const char* name, int type, int size_or_val) {
    // Basic implementation
    EMIT("// SYMBOL_ADD: %s, type %d, size/val %d", name, type, size_or_val);
}
Symbol* lookup_symbol(const char* name) {
    EMIT("// SYMBOL_LOOKUP: %s", name);
    return NULL; // Placeholder
}


// Main function to drive the parser
// (Often in a separate file, but can be here for self-contained yacc file)
/*
int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file; // Direct yylex to read from this file
    } else {
        yyin = stdin; // Default to standard input
    }

    EMIT("// --- BEGIN STACK CODE ---");
    EMIT("CALL main"); // Standard entry point
    EMIT("HALT");

    // Initialize symbol table, etc. if needed

    if (yyparse() == 0) { // yyparse returns 0 on success
        EMIT("// --- PARSING SUCCESSFUL ---");
    } else {
        EMIT("// --- PARSING FAILED ---");
    }


    EMIT("// --- END STACK CODE ---");
    return 0;
}
*/