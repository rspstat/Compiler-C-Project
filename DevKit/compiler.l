%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

int line_num = 1;
%}

DIGIT    [0-9]
LETTER   [a-zA-Z가-힣]
ID       ({LETTER}|_)({LETTER}|{DIGIT}|_)*
INTEGER  {DIGIT}+
FLOAT    {DIGIT}+\.{DIGIT}+

%%

"main"          { return MAIN; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"int"           { return INT; }
"float"         { return FLOAT_TYPE; }
"return"        { return RETURN; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"function"      { return FUNCTION; }
"void"          { return VOID; }

"=="            { return EQ; }
"!="            { return NE; }
"<="            { return LE; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
"++"            { return INC; }
"--"            { return DEC; }
"+="            { return PLUS_ASSIGN; }
"-="            { return MINUS_ASSIGN; }

{INTEGER}       { yylval.ival = atoi(yytext); return INTEGER; }
{FLOAT}         { yylval.fval = atof(yytext); return FLOAT; }
{ID}            { yylval.sval = strdup(yytext); return ID; }

"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"%"             { return '%'; }
"="             { return '='; }
"<"             { return '<'; }
">"             { return '>'; }
"!"             { return '!'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
"["             { return '['; }
"]"             { return ']'; }
";"             { return ';'; }
","             { return ','; }

[ \t]+          { }
\n              { line_num++; }
.               { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}