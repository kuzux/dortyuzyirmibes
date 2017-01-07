#include "grammar.tab.hpp"
#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern FILE* yyin;

int main(int argc, char** argv) {
    if(argc < 2){
        printf("usage: compiler filename\n");
        return 1;
    }

    FILE* fp=fopen(argv[1], "r");
    if(!fp){
        printf("couldn't open file %s\n", argv[1]);
    }
    yyin = fp;

    yyparse();
    // todo store the root of the ast somewhere
    // todo generate some kind of a symbol table
    // todo calculate types
    // todo check types
    // todo actually generate llvm code

    fclose(fp);
    return 0;
}
