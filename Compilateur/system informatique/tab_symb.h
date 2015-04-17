#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char name[30]; 		//nom du symbole
	int initialized;	// symbole initialisé ou pas ?
	// int tempo ;			// symbole temporaire ou bien ?!
}symb;

typedef struct {
	symb * ts;
	int sp;
}tab_symb;


tab_symb* tab;

tab_symb* ts_initialize () ; // création du tableau de symboles
int ts_create (char *id, int initialized); // ajout d'un élément dans la table
void ts_delete (); //détruit le dernier element du tableau
void ts_init_var(char *id); // initialise une variable déclarée dans la table
int ts_get_addr(char *id); // retourne l'adresse dans la table de l'id spécifiée
void ts_print ();