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

#line 2 "assembleyacc.yacc"
#include <stdio.h>
#include <stdlib.h>

/* definir des tokens*/
#define COP 1
#define AFC 2
#define JMP 3
#define JMF 4

#define ADD 5
#define SOU 6
#define MUL 7
#define DIV 8

#define INF 9
#define SUP 10
#define EQU 11

#define PRI 12

/* declaration de matrice de memoire*/
int matrice[100][4];

/* declaration de compteur de ligne*/
int cpt = 0;

/* declaration une variable global*/
int i;

/* predeclaration des fonctions*/
void print_matrice(int t);
void interpreteur(int t);
#line 36 "assembleyacc.yacc"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char* id ;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 61 "y.tab.c"

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

#define tADD 257
#define tMUL 258
#define tSOU 259
#define tDIV 260
#define tNB 261
#define tEQU 262
#define tCOP 263
#define tAFC 264
#define tJMP 265
#define tJMF 266
#define tINF 267
#define tSUP 268
#define tPRI 269
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    2,    1,    3,    1,    4,    1,    5,
    1,    6,    1,    7,    1,    8,    1,    9,    1,   10,
    1,   11,    1,   12,    1,   13,    1,
};
static const short yylen[] = {                            2,
    1,    0,    0,    0,    6,    0,    6,    0,    6,    0,
    6,    0,    5,    0,    5,    0,    4,    0,    4,    0,
    6,    0,    6,    0,    6,    0,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,
    0,   16,   18,    0,    0,   26,    0,    0,    0,    0,
    0,   12,   14,    0,    0,    0,    0,    0,    4,    6,
    8,   10,   24,    0,    0,   17,   19,   20,   22,   27,
    0,    0,    0,    0,    0,   13,   15,    0,    0,    5,
    7,    9,   11,   25,   21,   23,
};
static const short yydgoto[] = {                         13,
   14,   51,   52,   53,   54,   44,   45,   34,   35,   58,
   59,   55,   38,
};
static const short yysindex[] = {                      -231,
 -259, -258, -256, -255, -254, -253, -252, -249, -248, -247,
 -246, -245,    0,    0, -239, -238, -222, -221, -220, -219,
 -218,    0,    0, -217, -216,    0, -215, -214, -213, -212,
 -211,    0,    0, -231, -231, -210, -209, -231,    0,    0,
    0,    0,    0, -231, -231,    0,    0,    0,    0,    0,
 -231, -231, -231, -231, -231,    0,    0, -231, -231,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                        30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   53,   53,    0,    0,   53,    0,    0,
    0,    0,    0,   53,   53,    0,    0,    0,    0,    0,
   53,   53,   53,   53,   53,    0,    0,   53,   53,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 53
static const short yytable[] = {                         46,
   47,   15,   16,   50,   17,   18,   19,   20,   21,   56,
   57,   22,   23,   24,   25,   26,   60,   61,   62,   63,
   64,   27,   28,   65,   66,    1,    2,    3,    4,    2,
    5,    6,    7,    8,    9,   10,   11,   12,   29,   30,
   31,   32,   33,   36,   37,   39,   40,   41,   42,   43,
   48,   49,    3,
};
static const short yycheck[] = {                         34,
   35,  261,  261,   38,  261,  261,  261,  261,  261,   44,
   45,  261,  261,  261,  261,  261,   51,   52,   53,   54,
   55,  261,  261,   58,   59,  257,  258,  259,  260,    0,
  262,  263,  264,  265,  266,  267,  268,  269,  261,  261,
  261,  261,  261,  261,  261,  261,  261,  261,  261,  261,
  261,  261,    0,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tADD","tMUL","tSOU","tDIV","tNB",
"tEQU","tCOP","tAFC","tJMP","tJMF","tINF","tSUP","tPRI",
};
static const char *yyrule[] = {
"$accept : Start",
"Start : Phrase",
"Start :",
"Phrase :",
"$$1 :",
"Phrase : tADD tNB tNB tNB $$1 Phrase",
"$$2 :",
"Phrase : tMUL tNB tNB tNB $$2 Phrase",
"$$3 :",
"Phrase : tSOU tNB tNB tNB $$3 Phrase",
"$$4 :",
"Phrase : tDIV tNB tNB tNB $$4 Phrase",
"$$5 :",
"Phrase : tCOP tNB tNB $$5 Phrase",
"$$6 :",
"Phrase : tAFC tNB tNB $$6 Phrase",
"$$7 :",
"Phrase : tJMP tNB $$7 Phrase",
"$$8 :",
"Phrase : tJMF tNB $$8 Phrase",
"$$9 :",
"Phrase : tINF tNB tNB tNB $$9 Phrase",
"$$10 :",
"Phrase : tSUP tNB tNB tNB $$10 Phrase",
"$$11 :",
"Phrase : tEQU tNB tNB tNB $$11 Phrase",
"$$12 :",
"Phrase : tPRI tNB $$12 Phrase",

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
#line 61 "assembleyacc.yacc"
 
int main () {
	yyparse();
	print_matrice(cpt);
	printf("\n\n***  interpreter  ***\n");
	interpreteur(cpt);
	return 0;
	}

yyerror (char *s){
	fprintf(stderr, "%s\n",s);
	}

void print_matrice(int t){
	for(i=0;i<t;i++){
	  printf("%d %d %d %d\n",matrice[i][0],matrice[i][1],matrice[i][2],matrice[i][3]);	
	}
}

void interpreteur(int t){
	for(i=0;i<t;i++){
	  switch(matrice[i][0]){
		case ADD:
			matrice[i][1]=matrice[i][2]+matrice[i][3];
			printf("ADD %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);
			break;
		case SOU:
			matrice[i][1]=matrice[i][2]-matrice[i][3];
			printf("SOU %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);
			break;
		case MUL:
			matrice[i][1]=matrice[i][2]*matrice[i][3];
			printf("MUL %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);
			break;
		case DIV:
			matrice[i][1]=matrice[i][2]/matrice[i][3];
			printf("DIV %d %d %d\n",matrice[i][1],matrice[i][2],matrice[i][3]);			
			break;
		default:
			;
	  }		
	}
}

#line 298 "y.tab.c"

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
case 4:
#line 47 "assembleyacc.yacc"
	{matrice[cpt][0]=ADD;matrice[cpt][1]=yystack.l_mark[-2].nb;matrice[cpt][2]=yystack.l_mark[-1].nb;matrice[cpt][3]=yystack.l_mark[0].nb;cpt++;}
break;
case 6:
#line 48 "assembleyacc.yacc"
	{matrice[cpt][0]=MUL;matrice[cpt][1]=yystack.l_mark[-2].nb;matrice[cpt][2]=yystack.l_mark[-1].nb;matrice[cpt][3]=yystack.l_mark[0].nb;cpt++;}
break;
case 8:
#line 49 "assembleyacc.yacc"
	{matrice[cpt][0]=SOU;matrice[cpt][1]=yystack.l_mark[-2].nb;matrice[cpt][2]=yystack.l_mark[-1].nb;matrice[cpt][3]=yystack.l_mark[0].nb;cpt++;}
break;
case 10:
#line 50 "assembleyacc.yacc"
	{matrice[cpt][0]=DIV;matrice[cpt][1]=yystack.l_mark[-2].nb;matrice[cpt][2]=yystack.l_mark[-1].nb;matrice[cpt][3]=yystack.l_mark[0].nb;cpt++;}
break;
case 12:
#line 51 "assembleyacc.yacc"
	{matrice[cpt][0]=COP;matrice[cpt][1]=yystack.l_mark[-1].nb;matrice[cpt][2]=yystack.l_mark[0].nb;matrice[cpt][3]=-1;cpt++;}
break;
case 14:
#line 52 "assembleyacc.yacc"
	{matrice[cpt][0]=AFC;matrice[cpt][1]=yystack.l_mark[-1].nb;matrice[cpt][2]=yystack.l_mark[0].nb;matrice[cpt][3]=-1;cpt++;}
break;
case 16:
#line 53 "assembleyacc.yacc"
	{matrice[cpt][0]=JMP;matrice[cpt][1]=yystack.l_mark[0].nb;matrice[cpt][2]=-1;matrice[cpt][3]=-1;cpt++;}
break;
case 18:
#line 54 "assembleyacc.yacc"
	{matrice[cpt][0]=JMF;matrice[cpt][1]=yystack.l_mark[0].nb;matrice[cpt][2]=-1;matrice[cpt][3]=-1;cpt++;}
break;
case 20:
#line 55 "assembleyacc.yacc"
	{matrice[cpt][0]=INF;matrice[cpt][1]=yystack.l_mark[-2].nb;matrice[cpt][2]=yystack.l_mark[-1].nb;matrice[cpt][3]=yystack.l_mark[0].nb;cpt++;}
break;
case 22:
#line 56 "assembleyacc.yacc"
	{matrice[cpt][0]=SUP;matrice[cpt][1]=yystack.l_mark[-2].nb;matrice[cpt][2]=yystack.l_mark[-1].nb;matrice[cpt][3]=yystack.l_mark[0].nb;cpt++;}
break;
case 24:
#line 57 "assembleyacc.yacc"
	{matrice[cpt][0]=EQU;matrice[cpt][1]=yystack.l_mark[-2].nb;matrice[cpt][2]=yystack.l_mark[-1].nb;matrice[cpt][3]=yystack.l_mark[0].nb;cpt++;}
break;
case 26:
#line 58 "assembleyacc.yacc"
	{matrice[cpt][0]=PRI;matrice[cpt][1]=yystack.l_mark[0].nb;matrice[cpt][2]=-1;matrice[cpt][3]=-1;cpt++;}
break;
#line 552 "y.tab.c"
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
