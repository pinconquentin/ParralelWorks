test: lex.yy.c y.tab.c y.tab.h tab_symb.c
	gcc y.tab.c lex.yy.c -lfl -o test

lex.yy.c: firstlex.lex
	flex firstlex.lex

y.tab.c: yacctest.yacc
	byacc -d -v yacctest.yacc

y.tab.h: yacctest.yacc
	byacc -d -v yacctest.yacc

tab_symb.o: tab_symb.c
	gcc tab_symb.c

tab_jump.o: tab_jump.c
	gcc tab_jump.c