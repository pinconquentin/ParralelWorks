#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "yacctab.yacc"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tab_symb.c"
#include "tab_fonction.c"
	
int table[2][100];

/*compte ligne*/
int cpt=0;
int cpt_fonc=0;
/*file*/
FILE* fid;

void print_jmp_table();
void write_dest (FILE* fid);
void print_tab_fonction();
#line 21 "yacctab.yacc"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char* id ;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define LOWERTELSE 257
#define LOWERTDECL 258
#define tFL 259
#define tCO 260
#define tCF 261
#define tPV 262
#define tRET 263
#define tINT 264
#define tMAIN 265
#define tIF 266
#define tELSE 267
#define tINF 268
#define tSUP 269
#define tEGAL 270
#define tSOU 271
#define tADD 272
#define tMUL 273
#define tDIV 274
#define tPO 275
#define tPF 276
#define tNB 277
#define tID 278
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    6,    8,    3,    7,    7,    9,   11,    5,    5,
    4,   10,   10,   10,   10,   10,   10,   17,   12,   18,
   19,   12,   14,   14,   21,   22,   20,    2,    2,    2,
   23,   13,    1,    1,    1,    1,    1,    1,    1,   24,
   15,   16,   16,
};
static const short yylen[] = {                            2,
    3,    0,    0,    8,    1,    1,    0,    0,   10,    0,
    6,    1,    1,    1,    1,    1,    0,    0,    5,    0,
    0,    8,   10,   14,    0,    0,    3,    1,    1,    2,
    0,    6,    3,    3,    3,    3,    3,    1,    1,    0,
    6,    3,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    2,    0,    0,    0,    0,    0,    3,    0,    0,    0,
    0,    0,   12,   13,   14,   15,   16,    7,    0,    0,
    0,    0,    0,    0,    0,   11,    0,    0,    5,    4,
   42,   43,   18,    0,    0,   39,   38,    0,    0,    0,
   40,    0,    0,    0,    0,   29,   28,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   19,    0,   37,
   30,    0,    0,   35,   36,    0,   25,    0,    0,    8,
    0,    0,   32,   41,    0,    0,    0,    9,   22,   26,
    0,    0,   23,    0,    0,    0,   24,
};
static const short yydgoto[] = {                          2,
   48,   63,    3,    6,   10,   14,   40,   29,   37,   22,
   85,   23,   24,   25,   26,   27,   53,   44,   81,   49,
   82,   91,   65,   66,
};
static const short yysindex[] = {                      -249,
 -253,    0, -233, -242, -234, -221, -225, -224, -223,    0,
    0, -207, -213, -208, -256, -211,    0, -259, -215, -209,
 -266, -189,    0,    0,    0,    0,    0,    0, -191, -188,
 -179, -178, -254, -254, -190,    0, -175, -253,    0,    0,
    0,    0,    0, -183, -254,    0,    0, -192, -187, -236,
    0, -256, -256, -254, -260,    0,    0, -182, -254, -254,
 -254, -254, -254, -170, -171, -169, -167,    0, -236,    0,
    0, -245, -245,    0,    0, -236,    0, -256, -256,    0,
 -166, -256,    0,    0, -221, -256, -164,    0,    0,    0,
 -261, -168,    0, -256, -163, -256,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,   95,    0,    0,    0,    0,
    0,    0,    0,    0, -162,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -165,    0,    0,    0,    0,    0, -161,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -160,
    0, -162, -162,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -159,    0,
    0, -212, -201,    0,    0, -176,    0, -162, -162,    0,
    0, -162,    0,    0,   95, -162,    0,    0,    0,    0,
 -162,    0,    0, -162,    0, -162,    0,
};
static const short yygindex[] = {                         0,
  -14,    0,   72,    0,   21,    0,    0,    0,    0,  -52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 106
static const short yytable[] = {                         67,
   68,   18,   19,   34,   20,   92,   18,   19,   35,   20,
   59,   60,   61,   62,    1,   70,   21,   30,   31,   50,
   45,   21,   46,   47,    4,   83,   84,   61,   62,   87,
   55,    5,    7,   89,   59,   60,   61,   62,   93,   69,
    8,   95,    9,   97,   72,   73,   74,   75,   76,   34,
   11,   12,   15,   17,   13,   34,   34,   34,   34,   34,
   33,   16,   32,   34,   28,   33,   33,   33,   33,   33,
   33,   36,   38,   41,   33,   56,   57,   58,   59,   60,
   61,   62,   42,   43,   52,   51,   54,   71,   64,   77,
   78,   94,   79,   80,   10,   86,   90,   96,   17,   27,
   39,   31,   21,    6,   20,   88,
};
static const short yycheck[] = {                         52,
   53,  263,  264,  270,  266,  267,  263,  264,  275,  266,
  271,  272,  273,  274,  264,  276,  278,  277,  278,   34,
  275,  278,  277,  278,  278,   78,   79,  273,  274,   82,
   45,  265,  275,   86,  271,  272,  273,  274,   91,   54,
  275,   94,  264,   96,   59,   60,   61,   62,   63,  262,
  276,  276,  260,  262,  278,  268,  269,  270,  271,  272,
  262,  275,  278,  276,  276,  275,  268,  269,  270,  271,
  272,  261,  264,  262,  276,  268,  269,  270,  271,  272,
  273,  274,  262,  262,  260,  276,  270,  270,  276,  260,
  262,  260,  262,  261,    0,  262,  261,  261,  261,  276,
   29,  262,  262,  265,  270,   85,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LOWERTELSE","LOWERTDECL","tFL",
"tCO","tCF","tPV","tRET","tINT","tMAIN","tIF","tELSE","tINF","tSUP","tEGAL",
"tSOU","tADD","tMUL","tDIV","tPO","tPF","tNB","tID",
};
static const char *yyrule[] = {
"$accept : Start",
"Start : DeclaFonc Main Fonction",
"$$1 :",
"$$2 :",
"DeclaFonc : tINT tID tPO tPF $$1 tPV $$2 Suite",
"Suite : DeclaFonc",
"Suite : tINT",
"$$3 :",
"$$4 :",
"Fonction : tINT tID tPO tPF $$3 tCO Core tCF $$4 Fonction",
"Fonction :",
"Main : tMAIN tPO tPF tCO Core tCF",
"Core : Declaration",
"Core : Affectation",
"Core : Ifelse",
"Core : Call",
"Core : Return",
"Core :",
"$$5 :",
"Declaration : tINT tID tPV $$5 Core",
"$$6 :",
"$$7 :",
"Declaration : tINT tID $$6 tEGAL Expression $$7 tPV Core",
"Ifelse : tIF tPO Condition tPF tCO ActionJMF Core tCF ActionFJMF Core",
"Ifelse : tIF tPO Condition tPF tCO ActionJMF Core tCF ActionFJMF tELSE tCO Core tCF Core",
"ActionJMF :",
"ActionFJMF :",
"Condition : Expression Comp Expression",
"Comp : tSUP",
"Comp : tINF",
"Comp : tEGAL tEGAL",
"$$8 :",
"Affectation : tID tEGAL Expression $$8 tPV Core",
"Expression : Expression tADD Expression",
"Expression : Expression tSOU Expression",
"Expression : Expression tMUL Expression",
"Expression : Expression tDIV Expression",
"Expression : tPO Expression tPF",
"Expression : tID",
"Expression : tNB",
"$$9 :",
"Call : tID tPO tPF $$9 tPV Core",
"Return : tRET tNB tPV",
"Return : tRET tID tPV",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 142 "yacctab.yacc"

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
#line 352 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 42 "yacctab.yacc"
	{
				strcpy(tab_fon[cpt_fonc].name,yystack.l_mark[-2].id);
				cpt_fonc++;
				}
break;
case 3:
#line 45 "yacctab.yacc"
	{printf("pro\n");}
break;
case 7:
#line 50 "yacctab.yacc"
	{printf("debut de fonction\n");
				cpt_fonc=tf_find_place(yystack.l_mark[-2].id);
				tab_fon[cpt_fonc].place_next = cpt+1;
				printf("fin de fonction\n");			
				}
break;
case 8:
#line 55 "yacctab.yacc"
	{ cpt++;
						fprintf(fid,"JMP %d\n",tab_fon[cpt_fonc].place_cur+1);}
break;
case 18:
#line 69 "yacctab.yacc"
	{int a=ts_create(yystack.l_mark[-1].id,0) ;
								/* printf("declaration : ajout de la variable %s à la table des symboles à l'adresse %d\n", $2,a)*/
								;}
break;
case 20:
#line 72 "yacctab.yacc"
	{int a=ts_create(yystack.l_mark[0].id,0) ;}
break;
case 21:
#line 72 "yacctab.yacc"
	{cpt++;fprintf(fid,"COP %d %d\n",ts_get_addr(yystack.l_mark[-3].id),yystack.l_mark[0].nb);
																	 ts_init_var(yystack.l_mark[-3].id);
																	 ts_delete();}
break;
case 25:
#line 80 "yacctab.yacc"
	{	cpt++;
			fprintf(fid,"JMF \n");
					
			}
break;
case 26:
#line 84 "yacctab.yacc"
	{	
						
			}
break;
case 28:
#line 91 "yacctab.yacc"
	{yyval.nb=1;}
break;
case 29:
#line 92 "yacctab.yacc"
	{yyval.nb=2;}
break;
case 30:
#line 93 "yacctab.yacc"
	{yyval.nb=3;}
break;
case 31:
#line 96 "yacctab.yacc"
	{cpt++;fprintf(fid,"COP %d %d\n",ts_get_addr(yystack.l_mark[-2].id),yystack.l_mark[0].nb);
									 ts_init_var(yystack.l_mark[-2].id);
									 ts_delete();}
break;
case 33:
#line 102 "yacctab.yacc"
	{cpt++;fprintf(fid,"ADD %d %d %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											ts_delete();
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 34:
#line 106 "yacctab.yacc"
	{cpt++;fprintf(fid,"SOU %d %d %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											ts_delete();
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 35:
#line 110 "yacctab.yacc"
	{cpt++;fprintf(fid,"MUL %d %d %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											ts_delete();
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 36:
#line 114 "yacctab.yacc"
	{cpt++;fprintf(fid,"DIV %d %d %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											/* ts_print();*/
											ts_delete();
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 37:
#line 119 "yacctab.yacc"
	{yyval.nb=yystack.l_mark[-1].nb;}
break;
case 38:
#line 121 "yacctab.yacc"
	{/*printf("Chercher dans la table des symboles l'ID (%s) et faire remonter son adresse\n",$1);*/
				   	int a = ts_get_addr(yystack.l_mark[0].id);
					int b = ts_create ("temp",1);
					cpt++;
					fprintf(fid,"COP %d %d\n",b,a);
					yyval.nb = b;}
break;
case 39:
#line 128 "yacctab.yacc"
	{int a = ts_create("temp",1);
					cpt++;
					fprintf(fid,"AFC %d %d\n",a,yystack.l_mark[0].nb);
					yyval.nb = a;}
break;
case 40:
#line 133 "yacctab.yacc"
	{cpt_fonc = tf_find_place(yystack.l_mark[-2].id); 
			     cpt++;
			     fprintf(fid,"JMP    \n");
			     tab_fon[cpt_fonc].place_cur=cpt;}
break;
#line 681 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
