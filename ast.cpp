#include "ast.h"

#include <stdlib.h>

ast_node_t* prog_node(vector<ast_node_t*>* consts, vector<ast_node_t*>* types, vector<ast_node_t*>* vars, vector<ast_node_t*>* funcs, vector<ast_node_t*>* stmts) {
    return NULL;
}

ast_node_t* field_node(ast_node_t* n, char* field){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FIELD;

    res->val.field.var = n;
    res->val.field.field = std::string(field);

    // res->val.field.type needs to be determined
    // by looking at some kind of a symbol table

    return res;
}

// TODO write similar functions for the rest of them
ast_node_t* indexed_node(ast_node_t* n, vector<ast_node_t*>* ns){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_INDEXED_VAR;

    res->val.indexed_var.var_access = n;
    res->val.indexed_var.indices = ns;

    return res;
}

ast_node_t* var_access(char* ident){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_PLAIN_VAR;

    res->val.plain_var.ident = ident;

    return res;
}

ast_node_t* fn_call(char* fn, vector<ast_node_t*>* ns){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FNCALL;

    res->val.fn_call.name = std::string(fn);
    res->val.fn_call.params = ns;

    return res;
}

ast_node_t* factor_paren(ast_node_t* ex){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FACTOR;

    res->val.factor.expr = ex;
    res->val.factor.fn_call = NULL;
    res->val.factor.var_access = NULL;
    res->val.factor.number = 0;

    return res;
}

ast_node_t* factor_fn(ast_node_t* call){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FACTOR;

    res->val.factor.expr = NULL;
    res->val.factor.fn_call = call;
    res->val.factor.var_access = NULL;
    res->val.factor.number = 0;

    return res;
}

ast_node_t* factor_varacc(ast_node_t* acc){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FACTOR;

    res->val.factor.expr = NULL;
    res->val.factor.fn_call = NULL;
    res->val.factor.var_access = acc;
    res->val.factor.number = 0;

    return res;
}

ast_node_t* factor_num(int n){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FACTOR;

    res->val.factor.expr = NULL;
    res->val.factor.fn_call = NULL;
    res->val.factor.var_access = NULL;
    res->val.factor.number = n;

    return res;
}

ast_node_t* term(ast_node_t* t, ast_node_t* f, char op){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_TERM;

    res->val.term.term = t;
    res->val.term.factor = f;
    res->val.term.op = op;

    return res;
}

ast_node_t* expr(ast_node_t* ex, ast_node_t* t, char op){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_EXPR;

    res->val.expr.expr = ex;
    res->val.expr.term = t;
    res->val.expr.op = op;

    return res;
}
