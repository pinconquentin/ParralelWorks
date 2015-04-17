#include "tab_jump.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



tab_jmp* tj_initialize () {
	tab_jmp *tabjmp;
	tabjmp->indexjmp=0;
	int i;
	for (i=0;i<50;i++){
		tabjmp->tabdeb[i]=0;
		tabjmp->tabdest[i]=0;
	}

}


void tj_adddeb (int line) {
	// printf("tabdeb[%d]=%d après\n",tabjmp->indexjmp, tabjmp->tabdeb[tabjmp->indexjmp]);
	tabjmp->tabdeb[tabjmp->indexjmp]=line;
	// printf("tabdeb[%d]=%d après\n",tabjmp->indexjmp, tabjmp->tabdeb[tabjmp->indexjmp]);
	tabjmp->tabdest[tabjmp->indexjmp]=-1;
	tabjmp->indexjmp++;
}

void tj_adddest (int line, int whil) { //whil est à 1 si c'est un bloc while, ou il n'y a pas d'evenement particulier
	int i;
	int last=0;

// Ce bloc sert à determiner si on rempli la derniere case du tableau des jumps à ne pas etre initialisée. 
//Dans ce cas, on saute une ligne assembleur de moins, correpsondant au JMP dans les autres cas
		
	if (whil==0) { 
		if (tabjmp->indexjmp !=0){
			last=1;
		}
		for (i=tabjmp->indexjmp - 2;i>=0;i--){
			printf("dest : %d \n",tabjmp-> tabdest[i]);
			last = last && (tabjmp-> tabdest[i]!=-1);
		}
	}
	// if (last==1){
	// 		printf("lol\n");
	// 	}
	// else {
	// 	printf("not lol\n");
	// }

	for (i=tabjmp->indexjmp - 1;i>=0;i--){ 
		// printf("i=%d\n",i);
		if (tabjmp->tabdest[i]==-1){
			if (last == 1 ){
				printf("cas atteint\n");
				tabjmp->tabdest[i] = line;
				break;
			}
			tabjmp->tabdest[i] = line+1;
			break;
		}
	}
}

void tj_print (){ //marche pas
	int i;
	for (i=tabjmp->indexjmp-1;i>=0;i--){
		printf ("%d  %d\n",tabjmp->tabdeb[tabjmp->indexjmp-i],tabjmp->tabdest[tabjmp->indexjmp-i]);
	}
}