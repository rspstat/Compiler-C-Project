%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mini_c.h"

int line_no = 1;
%}

%option noyywrap

DIGIT    [0-9]
LETTER   [a-zA-Z_]
ID       {LETTER}({LETTER}|{DIGIT})*
NUMBER   {DIGIT}+
WHITESPACE [ \t]+

%%

"/*"([^*]|\*+[^*/])*\*+"/"   { /* multi-line comment */ }
"//".*                       { /* single-line comment */ }

"int"           { return INT; }
"void"          { return VOID; }
"char"          { return CHAR; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"do"            { return DO; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"return"        { return RETURN; }
"printf"        { return PRINTF; }
"scanf"         { return SCANF; }
"print"         { return PRINT; }

{ID}            { 
                  yylval.string = strdup(yytext); 
                  return IDENTIFIER; 
                }

{NUMBER}        { 
                  yylval.number = atoi(yytext); 
                  return NUMBER; 
                }

\"([^\"\\]|\\.)*\"  { 
                      yylval.string = strdup(yytext); 
                      return STRING; 
                    }

\'([^\'\\]|\\.)?\'  { 
                      yylval.number = yytext[1]; 
                      return NUMBER; 
                    }

"++"            { return INCREMENT; }
"--"            { return DECREMENT; }
"+="            { return PLUS_ASSIGN; }
"-="            { return MINUS_ASSIGN; }
"*="            { return MUL_ASSIGN; }
"/="            { return DIV_ASSIGN; }
"%="            { return MOD_ASSIGN; }

"<<"            { return LEFT_SHIFT; }
">>"            { return RIGHT_SHIFT; }
"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"&&"            { return AND; }
"||"            { return OR; }

"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"%"             { return '%'; }
"="             { return '='; }
"<"             { return '<'; }
">"             { return '>'; }
"!"             { return '!'; }
"?"             { return '?'; }
":"             { return ':'; }
"&"             { return '&'; }
"|"             { return '|'; }
"^"             { return '^'; }
"~"             { return '~'; }

"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
"["             { return '['; }
"]"             { return ']'; }
";"             { return ';'; }
","             { return ','; }

{WHITESPACE}    { /* ignore whitespace */ }

\n              { line_no++; }

.               { 
                  printf("Unexpected character: %c at line %d\n", yytext[0], line_no);
                  return yytext[0]; 
                }

%%