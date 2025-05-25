/* compiler.y - Bison 파서 + 코드 생성기 */
/* 주석은 모두 한글 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* ---------- 심볼 테이블 ---------- */
typedef struct symrec {
    char *name;
    int   offset;    /* 데이터 영역 오프셋 */
    int   size;      /* 배열 길이 (1 = 스칼라) */
    struct symrec *next;
} symrec;

static symrec *symtab     = NULL;
static int     data_offset = 0;

/* yylineno 는 lexer에서 extern 선언 */
extern int yylineno;

/* -------- 함수 원형 -------- */
int  yylex(void);
void yyerror(const char *s);

/* -------- 코드 출력 -------- */
static void emit(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    printf("\n");
    va_end(ap);
}

/* -------- 심볼 테이블 헬퍼 -------- */
static symrec *putsym(const char *name, int size)
{
    symrec *s = (symrec*)malloc(sizeof(symrec));
    s->name   = strdup(name);
    s->offset = data_offset;
    s->size   = size;
    s->next   = symtab;
    symtab    = s;
    data_offset += size;
    return s;
}
static symrec *getsym(const char *name)
{
    for(symrec *s = symtab; s; s = s->next)
        if(strcmp(s->name, name) == 0) return s;
    return NULL;
}

/* -------- 레이블 관리 -------- */
static int label_count = 0;
static int new_label(void) { return label_count++; }
%}

/* ---------- YYSTYPE ---------- */
%union {
    int    ival;
    double fval;
    char*  sval;
    char*  id;
    int    lbl;      /* 레이블 번호 전달 */
}

/* ---------- 토큰 ---------- */
%token <id>    IDENT
%token <ival>  INT_CONST
%token <fval>  FLOAT_CONST
%token <sval>  STRING
%token <ival>  CHAR_CONST

%token K_INT K_FLOAT K_CHAR K_VOID

%token IF ELSE WHILE FOR DO
%token BREAK CONTINUE RETURN
%token SWITCH CASE DEFAULT

%token PRINT READ

%token INC_OP DEC_OP
%token ADDEQ SUBEQ MULEQ DIVEQ MODEQ

%token EQ_OP NE_OP LE_OP GE_OP
%token AND_OP OR_OP
%token LSHIFT RSHIFT
%token ARROW

/* ---------- 연산자 우선순위 ---------- */
%left  OR_OP
%left  AND_OP
%left  EQ_OP NE_OP
%left  '<' '>' LE_OP GE_OP
%left  '+' '-'
%left  '*' '/' '%'
%right '!' '~' INC_OP DEC_OP
%right UMINUS
%right '?' ':'

%type <lbl> bool_expr while_head
%type <ival> assignment_expr_opt

%%

translation_unit
    : external_list                { emit("; 데이터 영역 크기 = %d", data_offset); }
    ;

external_list
    : external_list external
    | external
    ;

external
    : func_def
    | declaration
    ;

/* ---------- 선언 ---------- */
declaration
    : type IDENT ';'                        { putsym($2, 1); }
    | type IDENT '[' INT_CONST ']' ';'      { putsym($2, $4); }
    ;

type
    : K_INT
    | K_FLOAT
    | K_CHAR
    | K_VOID
    ;

/* ---------- 함수 정의 ---------- */
func_def
    : type IDENT '(' param_list_opt ')' compound_stmt
        {
            emit("FUNC %s:", $2);           /* 함수 시작 라벨 */
            /* compound_stmt 에서 본문 코드 이미 출력 */
            emit("RET");                    /* 기본 반환 */
        }
    ;

param_list_opt
    : param_list
    | /* 공백 */
    ;

param_list
    : type IDENT
    | param_list ',' type IDENT
    ;

/* ---------- 복합문 ---------- */
compound_stmt
    : '{' stmt_list_opt '}'                 /* 블록 */
    ;

stmt_list_opt
    : stmt_list
    | /* 공백 */
    ;

stmt_list
    : stmt_list stmt
    | stmt
    ;

/* ---------- 문장 ---------- */
stmt
    : ';'                                   /* 빈 문장 */
    | expr_stmt ';'
    | compound_stmt
    | selection_stmt
    | iteration_stmt
    | jump_stmt
    | io_stmt
    ;

/* 표현식 문장 */
expr_stmt
    : assignment_expr
    ;

/* ---------- 입출력 ---------- */
io_stmt
    : PRINT '(' assignment_expr ')' ';'     { emit("OUT_INT"); }
    | READ '(' IDENT ')' ';'
        {
            symrec *s = getsym($3);
            if(!s) yyerror("변수 미선언");
            emit("IN_INT");
            emit("STORE %d", s->offset);
        }
    ;

/* ---------- 선택문 (if / if-else) ---------- */
selection_stmt
    : IF '(' bool_expr ')' stmt
        { emit("LABEL L%d", $3); /* false 분기 */ }
    | IF '(' bool_expr ')' stmt ELSE stmt
        {
            int Lelse = $3;
            int Lend  = new_label();
            emit("JMP L%d", Lend);  /* 참 분기 끝나면 건너뜀 */
            emit("LABEL L%d", Lelse);       /* else 시작 */
            /* else 본문($6) */
            emit("LABEL L%d", Lend);        /* if-else 종료 */
        }
    ;

