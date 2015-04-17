%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tab_symb.c"
#include "tab_fonction.c"
	
int table[2][100];

//compte ligne
int cpt=0;
int cpt_fonc=0;
//file
FILE* fid;

void print_jmp_table();
void write_dest (FILE* fid);
void print_tab_fonction();
%}

%union { int nb; char* id ;} 
%token LOWERTELSE
%token LOWERTDECL
%token tFL tCO tCF tPV tRET
%token tINT 
%token tMAIN, tIF, tELSE , tINF, tSUP
%token tEGAL tSOU tADD 
%token tMUL tDIV 
%token tPO tPF 
%token <nb> tNB
%token <id> tID 
%left tADD, tSOU, 
%left tMUL, tDIV
%type <nb> Expression Comp
%start Start

%%

Start		: DeclaFonc Main Fonction;


DeclaFonc	: tINT tID tPO tPF {
				strcpy(tab_fon[cpt_fonc].name,$2);
				cpt_fonc++;
				} tPV {printf("pro\n");} Suite;

Suite		: DeclaFonc ;


Fonction	: tINT tID tPO tPF  {printf("debut de fonction\n");
				cpt_fonc=tf_find_place($2);
				tab_fon[cpt_fonc].place_next = cpt+1;
				printf("fin de fonction\n");			
				}
				 tCO Core tCF { cpt++;
						fprintf(fid,"JMP %d\n",tab_fon[cpt_fonc].place_cur+1);} Fonction
		|;

Main		:  tINT tMAIN tPO tPF tCO Core tCF ;


Core		: Declaration // A FAIRE : creer un non terminal instrutions qui peut se boucler lui meme, mais pas que Core se boucle sur lui meme pour éviter les boucles infinies
			| Affectation
			| Ifelse
			| Call
			| Return
			|;  

Declaration :  tINT tID tPV 	{int a=ts_create($2,0) ;
								// printf("declaration : ajout de la variable %s à la table des symboles à l'adresse %d\n", $2,a)
								;} Core
			|  tINT tID {int a=ts_create($2,0) ;} tEGAL Expression {cpt++;fprintf(fid,"COP %d %d\n",ts_get_addr($2),$5);
																	 ts_init_var($2);
																	 ts_delete();}				
																	 tPV   Core ;
 
Ifelse 		:  tIF  tPO Condition tPF tCO  ActionJMF Core  tCF ActionFJMF Core %prec LOWERTELSE 
			|  tIF tPO Condition  tPF tCO ActionJMF Core tCF ActionFJMF tELSE tCO  Core tCF  Core ;

ActionJMF	: {	cpt++;
			fprintf(fid,"JMF \n");
					
			}
ActionFJMF	: {	
						
			}


Condition	: Expression Comp Expression 

Comp 		: tSUP {$$=1;}
		| tINF {$$=2;}
		| tEGAL tEGAL {$$=3;} ;


Affectation : tID tEGAL Expression  {cpt++;fprintf(fid,"COP %d %d\n",ts_get_addr($1),$3);
									 ts_init_var($1);
									 ts_delete();} 
									 tPV  Core ; //check si tempo ou non, si oui dépiler


Expression	: Expression tADD Expression  	{cpt++;fprintf(fid,"ADD %d %d %d\n",$1,$1,$3);
											ts_delete();
											$$=$1;} 

			| Expression tSOU Expression  	{cpt++;fprintf(fid,"SOU %d %d %d\n",$1,$1,$3);
											ts_delete();
											$$=$1;} 

			| Expression tMUL Expression 	{cpt++;fprintf(fid,"MUL %d %d %d\n",$1,$1,$3);
											ts_delete();
											$$=$1;} 

			| Expression tDIV Expression 	{cpt++;fprintf(fid,"DIV %d %d %d\n",$1,$1,$3);
											// ts_print();
											ts_delete();
											$$=$1;} 

			| tPO Expression tPF			{$$=$2;}
 
			| tID 	{//printf("Chercher dans la table des symboles l'ID (%s) et faire remonter son adresse\n",$1);
				   	int a = ts_get_addr($1);
					int b = ts_create ("temp",1);
					cpt++;
					fprintf(fid,"COP %d %d\n",b,a);
					$$ = b;} 

			| tNB 	 {int a = ts_create("temp",1);
					cpt++;
					fprintf(fid,"AFC %d %d\n",a,$1);
					$$ = a;}

Call		: tID tPO tPF {cpt_fonc = tf_find_place($1); 
			     cpt++;
			     fprintf(fid,"JMP    \n");
			     tab_fon[cpt_fonc].place_cur=cpt;}; tPV Core 

  
Return 		:  tRET tNB  tPV 
		|tRET tID tPV;

%%
int main () {
	fid = fopen("assembly.txt","w+");
	printf("debut de compilateur\n");
	tab = ts_initialize();
	yyparse();
	write_dest (fid);
	fclose(fid);
	print_tab_fonction();
	ts_print(tab);
	//free(tab->ts);
	return 0;
}

yyerror (char *s){
	fprintf(stderr, "%s\n",s);
	}

void write_dest (FILE* fid) { //write the destination line of the jumps in the assembly file
	char buf[30];
	int i=0;
	int j=0;
	int tmp;
	//printf("Nombre de jumps :  = %d\n",cpt_fonc);	

		
	fseek (fid,0,SEEK_SET);

	for (i=0;i<10;i++) {
		if(tab_fon[i].name[0] == '\0'){
		//	printf("do break\n");
			break;
		}
		for (j=0;j<tab_fon[i].place_cur-1;j++){
			fgets(&buf[0], sizeof(buf), fid);
		//	printf("Ligne lue : %s \n",buf);
		}
		if (fseek (fid, 4, SEEK_CUR)!=0){
			printf("Error 1st fseek\n");
		}
		tmp = tab_fon[i].place_next;	
		//if(tmp>0 && tmp<10)
		fprintf (fid,"%d",tmp);
		
		if (fseek (fid,0,SEEK_SET)!=0){
			printf("Error 2st fseek\n");	
		}
	}
}


void print_tab_fonction(){
	int i;	
	for (i=0;i<10;i++) {
		if(tab_fon[i].name[0] == '\0'){
		  printf("%s  cur:%d  next:%d",tab_fon[i].name,tab_fon[i].place_cur,tab_fon[i].place_next);
		}
		else
			break;
	}
}
