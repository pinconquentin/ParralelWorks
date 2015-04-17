#include <stdio.h>
#include <stdlib.h>
#include "tab_symb.h"
#include <string.h>
#define SIZE_TS 200


tab_symb* ts_initialize () { // création du tableau de symboles
	tab_symb *tab;
	tab -> sp = 0;
	tab->ts =  (symb*) malloc (sizeof(symb)*SIZE_TS);
	return tab;
}



int ts_create (char *id, int init) { // ajout d'un élément dans la table
	strcpy((tab->ts[tab->sp]).name, id);/*a ajouter : check d'abord si variable pas présente dans la table*/
	(tab->ts[tab->sp]).initialized=init;
	(tab->sp)++;
	// printf("sp = %d\n",(tab->sp)-1);
	return ((tab->sp)-1);
}
void ts_delete () {//détruit le dernier element du tableau
	(tab->ts[tab->sp]).name[0]='\0';
	(tab->ts[tab->sp]).initialized=0;
	(tab->sp)--;
}

void ts_init_var(char *id){ // initialise une variable déclarée dans la table
	int i;
	int found=0;
	for (i=0;i<=(tab->sp);i++){
		if(strcmp(id,(tab->ts[i]).name)==0){
			found=1;
			(tab->ts[i]).initialized=1;
			break;
		}
	}
	if (found==0){
		// printf("ID %s found at index %d and initialized\n", id,found);
		printf("Error finding %s : maybe not in the table ?\n",id);
	}
}


int ts_get_addr(char *id){ // retourne l'adresse dans la table de l'id spécifiée
	int i;
	int addr=0;
	for (i=0;i<(tab->sp);i++){
		if(strcmp(id,(tab->ts[i]).name)==0){
			addr=i;
			return addr;
		}
	}
	printf("Error : %s undeclared\n",id);

}

void ts_print (){
	int i;
	for (i=0;i<(tab->sp);i++){
		printf("Variable à adresse %d: %s\n",i,tab->ts[i].name);
		}
	// printf("test\n");
}
