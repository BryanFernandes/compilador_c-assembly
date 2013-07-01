#PROJECT_SRC_FILES = $(wildcard *.c)

CC = gcc
FLEX = flex
BISON = bison
BFLAGS = -d -v


prog:
	${FLEX} langC.l
	${BISON} ${BFLAGS} langC.y
	${CC} -o prog langC.tab.c

run:
	./prog teste.c

clean:
	rm langC.output
	rm langC.tab.c
	rm langC.tab.h
	rm lex.yy.c
	rm prog

lex:
	${FLEX} langC.l
	${CC} -o lex_prog lex.yy.c ${LIBS}

runLex:
	./lex_prog teste.c