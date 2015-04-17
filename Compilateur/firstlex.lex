


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
"while" {return tWHILE ;}
"const" {return tCONST ;}
[0-9]+ { yylval.nb = atoi(yytext);
		return tNB;}

[a-z]+'('*')' {yylval.id = strdup(yytext);
		return tFONCTION ;}

[a-z]+ {yylval.id = strdup(yytext);
		return tID ;}

"," {return tV;}
"=" { return tEGAL ; }
"-" { return tSOU ; }
"+" { return tADD ; }
"*" { return tMUL ; }
"<" { return tINF;}
">" {return tSUP;}
"/" { return tDIV ; }
"(" { return tPO ; }
")" { return tPF ; }
\n { /*cpt_line*/ }
"{" {return tAO ;}
"}" {return tAF;}
";" {return tPV;}
" " {}