/* bool_expr: 조건 계산 후 거짓이면 JZ */
bool_expr
    : assignment_expr
        {
            int lbl = new_label();
            emit("JZ L%d", lbl);    /* 0이면 lbl 로 */
            $$ = lbl;
        }
    ;

/* ---------- 반복문 ---------- */
iteration_stmt
    : WHILE while_head stmt
        {
            int Lstart = $2;
            int Lend   = new_label();
            emit("JMP L%d", Lstart); /* 반복 */
            emit("LABEL L%d", Lend); /* while 종료 */
        }
    | DO stmt WHILE '(' bool_expr ')' ';'
        {
            int Lstart = new_label();
            emit("LABEL L%d", Lstart); /* do 본문 */
            /* stmt ($2) 코드 이미 출력 */
            int Lfalse = $5;           /* bool_expr 에서 받은 레이블 */
            emit("JMP L%d", Lstart);
            emit("LABEL L%d", Lfalse);
        }
    | FOR '(' assignment_expr_opt ';' assignment_expr_opt ';' assignment_expr_opt ')' stmt
        {
            yyerror("for 문은 while 형태로 변환하여 직접 구현하세요");
        }
    ;

while_head
    : '(' bool_expr ')'                    { $$ = new_label(); emit("LABEL L%d", $$); }
    ;

/* ---------- 점프문 ---------- */
jump_stmt
    : BREAK ';'                            { emit("; break 구현 필요"); }
    | CONTINUE ';'                         { emit("; continue 구현 필요"); }
    | RETURN ';'                           { emit("RET"); }
    | RETURN assignment_expr ';'
        { emit("RET"); }
    ;

/* ---------- 표현식 ---------- */
assignment_expr
    : unary_expr '=' assignment_expr       { emit("STORE"); }
    | unary_expr ADDEQ assignment_expr     { emit("DUP"); emit("LOAD"); emit("ADD"); emit("STORE"); }
    | logical_or_expr
    ;

assignment_expr_opt
    : assignment_expr
    | /* 공백 */                           { $$ = 0; }
    ;

/* || */
logical_or_expr
    : logical_or_expr OR_OP logical_and_expr   { emit("OR"); }
    | logical_and_expr
    ;

/* && */
logical_and_expr
    : logical_and_expr AND_OP equality_expr    { emit("AND"); }
    | equality_expr
    ;

/* == != */
equality_expr
    : equality_expr EQ_OP relational_expr      { emit("EQ"); }
    | equality_expr NE_OP relational_expr      { emit("NEQ"); }
    | relational_expr
    ;

/* < > <= >= */
relational_expr
    : relational_expr '<' additive_expr        { emit("LT"); }
    | relational_expr '>' additive_expr        { emit("GT"); }
    | relational_expr LE_OP additive_expr      { emit("LE"); }
    | relational_expr GE_OP additive_expr      { emit("GE"); }
    | additive_expr
    ;

/* + - */
additive_expr
    : additive_expr '+' multiplicative_expr    { emit("ADD"); }
    | additive_expr '-' multiplicative_expr    { emit("SUB"); }
    | multiplicative_expr
    ;

/* * / % */
multiplicative_expr
    : multiplicative_expr '*' unary_expr       { emit("MUL"); }
    | multiplicative_expr '/' unary_expr       { emit("DIV"); }
    | multiplicative_expr '%' unary_expr       { emit("MOD"); }
    | unary_expr
    ;

/* 단항 */
unary_expr
    : primary_expr
    | '-' unary_expr %prec UMINUS              { emit("NEG"); }
    | '!' unary_expr                           { emit("NOT"); }
    | INC_OP unary_expr                        { yyerror("전위 ++ 직접 구현 필요"); }
    | DEC_OP unary_expr                        { yyerror("전위 -- 직접 구현 필요"); }
    ;

/* 기본 단위 */
primary_expr
    : IDENT
        {
            symrec *s = getsym($1);
            if(!s) yyerror("변수 미선언");
            emit("PUSHV %d", s->offset);
        }
    | IDENT '[' assignment_expr ']'
        {
            symrec *s = getsym($1);
            if(!s) yyerror("배열 미선언");
            emit("PUSH %d", s->offset);  /* base */
            /* index (assignment_expr) 결과 스택에 존재 */
            emit("ADD");
            emit("LOAD");
        }
    | INT_CONST                               { emit("PUSH %d", $1); }
    | FLOAT_CONST
        {
            int scaled = (int)($1 * 1000);    /* 고정소수점 */
            emit("PUSH %d", scaled);
        }
    | '(' assignment_expr ')'                 /* 괄호식 */
    | IDENT '(' argument_expr_list_opt ')'    { emit("CALL %s", $1); }
    ;

argument_expr_list_opt
    : argument_expr_list
    | /* 공백 */
    ;

argument_expr_list
    : assignment_expr
    | argument_expr_list ',' assignment_expr
    ;

%%

/* ---------- 에러 처리 ---------- */
void yyerror(const char *s)
{
    fprintf(stderr, "구문 오류: %s (행 %d)\n", s, yylineno);
}

/* ---------- 진입점 ---------- */
int main(int argc, char **argv)
{
    printf("; ===== Stack Machine 코드 =====\n");
    yyparse();
    printf("HALT\n");
    return 0;
}
