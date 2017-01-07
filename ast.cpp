#include "ast.h"

#include <stdlib.h>

ast_node_t* field_node(ast_node_t* n, string& field){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FIELD;

    res->val.field.var = n;
    res->val.field.field = field;

    // res->val.field.type needs to be determined
    // by looking at some kind of a symbol table

    return res;
}

// TODO write similar functions for the rest of them
ast_node_t* indexed_node(ast_node_t* n, vector<ast_node_t*>* ns){
    return NULL;
}

ast_node_t* var_access(char* ident){
    return NULL;
}

ast_node_t* varacc_field(ast_node_t* n, char* mem){
    return NULL;
}

ast_node_t* varacc_index(ast_node_t* n, vector<ast_node_t*>* ns){
    return NULL;
}

ast_node_t* fn_call(char* fn, vector<ast_node_t*>* ns){
    return NULL;
}

ast_node_t* factor_paren(ast_node_t* ex){
    return NULL; 
}

ast_node_t* factor_fn(ast_node_t* call){
    return NULL; 
}

ast_node_t* factor_varacc(ast_node_t* acc){
    return NULL;  
}

ast_node_t* factor_num(int n){
    return NULL;  
}

ast_node_t* term(ast_node_t* t, ast_node_t* f, char op){
    return NULL;
}

ast_node_t* expr(ast_node_t* ex, ast_node_t* t, char op){
    return NULL;
}
