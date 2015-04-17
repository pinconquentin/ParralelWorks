%{
#include <stdio.h>
#include "tab_symb.c"
%}

%union { int nb; char* id ;}
%token tINT tMAIN tNB tID 
%token tEGAL tSOU tADD tMUL tDIV 
%token tPO tPF tFL tCO tCF tPV tRET

%start Start

%%

Start		: tINT Main ;

Main		: tMAIN tPO tPF tCO Core tCF ;

Core		: Declaration 
			| Affectation
			| Return ;

Declaration :  tINT tID tPV {printf("declaration : ajouter la variable $2 (%s) à la table des symboles\n", $2);} Core
			|  tINT tID tEGAL C {printf("créer tID (%s) dans la table des symboles avec la valeur contenue dans l'adresse de C \n", $2);} tPV Core ;


/*Expression	: tID tEGAL Calcul Core*/

Affectation : tID tEGAL C  {printf("Affecter tID (%s) dans la table des symboles avec la valeur contenue dans l'adresse de C \n", $1);} tPV  Core ; //check si tempo ou non, si oui dépiler


C			: C tADD C {printf("addition ADD en ASM et mettre le resultat dans le 1er symbole, supprimer le deuxième symbole et faire remonter l'adresse du result\n");}
			// | tPO C tADD C tPF {printf("addition parenthèses\n");}
			| C tSOU C {printf("soustraction\n");}
			// | tPO C tSOU C tPF {printf("soustraction parenthèses\n");}
			| C tMUL C {printf("multiplication\n");}
			// | tPO C tMUL C tPF {printf("multiplication parenthèses\n");}
			| C tDIV C {printf("division\n");}
			// | tPO C tDIV C tPF {printf("division parenthèses\n");}
			| tPO C tPF
			| tID {printf("Chercher dans la table des symboles l'ID (%s) et faire remonter son adresse\n",$1);}
			| tNB {printf("Créer une variable temporaire dans la table des symboles et faire remonter l'adresse de la valeur %d\n", $1);}

Return 		: tRET tNB  tPV ;

%%
main () {
	tab_symb* tab=ts_initialize();
	yyparse();
	return 0;
}

yyerror (char *s){
	fprintf(stderr, "%s\n",s);
}
