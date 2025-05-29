%{
#include <string.h>
#include "cute.h"
#define MAXSYM	100
#define	MAXSYMLEN	20

#define STMTLIST 500

typedef struct nodeType {
	int token;
	int tokenval;
	struct nodeType *son;
	struct nodeType *brother;
} Node;

char symtbl[MAXSYM][MAXSYMLEN];
int lineno=1;
int insertsym(char *s);
int maxsym=0;
char s[MAXSYMLEN];
int temp;
Node * MakeNode(int, int);

%}
sp		[ \t]
ws		{sp}+
nl		\n
eletter	[A-Za-z]
letter	({eletter})
digit	[0-9]
id	{letter}({letter}|{digit})*
%%
{ws}	{/* do nothing */}
{nl}	{lineno++; }
\+|더하기|더할랭		{return(ADD); }
\-|빼기|뺄랭		{return(SUB); }
에		{return(ASSGN);}
을|를		{return(THIS);}
"*"|곱하기|곱할랭             {return(MUL);}
"/"|나누기|나눌랭             {return(DIV);}
고마웡		{return(STMTEND); }
요기부터           {return(LB);}
요기까지             {return(RB);}
하면서		{return(ING);}
만약에            {return(IF);}
가	{return(IS);}
보다	{return(THEN);}
와|과	{return(WA);}
저장할랭	{return(SAVE);}
실행할랭	{return(RUN);}
마지막에	{return(LAST);}
아니라면            {return(ELSE);}
함수이름은       {return(FUNC);}
이고	{return(AND);}
인 	{return(IN);}
선언할랭	{return(INIT);}
뭐가들었냐면	{return(CONTENT);}
함수	{return(FN);}
반복할랭	{return(LOOP);}
작다면         {return(LT);}
크다면         {return(GT);}
"의 값을"	{return(VAL);}
"작거나 같다면"      {return(LE);}
"크거나 같다면"      {return(GE);}
같다면      {return(EQ);}
"같지 않다면"      {return(NE);}
"+="	  {return(AA);}
"-="	  {return(SA);}
"*="	  {return(MA);}
"/="	  {return(DA);}
일단은	{return(FOR);}
"입력 받아줭"	{return(SCANF);}
:	{return(COLON);}
"++"	{return(INC);}
"--"	{return(DEC);}
호출할랭	{return(CALL);}
출력할랭	{return(PRINTF);}
이제	{return(NOW);}
"의 값을 서로 바꿔줭"	{return(SWAP);}
"일 경우엔"	{return(CASE);}
"빠져나가봥"	{return(BREAK);}
"다 아닌경우엔"	{return(DEFAULT);}
"여러 경우가 있엉"	{return(SWITCH);}
"시작할랭"	{return(START);}
"끝낼랭"	{return(END); }
func_{letter}+	{return(FNAME);}
{id}	{temp=insertsym(yytext); yylval=MakeNode(ID, temp); return(ID);}
-?{digit}+		{sscanf(yytext, "%d", &temp); yylval=MakeNode(NUM, temp); return(NUM);}
-?{digit}+\.{digit}+ {sscanf(yytext, "%f", &temp); yylval=MakeNode(REAL, temp); return(REAL);}
.		{printf("invalid token %s\n", yytext); }
%%

int insertsym(char *s)
{
int i;

	for(i=0;i<maxsym; i++) {
		if(strcmp(s, symtbl[i])==0) return(i);
		}
	if (i<MAXSYM-1) {
		strcpy(symtbl[maxsym],s);
		maxsym++;
		return(maxsym-1);
		}
	else
		{printf("symbol table overflow\n");}
	return(0);
}

yywrap() {}