%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SYMAXSIZE 100
#define LEXSIZE 999

int cpt=1;

int last_symbole=0;
int last_lex_position=0;
char lex[LEXSIZE];

typedef struct{
char* lexptr;
int token;
}symbole;

symbole elem[SYMAXSIZE];

int lookup(char* s)
{
int i;
for(i=last_symbole;i>0;i--){
if(strcmp(elem[i].lexptr,s)==0)
return i;
}
return 0;
}

int insert(char *s, int tok)
{
int len;
len = strlen(s);
if(last_symbole+1>SYMAXSIZE)
	{
		printf("error:table symbole is full\n");
		return 0;
	}

if(last_lex_position+len+1>LEXSIZE)
	{
		printf("error:table lex is full\n");
		return 0;
	}
last_symbole = last_symbole+1;
elem[last_symbole].token = tok;
elem[last_symbole].lexptr = &lex[last_lex_position+1];
last_lex_position = last_lex_position+len+1;
strcpy(elem[last_symbole].lexptr,s);
return last_symbole;
}


%}

%union {int nb; char *var;}
%token LOWERTELSE
%token tINT tMAIN tINC tDEF tHEAD
%token tIF tELSE
%token <nb> tNB
%token <var> tID
%token tEGAL tSOU tADD tMUL tDIV tSUP tINF
%token tPO tPF tFL tCO tCF tPV tRET tVI tJIN
%start Start

%%

Start		: tINT Main ;

Main		: tMAIN tPO tPF tCO Core tCF ;

Core		: Declaration 
			| Affectation
			| Return 
			| Stmt
			|;

Stmt		: tIF tPO Expression  tPF tCO Core tCF tELSE tCO Core tCF
			|tIF tPO Expression  tPF tCO Core tCF %prec LOWERTELSE; 
			

Expression	: tID tINF tID
			| tID tSUP tID
			| tNB;
			
Declaration :  tINT tID tPV {if(lookup($2));else{insert((char*)$2,cpt++);}} Core
			|  tINT Affectation {printf("declar+affec\n");};


/*Expression	: tID tEGAL Calcul Core*/

Calcul		: Calcul Addop Terme|Terme;  
	
Terme 		:Terme Mulop factor|factor;

factor		:tPO Calcul tPF
			|tNB
			tID;

Addop		:tADD
			|tSOU;

Mulop		:tMUL
			|tDIV;

Affectation : tID tEGAL  Calcul tPV Core;

Return 		: tRET   tPV {printf("success\n");};



%%
main () {
	int ex=0;
	yyparse();
	printf("debut de table de symbole\n");
	for(ex=0;ex<SYMAXSIZE;ex++)
	{
	printf("---%s---%d\n",elem[ex].lexptr,elem[ex].token);
	}
	return 0;
}

yyerror (char *s){
	fprintf(stderr, "%s\n",s);
}
