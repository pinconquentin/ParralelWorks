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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { int nb; char* id ;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
