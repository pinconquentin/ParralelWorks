#include "tab_fonction.h"


//  pour la table de fonction
int tf_find_cur(char* name){
	int j=0;
	for(j=0;j<10;j++){
	if(strcmp(tab_fon[j].name,name) == 0)
	return tab_fon[j].place_cur;		
	}
}

int tf_find_next(char* name){
	int j=0;
	for(j=0;j<10;j++){
	if(strcmp(tab_fon[j].name,name) == 0)
	return tab_fon[j].place_next;		
	}
}

int tf_find_place(char* name){
	int j=0;
	for(j=0;j<10;j++){
	if(strcmp(tab_fon[j].name,name) == 0)
	return j;		
	}
}

//  pour la place de chaque fonction

/*
void initQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
}

void DestoryQueue(LinkQueue &Q){
	while(Q.front){
	Q.rear = Q.front -> next;
	free(Q.front);
	Q.front = Q.rear;	
	}
}

void EnQueue(LinkQueue &Q,Q)

*/
