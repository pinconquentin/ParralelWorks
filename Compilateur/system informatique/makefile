main: test test.c
	./test < test.c
 
test: lex.yy.c y.tab.c y.tab.h tab_symb.c tab_fonction.c
	gcc y.tab.c lex.yy.c -lfl -o  test

lex.yy.c: firstlex.lex
	flex firstlex.lex

y.tab.c: yacctab.yacc
	byacc -d -v yacctab.yacc

y.tab.h: yacctab.yacc
	byacc -d -v yacctab.yacc

tab_symb.o: tab_symb.c
	gcc tab_symb.c

tab_fonction.o: tab_fonction.c
	gcc tab_fonction.c
