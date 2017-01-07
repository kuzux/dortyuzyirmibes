#include "ast.h"

#include <stdlib.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// symbol tables and stuff
// we might need to do those in a per-function basis in the future
map<string, type_t> vars;
map<string, type_t> fn_types;
map<string, map<string, type_t> > record_fields;

void copy_types(type_t& t1, type_t& t2) {
    // that doesn't work with function types
    t1.type = t2.type;
    t1.val.array.len = t2.val.array.len;
    t1.val.array.name = t2.val.array.name;
}

ast_node_t* prog_node(vector<ast_node_t*>* consts, vector<ast_node_t*>* types, vector<ast_node_t*>* vars, vector<ast_node_t*>* funcs, vector<ast_node_t*>* stmts) {
    return NULL;
}

ast_node_t* field_node(ast_node_t* n, char* field){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FIELD;

    res->val.field.var_type = VAR_PLAIN;

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

    res->val.field.var_type = VAR_INDEXED;

    res->val.indexed_var.var_access = n;
    res->val.indexed_var.indices = ns;

    return res;
}

ast_node_t* var_access(char* ident){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_PLAIN_VAR;

    res->val.field.var_type = VAR_PLAIN;

    res->val.plain_var.ident = ident;

    map<string, type_t>::iterator it = vars.find(string(ident));

    if(it != vars.end()) {
        copy_types(res->val.plain_var.type, it->second);
    } else {
        cout << "Variable " << ident << " not found" << endl;
        exit(1);
    }

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

    copy_types(res->val.factor.type, ex->val.expr.type);

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

    switch(acc->val.plain_var.var_type) {
        case VAR_PLAIN:
            copy_types(res->val.factor.type, acc->val.plain_var.type);
            break;
        case VAR_INDEXED:
            copy_types(res->val.factor.type, acc->val.indexed_var.type);
            break;
        case VAR_FIELD:
            copy_types(res->val.factor.type, acc->val.field.type);
            break;
    }
    

    return res;
}

ast_node_t* factor_num(int n){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_FACTOR;

    res->val.factor.expr = NULL;
    res->val.factor.fn_call = NULL;
    res->val.factor.var_access = NULL;
    res->val.factor.number = n;

    res->val.factor.type.type = TYPE_INT;

    return res;
}

ast_node_t* term(ast_node_t* t, ast_node_t* f, char op){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_TERM;

    res->val.term.term = t;
    res->val.term.factor = f;
    res->val.term.op = op;

    bool t_int = (t->type == NODE_TERM && t->val.term.type.type == TYPE_INT)
        || (t->type == NODE_FACTOR && t->val.factor.type.type == TYPE_INT);
    bool f_int = t->val.factor.type.type == TYPE_INT;

    if(t_int && f_int) {
        res->val.term.type.type = TYPE_INT;
    } else {
        cout << "type error" << std::endl;
        exit(1);
    }

    return res;
}

ast_node_t* expr(ast_node_t* ex, ast_node_t* t, char op){
    ast_node_t* res = (ast_node_t*)malloc(sizeof(ast_node_t));

    res->type = NODE_EXPR;

    res->val.expr.expr = ex;
    res->val.expr.term = t;
    res->val.expr.op = op;

    bool e_int = (ex->type == NODE_EXPR && ex->val.expr.type.type == TYPE_INT)
        || (ex->type == NODE_TERM && ex->val.expr.type.type == TYPE_INT)
        || (ex->type == NODE_FACTOR && ex->val.factor.type.type == TYPE_INT);
    bool t_int = (t->type == NODE_TERM && t->val.term.type.type == TYPE_INT)
        || (t->type == NODE_FACTOR && t->val.factor.type.type == TYPE_INT);

    if(t_int && e_int) {
        res->val.term.type.type = TYPE_INT;
    } else {
        cout << "type error" << std::endl;
        exit(1);
    }

    return res;
}
