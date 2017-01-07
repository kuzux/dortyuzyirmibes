#include "grammar.tab.hpp"
#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "types.h"

extern int yyparse();
extern FILE* yyin;

// todo in the parser, actually set the root node
extern ast_node_t* root;

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
    // todo generate some kind of a symbol table
    // (preferably while parsing)

    type_calc(root);
    type_check(root);

    // todo calculate types
    // todo check types
    // todo actually generate llvm code

    fclose(fp);
    return 0;
}
