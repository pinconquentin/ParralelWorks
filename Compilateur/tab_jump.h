#include <stdio.h>
#include <stdlib.h>



typedef struct {
	int tabdeb[50];
	int tabdest[50];
	int indexjmp;
}tab_jmp;


tab_jmp* tabjmp;


tab_jmp* tj_initialize ();
void tj_adddeb (int line);	
void tj_adddest (int line, int whil);
void tj_print ();