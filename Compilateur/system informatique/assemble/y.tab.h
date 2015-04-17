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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char* id ;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
