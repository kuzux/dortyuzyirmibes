BINS=compiler
OBJS=grammar.o lex.o
CFLAGS=-O2 -g
LEX=flex
YACC=bison
CC=gcc
LIBS=-ll
OUT_SRCS=grammar.tab.c grammar.tab.h lex.yy.c

all: $(BINS)

.PHONY = all clean

grammar.tab.c: grammar.y
	$(YACC) -d $<

lex.yy.c: grammar.l grammar.tab.c
	$(LEX) $<

grammar.o: grammar.tab.c
	$(CC) $(CFLAGS) $< -c -o $@

lex.o: lex.yy.c
	$(CC) $(CFLAGS) $< -c -o $@

compiler: grammar.o lex.o
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

clean:
	rm $(BINS) $(OBJS) $(OUT_SRCS)
