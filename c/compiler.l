/* compiler.l - Flex 스캐너 */
/* 모든 주석은 한글 */

%option noyywrap
%option nounput
%option noinput

%{
#include "y.tab.h"
#include <stdlib.h>
#include <string.h>

/* 현재 행 번호 추적 */
int yylineno = 1;
%}

/* ---------- 정규식 정의 ---------- */
DIGIT        [0-9]
LETTER       [a-zA-Z_]
IDENT        {LETTER}({LETTER}|{DIGIT})*
INTCONST     {DIGIT}+
REALCONST    {DIGIT}+\.{DIGIT}+([eE][+-]?{DIGIT}+)?
STRLIT       \"([^\"\\\n]|\\.)*\"
CHARLIT      \'([^\'\\\n]|\\.)\'

%%

[ \t\r]+                       /* 공백 무시 */
\n              { ++yylineno; }/* 줄 개행 */

"//".*                         /* 한 줄 주석 */
"/*"([^*]|\*+[^*/])*\*+ "/"    /* 블록 주석 */

/* ---------- 키워드 ---------- */
"int"        { return K_INT; }
"float"      { return K_FLOAT; }
"char"       { return K_CHAR; }
"void"       { return K_VOID; }

"if"         { return IF; }
"else"       { return ELSE; }
"while"      { return WHILE; }
"for"        { return FOR; }
"do"         { return DO; }
"break"      { return BREAK; }
"continue"   { return CONTINUE; }
"return"     { return RETURN; }

"switch"     { return SWITCH; }
"case"       { return CASE; }
"default"    { return DEFAULT; }

"print"      { return PRINT; }
"read"       { return READ; }

/* ---------- 다중문자 연산자 ---------- */
"++"         { return INC_OP; }
"--"         { return DEC_OP; }

"+="         { return ADDEQ; }
"-="         { return SUBEQ; }
"*="         { return MULEQ; }
"/="         { return DIVEQ; }
"%="         { return MODEQ; }

"=="         { return EQ_OP; }
"!="         { return NE_OP; }
"<="         { return LE_OP; }
">="         { return GE_OP; }
"&&"         { return AND_OP; }
"||"         { return OR_OP; }

"<<"         { return LSHIFT; }
">>"         { return RSHIFT; }

"->"         { return ARROW; }

/* ---------- 리터럴 ---------- */
{REALCONST}  { yylval.fval = atof(yytext);   return FLOAT_CONST; }
{INTCONST}   { yylval.ival = atoi(yytext);   return INT_CONST; }
{CHARLIT}    { yylval.ival = yytext[1];      return CHAR_CONST; }
{STRLIT}     {
                int len = yyleng - 2;        /* 양쪽 따옴표 제거 */
                char *buf = (char*)malloc(len + 1);
                memcpy(buf, yytext + 1, len);
                buf[len] = '\0';
                yylval.sval = buf;
                return STRING;
             }

/* 식별자 */
{IDENT}      { yylval.id = strdup(yytext);  return IDENT; }

/* ---------- 단일문자 기호 ---------- */
"(" | ")" |
"{" | "}" |
"[" | "]" |
";" | "," |
"+" | "-" | "*" | "/" | "%" |
"<" | ">" | "=" | "!" |
"&" | "|" | "^" | "~" |
"?" | ":" | "."   { return yytext[0]; }

/* 그 밖의 알 수 없는 문자 */
.            { fprintf(stderr,"알 수 없는 문자 '%c' (행 %d)\n", yytext[0], yylineno); }

%%

/* flex에서 필요 시 호출 */
int yywrap(void) { return 1; }
