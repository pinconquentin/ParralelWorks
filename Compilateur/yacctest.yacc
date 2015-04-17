%{
#include <stdio.h>
#include "tab_symb.c"
#include "tab_jump.c"
%}

%union { int nb; char* id ;} 
%token LOWERTELSE
%token tFL, tAO, tAF, tPV, tRET, tV
%token tINT, tCONST
%token tMAIN, tIF, tELSE , tINF, tSUP, tWHILE , tFONCTION
%token tEGAL tSOU tADD 
%token tMUL tDIV 
%token tPO tPF 
%token <nb> tNB
%token <id> tID
%left tADD, tSOU
%left tMUL, tDIV
%type <nb> Expression
%type <nb> Comp 
%start Start

%%

Start		: tINT  Main ;

Main		: tMAIN tPO tPF Block_Fonc ;

Block		: tAO {nestlevel ++;}Instruction tAF {nestlevel -- ;} ;

Block_Fonc	: tAO {nestlevel ++;} Instruction Return tAF {nestlevel --;};

// Instructions : Instruction Block  ;

Instruction  : Declarations tPV Instruction
			 | Affectations tPV Instruction
			 | Ifelse
			 | While
			 | AppelFonc
			 |;


Declarations : Declaration
			 | Declaration tV Declarations ;

Affectations : Affectation
			 | Affectation Affectations ;

// a faire : int a, b, c
Declaration :  tINT tID {ts_create($2,0,0, nestlevel);} 
			|  tID {ts_create($1,0,0,nestlevel);} 
			|  tINT tID {ts_create($2,0,0,nestlevel) ;} tEGAL Expression {fprintf(fid,"COP %d, %d\n",ts_get_addr($2),$5);ts_init_var($2);ts_delete();count_line++;}
 			|  tCONST tINT tID {ts_create($3,0,1,nestlevel) ;} tEGAL Expression {fprintf(fid,"COP %d, %d\n",ts_get_addr($3),$6);ts_init_var($3);ts_delete();count_line++;};

Affectation : tID tEGAL Expression  {fprintf(fid,"COP %d, %d\n",  ts_get_addr($1),$3); ts_init_var($1); ts_delete();count_line++;}; 

Ifelse 		:  tIF tPO Condition  tPF ActionJMF Block ActionEndJMF Instruction %prec LOWERTELSE 
			|  tIF tPO Condition  tPF ActionJMF Block ActionEndJMF tELSE ActionJMP Block ActionEndJMP Instruction ;

While 		: tWHILE tPO {  linejmpwhile[indexwhile]=count_line; indexwhile++; } Condition tPF {fprintf(fid, "JMF %d,      \n",tab->sp-1); count_line++; tj_adddeb(count_line);}Block
				{tj_adddest(count_line,1); fprintf(fid, "JMP         \n"); count_line++; tj_adddeb(count_line); tj_adddest(linejmpwhile[indexwhile-1]-1,1) ; indexwhile--;} Instruction; 
 
ActionJMF 	: 	{fprintf(fid,"JMF %d,      \n",tab->sp-1);
				 count_line++;
				 tj_adddeb(count_line);  
				} ;

ActionEndJMF : {tj_adddest(count_line,0);};
				
ActionJMP 	: {fprintf(fid,"JMP          \n");
			   count_line++;
			   tj_adddeb(count_line);
			  };     

ActionEndJMP : {tj_adddest(count_line,0);};


AppelFonc	: tFONCTION ;

Condition	: Expression Comp Expression {switch ($2) {
														case 1 :fprintf(fid,"SUP %d, %d, %d\n",$1,$1,$3);
														count_line++;
														break;
														case 2 : fprintf(fid,"INF %d, %d, %d\n",$1,$1,$3);
														count_line++;
														break;
														default : fprintf(fid,"EQU %d, %d, %d\n",$1,$1,$3);
														count_line++;
													}
													ts_delete();}; 
 

Comp 		: tSUP {$$=1;}
			| tINF {$$=2 ;}
			| tEGAL tEGAL {$$=3;};


Expression	: Expression tADD Expression  	{fprintf(fid,"ADD %d, %d, %d\n",$1,$1,$3);
											ts_delete();
											count_line++;
											$$=$1;} 

			| Expression tSOU Expression  	{fprintf(fid,"SOU %d, %d, %d\n",$1,$1,$3);
											ts_delete();
											count_line++;
											$$=$1;} 

			| Expression tMUL Expression 	{fprintf(fid,"MUL %d, %d, %d\n",$1,$1,$3);
											ts_delete();
											count_line++;
											$$=$1;} 

			| Expression tDIV Expression 	{fprintf(fid,"DIV %d, %d, %d\n",$1,$1,$3);
											ts_delete();
											count_line++;
											$$=$1;} 

			| tPO Expression tPF			{$$=$2;}
 
			| tID 	{int a = ts_get_addr($1);
					int b = ts_create ("temp",1,0,nestlevel);
					fprintf(fid,"COP %d, %d\n",b,a);
					count_line++;
					$$=b;} 

			| tNB 	 {int a = ts_create("temp",1,0,nestlevel);
					fprintf(fid,"AFC %d,%d\n",a,$1);
					count_line++;
					$$ = a;};
  
Return 		: tRET tNB  tPV ;

%%

int main () {
	tab = ts_initialize();
	tabjmp = tj_initialize();
	fid = fopen("assembly.txt","w+");
	if (fid == NULL) {
		printf("Erreur\n");
	} 
	printf("Parsing...\n");
	yyparse();
	printf("Parsing Over ! \n");
	ts_print(tab); 
	free(tab->ts);  
	printf("Number of assembly lines : %d\n", count_line);
	// tj_print ();
	write_dest (fid);
	fclose(fid);
	return 0;
}

yyerror (char *s){
	fprintf(stderr, "%s\n",s);
}


void write_dest (FILE* fid) { //write the destination line of the jumps in the assembly file
	char buf[30];
	int i=0;
	int j=0;
	printf("Nombre de jumps :  = %d\n",tabjmp->indexjmp);	
	fseek (fid,0,SEEK_SET);
	for (i=tabjmp->indexjmp-1;i>=0;i--) {
		printf("JMPtabdeb[%d]=%d\n",i,tabjmp->tabdeb[i]);
		printf("JMPtabdest[%d]=%d\n",i,tabjmp->tabdest[i]);
		for (j=0;j<tabjmp->tabdeb[i]-1;j++){
			fgets(&buf[0], sizeof(buf), fid);
			//printf("Ligne lue : %s \n",buf);
		}
		if (fseek (fid, 7, SEEK_CUR)!=0){
			printf("Error 1st fseek\n");
		}
		printf("Number of caraters printed : %d\n",fprintf (fid, "%d", tabjmp->tabdest[i]+1));
		if (fseek (fid,0,SEEK_SET)!=0){
			printf("Error 2st fseek\n");	
		}
	}
}