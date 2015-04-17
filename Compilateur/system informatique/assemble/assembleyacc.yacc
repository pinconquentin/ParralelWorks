%{
#include <stdio.h>
#include <stdlib.h>

// definir des tokens
#define COP 1
#define AFC 2
#define JMP 3
#define JMF 4

#define ADD 5
#define SOU 6
#define MUL 7
#define DIV 8

#define INF 9
#define SUP 10
#define EQU 11

#define PRI 12

// declaration de matrice de memoire
int matrice[100][4];

// declaration de compteur de ligne
int cpt = 0;

// declaration une variable global
int i;

// predeclaration des fonctions
void print_matrice(int t);
void interpreteur(int t);
%}

%union { int nb; char* id ;} 
%token tADD tMUL tSOU tDIV tNB tEQU  tCOP tAFC tJMP tJMF tINF tSUP tEQU tPRI
%token <nb> tNB
%start Start

%%

Start	: Phrase
		| ;

Phrase	: 
	| tADD tNB tNB tNB {matrice[cpt][0]=ADD;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=$4;cpt++;} Phrase
	| tMUL tNB tNB tNB {matrice[cpt][0]=MUL;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=$4;cpt++;} Phrase
	| tSOU tNB tNB tNB {matrice[cpt][0]=SOU;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=$4;cpt++;} Phrase
	| tDIV tNB tNB tNB {matrice[cpt][0]=DIV;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=$4;cpt++;} Phrase
	| tCOP tNB tNB {matrice[cpt][0]=COP;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=-1;cpt++;} Phrase
	| tAFC tNB tNB {matrice[cpt][0]=AFC;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=-1;cpt++;} Phrase
	| tJMP tNB {matrice[cpt][0]=JMP;matrice[cpt][1]=$2;matrice[cpt][2]=-1;matrice[cpt][3]=-1;cpt++;} Phrase
	| tJMF tNB {matrice[cpt][0]=JMF;matrice[cpt][1]=$2;matrice[cpt][2]=-1;matrice[cpt][3]=-1;cpt++;} Phrase
	| tINF tNB tNB tNB {matrice[cpt][0]=INF;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=$4;cpt++;} Phrase
	| tSUP tNB tNB tNB {matrice[cpt][0]=SUP;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=$4;cpt++;} Phrase
	| tEQU tNB tNB tNB {matrice[cpt][0]=EQU;matrice[cpt][1]=$2;matrice[cpt][2]=$3;matrice[cpt][3]=$4;cpt++;} Phrase 
 	| tPRI tNB {matrice[cpt][0]=PRI;matrice[cpt][1]=$2;matrice[cpt][2]=-1;matrice[cpt][3]=-1;cpt++;} Phrase;

%%
 
int main () {
	yyparse();
	print_matrice(cpt);
	printf("\n\n***  interpreter  ***\n");
	interpreteur(cpt);
	return 0;
	}

yyerror (char *s){
	fprintf(stderr, "%s\n",s);
	}

void print_matrice(int t){
	for(i=0;i<t;i++){
	  printf("%d %d %d %d\n",matrice[i][0],matrice[i][1],matrice[i][2],matrice[i][3]);	
	}
}

void interpreteur(int t){
	for(i=0;i<t;i++){
	  switch(matrice[i][0]){
		case ADD:
			matrice[i][1]=matrice[i][2]+matrice[i][3];
			printf("ADD %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);
			break;
		case SOU:
			matrice[i][1]=matrice[i][2]-matrice[i][3];
			printf("SOU %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);
			break;
		case MUL:
			matrice[i][1]=matrice[i][2]*matrice[i][3];
			printf("MUL %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);
			break;
		case DIV:
			matrice[i][1]=matrice[i][2]/matrice[i][3];
			printf("DIV %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);			
			break;
		default:
			;
	  }		
	}
}

