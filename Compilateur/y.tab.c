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

#line 1 "yacctest.yacc"

#include <stdio.h>
#include "tab_symb.c"
#include "tab_jump.c"
#line 7 "yacctest.yacc"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char* id ;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 33 "y.tab.c"

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
#define tFL 258
#define tAO 259
#define tAF 260
#define tPV 261
#define tRET 262
#define tV 263
#define tINT 264
#define tCONST 265
#define tMAIN 266
#define tIF 267
#define tELSE 268
#define tINF 269
#define tSUP 270
#define tWHILE 271
#define tFONCTION 272
#define tEGAL 273
#define tSOU 274
#define tADD 275
#define tMUL 276
#define tDIV 277
#define tPO 278
#define tPF 279
#define tNB 280
#define tID 281
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    3,    7,    5,    8,    4,    6,    6,    6,    6,
    6,    6,   10,   10,   11,   11,   15,   15,   17,   15,
   18,   15,   16,   12,   12,   24,   25,   26,   13,   20,
   21,   22,   23,   14,   19,    2,    2,    2,    1,    1,
    1,    1,    1,    1,    1,    9,
};
static const short yylen[] = {                            2,
    2,    4,    0,    4,    0,    5,    3,    3,    1,    1,
    1,    0,    1,    3,    1,    2,    2,    1,    0,    5,
    0,    6,    3,    8,   12,    0,    0,    0,    9,    0,
    0,    0,    0,    1,    3,    1,    1,    2,    3,    3,
    3,    3,    3,    1,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    1,    0,    0,    5,    2,    0,    0,
    0,    0,    0,   34,    0,    0,    0,    0,    9,   10,
   11,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,    0,    0,    0,   16,    0,   21,    0,   45,   44,
    0,    0,    0,    0,    0,    6,    7,    8,   18,   14,
    0,    0,    0,   37,   36,    0,    0,    0,    0,    0,
    0,   30,    0,   46,    0,    0,   43,   38,    0,    0,
   41,   42,    0,    0,   27,    0,    3,   31,    0,    0,
    0,   28,    0,   32,   24,    0,    4,    0,   29,   33,
    0,   25,
};
static const short yydgoto[] = {                          2,
   41,   61,    4,    8,   78,   16,   80,    9,   30,   17,
   18,   19,   20,   21,   22,   23,   36,   52,   42,   74,
   81,   88,   91,   43,   79,   86,
};
static const short yysindex[] = {                      -254,
 -253,    0, -261,    0, -257, -196,    0,    0, -192, -244,
 -194, -207, -201,    0, -191, -181, -178, -177,    0,    0,
    0, -175, -182,    0, -180, -235,    0, -235, -195, -158,
 -192, -192, -260, -191,    0, -170,    0, -235,    0,    0,
 -183, -174, -235, -247, -157,    0,    0,    0,    0,    0,
 -235, -167, -179,    0,    0, -166, -235, -235, -235, -235,
 -235,    0, -171,    0, -247, -235,    0,    0, -210, -210,
    0,    0, -247, -150,    0, -247,    0,    0, -150, -192,
 -203,    0, -149,    0,    0, -192,    0, -150,    0,    0,
 -192,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0, -152,    0,
    0,    0,    0,    0, -252,    0,    0,    0,    0,    0,
    0, -148, -147, -219,    0,    0,    0,    0,    0,    0,
 -224, -224,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -258,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -205,    0,    0,    0, -255, -222,
    0,    0, -164,    0,    0, -187,    0,    0,    0, -144,
 -224,    0,    0,    0,    0, -224,    0,    0,    0,    0,
 -224,    0,
};
static const short yygindex[] = {                         0,
  -26,    0,    0,    0,  -72,  -31,    0,    0,    0,   79,
   94,    0,    0,    0,    0,    0,    0,    0,   75,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 118
static const short yytable[] = {                         47,
   48,   44,   23,   10,   11,   40,   82,   40,   18,    1,
   18,   53,    3,   40,   40,   90,    5,   40,   40,   40,
   49,    6,   23,   40,   65,   40,   57,   58,   59,   60,
   69,   70,   71,   72,   73,   12,   24,   12,   39,   76,
   39,   17,   38,   17,   39,   40,   39,   39,   83,   85,
   39,   39,   39,   19,   89,   20,   39,   20,   39,   92,
   10,   11,    7,   12,   84,   59,   60,   13,   14,   25,
   26,   10,   11,   22,   12,   22,   27,   15,   13,   14,
   29,   28,   31,   32,   45,   54,   55,   33,   15,   56,
   57,   58,   59,   60,   57,   58,   59,   60,   34,   67,
   37,   46,   51,   64,   62,   66,   68,   75,   77,   12,
   87,   50,   13,   15,   35,   12,   35,   63,
};
static const short yycheck[] = {                         31,
   32,   28,  261,  264,  265,  261,   79,  263,  261,  264,
  263,   38,  266,  269,  270,   88,  278,  273,  274,  275,
  281,  279,  281,  279,   51,  281,  274,  275,  276,  277,
   57,   58,   59,   60,   61,  260,  281,  262,  261,   66,
  263,  261,  278,  263,  280,  281,  269,  270,   80,   81,
  273,  274,  275,  273,   86,  261,  279,  263,  281,   91,
  264,  265,  259,  267,  268,  276,  277,  271,  272,  264,
  278,  264,  265,  261,  267,  263,  278,  281,  271,  272,
  262,  273,  261,  261,  280,  269,  270,  263,  281,  273,
  274,  275,  276,  277,  274,  275,  276,  277,  281,  279,
  281,  260,  273,  261,  279,  273,  273,  279,  259,  262,
  260,   33,  261,  261,  279,  260,   23,   43,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LOWERTELSE","tFL","tAO","tAF",
"tPV","tRET","tV","tINT","tCONST","tMAIN","tIF","tELSE","tINF","tSUP","tWHILE",
"tFONCTION","tEGAL","tSOU","tADD","tMUL","tDIV","tPO","tPF","tNB","tID",
};
static const char *yyrule[] = {
"$accept : Start",
"Start : tINT Main",
"Main : tMAIN tPO tPF Block_Fonc",
"$$1 :",
"Block : tAO $$1 Instruction tAF",
"$$2 :",
"Block_Fonc : tAO $$2 Instruction Return tAF",
"Instruction : Declarations tPV Instruction",
"Instruction : Affectations tPV Instruction",
"Instruction : Ifelse",
"Instruction : While",
"Instruction : AppelFonc",
"Instruction :",
"Declarations : Declaration",
"Declarations : Declaration tV Declarations",
"Affectations : Affectation",
"Affectations : Affectation Affectations",
"Declaration : tINT tID",
"Declaration : tID",
"$$3 :",
"Declaration : tINT tID $$3 tEGAL Expression",
"$$4 :",
"Declaration : tCONST tINT tID $$4 tEGAL Expression",
"Affectation : tID tEGAL Expression",
"Ifelse : tIF tPO Condition tPF ActionJMF Block ActionEndJMF Instruction",
"Ifelse : tIF tPO Condition tPF ActionJMF Block ActionEndJMF tELSE ActionJMP Block ActionEndJMP Instruction",
"$$5 :",
"$$6 :",
"$$7 :",
"While : tWHILE tPO $$5 Condition tPF $$6 Block $$7 Instruction",
"ActionJMF :",
"ActionEndJMF :",
"ActionJMP :",
"ActionEndJMP :",
"AppelFonc : tFONCTION",
"Condition : Expression Comp Expression",
"Comp : tSUP",
"Comp : tINF",
"Comp : tEGAL tEGAL",
"Expression : Expression tADD Expression",
"Expression : Expression tSOU Expression",
"Expression : Expression tMUL Expression",
"Expression : Expression tDIV Expression",
"Expression : tPO Expression tPF",
"Expression : tID",
"Expression : tNB",
"Return : tRET tNB tPV",

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
#line 133 "yacctest.yacc"


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
#line 333 "y.tab.c"

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
case 3:
#line 29 "yacctest.yacc"
	{nestlevel ++;}
break;
case 4:
#line 29 "yacctest.yacc"
	{nestlevel -- ;}
break;
case 5:
#line 31 "yacctest.yacc"
	{nestlevel ++;}
break;
case 6:
#line 31 "yacctest.yacc"
	{nestlevel --;}
break;
case 17:
#line 50 "yacctest.yacc"
	{ts_create(yystack.l_mark[0].id,0,0, nestlevel);}
break;
case 18:
#line 51 "yacctest.yacc"
	{ts_create(yystack.l_mark[0].id,0,0,nestlevel);}
break;
case 19:
#line 52 "yacctest.yacc"
	{ts_create(yystack.l_mark[0].id,0,0,nestlevel) ;}
break;
case 20:
#line 52 "yacctest.yacc"
	{fprintf(fid,"COP %d, %d\n",ts_get_addr(yystack.l_mark[-3].id),yystack.l_mark[0].nb);ts_init_var(yystack.l_mark[-3].id);ts_delete();count_line++;}
break;
case 21:
#line 53 "yacctest.yacc"
	{ts_create(yystack.l_mark[0].id,0,1,nestlevel) ; printf("nestlevel = %d\n",nestlevel);}
break;
case 22:
#line 53 "yacctest.yacc"
	{fprintf(fid,"COP %d, %d\n",ts_get_addr(yystack.l_mark[-3].id),yystack.l_mark[0].nb);ts_init_var(yystack.l_mark[-3].id);ts_delete();count_line++;}
break;
case 23:
#line 55 "yacctest.yacc"
	{fprintf(fid,"COP %d, %d\n",  ts_get_addr(yystack.l_mark[-2].id),yystack.l_mark[0].nb); ts_init_var(yystack.l_mark[-2].id); ts_delete();count_line++;}
break;
case 26:
#line 60 "yacctest.yacc"
	{  linejmpwhile[indexwhile]=count_line; indexwhile++; }
break;
case 27:
#line 60 "yacctest.yacc"
	{fprintf(fid, "JMF %d,      \n",tab->sp-1); count_line++; tj_adddeb(count_line);}
break;
case 28:
#line 61 "yacctest.yacc"
	{tj_adddest(count_line,1); fprintf(fid, "JMP         \n"); count_line++; tj_adddeb(count_line); tj_adddest(linejmpwhile[indexwhile-1]-1,1) ; indexwhile--;}
break;
case 30:
#line 63 "yacctest.yacc"
	{fprintf(fid,"JMF %d,      \n",tab->sp-1);
				 count_line++;
				 tj_adddeb(count_line);  
				}
break;
case 31:
#line 68 "yacctest.yacc"
	{tj_adddest(count_line,0);}
break;
case 32:
#line 70 "yacctest.yacc"
	{fprintf(fid,"JMP          \n");
			   count_line++;
			   tj_adddeb(count_line);
			  }
break;
case 33:
#line 75 "yacctest.yacc"
	{tj_adddest(count_line,0);}
break;
case 35:
#line 80 "yacctest.yacc"
	{switch (yystack.l_mark[-1].nb) {
														case 1 :fprintf(fid,"SUP %d, %d, %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
														count_line++;
														break;
														case 2 : fprintf(fid,"INF %d, %d, %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
														count_line++;
														break;
														default : fprintf(fid,"EQU %d, %d, %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
														count_line++;
													}
													ts_delete();}
break;
case 36:
#line 93 "yacctest.yacc"
	{yyval.nb=1;}
break;
case 37:
#line 94 "yacctest.yacc"
	{yyval.nb=2 ;}
break;
case 38:
#line 95 "yacctest.yacc"
	{yyval.nb=3;}
break;
case 39:
#line 98 "yacctest.yacc"
	{fprintf(fid,"ADD %d, %d, %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											ts_delete();
											count_line++;
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 40:
#line 103 "yacctest.yacc"
	{fprintf(fid,"SOU %d, %d, %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											ts_delete();
											count_line++;
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 41:
#line 108 "yacctest.yacc"
	{fprintf(fid,"MUL %d, %d, %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											ts_delete();
											count_line++;
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 42:
#line 113 "yacctest.yacc"
	{fprintf(fid,"DIV %d, %d, %d\n",yystack.l_mark[-2].nb,yystack.l_mark[-2].nb,yystack.l_mark[0].nb);
											ts_delete();
											count_line++;
											yyval.nb=yystack.l_mark[-2].nb;}
break;
case 43:
#line 118 "yacctest.yacc"
	{yyval.nb=yystack.l_mark[-1].nb;}
break;
case 44:
#line 120 "yacctest.yacc"
	{int a = ts_get_addr(yystack.l_mark[0].id);
					int b = ts_create ("temp",1,0,nestlevel);
					fprintf(fid,"COP %d, %d\n",b,a);
					count_line++;
					yyval.nb=b;}
break;
case 45:
#line 126 "yacctest.yacc"
	{int a = ts_create("temp",1,0,nestlevel);
					fprintf(fid,"AFC %d,%d\n",a,yystack.l_mark[0].nb);
					count_line++;
					yyval.nb = a;}
break;
#line 690 "y.tab.c"
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
