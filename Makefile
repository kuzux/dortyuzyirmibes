BINS=compiler
OBJS=grammar.o lex.o ast.o main.o
CFLAGS=-O2 -g -std=c++11
LEX=flex
YACC=bison
CC=g++
LIBS=-ll
OUT_SRCS=grammar.tab.cpp grammar.tab.hpp lex.yy.c

all: $(BINS)

.PHONY = all clean

grammar.tab.cpp: grammar.ypp
	$(YACC) -d $<

lex.yy.c: grammar.lpp grammar.tab.cpp
	$(LEX) $<

grammar.o: grammar.tab.cpp
	$(CC) -w -c $(CFLAGS) $< -o $@

lex.o: lex.yy.c
	$(CC) -w -c $(CFLAGS) $< -o $@

ast.o: ast.cpp
	$(CC) -c $(CFLAGS) $< -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) $< -c -o $@

compiler: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o compiler $(LIBS)

clean:
	rm $(BINS) $(OBJS) $(OUT_SRCS)
