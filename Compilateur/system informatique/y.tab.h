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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char* id ;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
