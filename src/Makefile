#PROJECT_SRC_FILES = $(wildcard *.c)

CC = gcc
FLEX = flex
BISON = bison
BFLAGS = -d -v
LIBS = -I.

prog: 
	${FLEX} langC.l
	${BISON} ${BFLAGS} langC.y
	${CC} -o prog langC.tab.c

run:
	./prog

clean:
	rm langC.output
	rm langC.tab.c
	rm langC.tab.h
	rm lex.yy.c
	rm prog