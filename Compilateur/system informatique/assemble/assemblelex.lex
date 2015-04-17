%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}


%%

"ADD" {return tADD;}
"MUL" {return tMUL ;}
"SOU" {return tSOU ;}
"DIV" {return tDIV ;}
"EQU" {return tEQU ;}
"COP" {return tCOP ;}
"AFC" {return tAFC ;}
"JMP" {return tJMP ;}
"JMF" {return tJMF ;}
"INF" {return tINF ;}
"SUP" {return tSUP ;}
"PRI" {return tPRI ;}
[0-9]+ {yylval.nb = atoi(yytext); return tNB;}

