#include "types.h"
#include <iostream>

// we might need an extern reference to the
// global symbol table here

void type_check(ast_node_t* root) {
    switch(root->type) {
        // similar to type_calc
        // switch over the types
        // recurse for non-leaf types
        // but this time fail if a statement has
        // an invalid type
        default:
            std::cout << "Can't process " << root->type << std::endl;
            break;
    }
}
