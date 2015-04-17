# main: test
# 	./test < x.txt

test: y.tab.c lex.yy.c  y.tab.h 
	gcc y.tab.c lex.yy.c -lfl -o  test

lex.yy.c: assemblelex.lex y.tab.h
	flex assemblelex.lex

y.tab.c: assembleyacc.yacc
	byacc -d -v assembleyacc.yacc

y.tab.h: assembleyacc.yacc
	byacc -d -v assembleyacc.yacc

