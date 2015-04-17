%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}



%%
"int" {return tINT;}
"main" {return tMAIN; }
"if" { return tIF ;}
"else" {return tELSE ;}
"return" {return tRET;}

[0-9]+ { yylval.nb = atoi(yytext);
		return tNB;}

[a-z]+ {yylval.id = strdup(yytext);
		return tID ;}
"=" { return tEGAL ; }
"-" { return tSOU ; }
"+" { return tADD ; }
"*" { return tMUL ; }
"<" { return tINF ;}
">" {return tSUP ;}
"/" { return tDIV ; }
"(" { return tPO ; }
")" { return tPF ; }
\n { /*cpt_line*/ }
"{" {return tCO ;}
"}" {return tCF;}
";" {return tPV;}
" " {}






