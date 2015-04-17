#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char name[30]; 		//nom du symbole
	int initialized;	// symbole initialisé ou pas ?
	int constant ;		// variable constate ? 0 si non, 1 si oui	
	int nesting;		//niveau de profondeur de la variable
}symb;

typedef struct {
	symb * ts;
	int sp;
}tab_symb;

int count_line=0;
int JMPtabdeb[50]={0};
int JMPtabdest[50]={0};
int indexJMP=0;
int linejmpwhile[20]={0};
int indexwhile=0;
int nestlevel=0;
FILE* fid = NULL;

tab_symb* tab;



void write_dest (FILE* fid);
tab_symb* ts_initialize () ; // création du tableau de symboles
int ts_create (char *id, int initialized, int constant, int nesting); // ajout d'un élément dans la table
void ts_delete (); //détruit le dernier element du tableau
void ts_init_var(char *id); // initialise une variable déclarée dans la table
int ts_get_addr(char *id); // retourne l'adresse dans la table de l'id spécifiée
void ts_print (); // affiche le contenu du tableau