#include "ast.h"

ast_node_t* field_node(ast_node_t* n, string& field){
    return NULL;
}

ast_node_t* indexed_node(ast_node_t* v, vector<int>& i){
    return NULL;
}

ast_node_t* var_access(string& ident){
    return NULL;
    
}

ast_node_t* varacc_field(ast_node_t* n){
    return NULL;
    
}

ast_node_t* varacc_index(ast_node_t* n){
    return NULL;
    
}

ast_node_t* fn_call(char* fn){
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
