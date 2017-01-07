#ifndef _AST_H
#define _AST_H

#include <stddef.h>
#include <stdint.h>
#include <vector>
#include <string>
using namespace std;

#define NODE_PROG -1
#define NODE_BLOCK -2

#define NODE_CONST -3
#define NODE_TYPE -4
#define NODE_VAR -5
#define NODE_FUNC -6 

#define NODE_ASS_STMT -7
#define NODE_READ_STMT -8
#define NODE_PRINT_STMT -9 
#define NODE_IF_STMT -10
#define NODE_WHILE_STMT -11
#define NODE_FOR_STMT -12
#define NODE_FN_CALL -13
#define NODE_STMT_BLOCK -14

#define NODE_PLAIN_VAR -15
#define NODE_INDEXED_VAR -16
#define NODE_FIELD -17

#define NODE_EXPR -18
#define NODE_TERM -19
#define NODE_FACTOR -20

#define NODE_FNCALL -21

#define TYPE_INT 1
#define TYPE_ARRAY 2
#define TYPE_RECORD 3
#define TYPE_FUNCTION 4

typedef struct type_st {
    int8_t type;

    union type_tu {
        string name;

        struct arr{
            string name;
            int len;
            ~arr(){ };
        } array;

        struct {
            vector<struct type_st*> args;
            struct type_st* retval;
        } fn;

        ~type_tu(){ };
    } val;

    ~type_st(){ };
} type_t;

/* tagged union type for ast node */
typedef struct ast_node {
    int8_t type;

    union {
        // todo add more structs for the ast
        struct {
            string name;

            vector<struct ast_node*>* consts;
            vector<struct ast_node*>* types;
            vector<struct ast_node*>* vars;
            vector<struct ast_node*>* funcs;

            vector<struct ast_node*>* stmts;
        } prog;

        struct {
            vector<struct ast_node*>* vars;
            vector<struct ast_node*>* stmts;
        } block;

        struct {
            struct ast_node* lval;
            struct ast_node* rval;
        } ass;

        struct {
            struct ast_node* expr;
        } read, print;

        struct {
            struct ast_node* cond;
            struct ast_node* stmt;
        } if_, while_;

        struct {
            struct ast_node* start;
            char* direction;
            struct ast_node* end;
            struct ast_node* stmt;
        } for_;

        struct {
            vector<struct ast_node*>* stmts;
        } stmt_block;

        struct {
            struct ast_node* expr;
            struct ast_node* term;
            char op;
            type_t type;
        } expr;

        struct {
            struct ast_node* term;
            struct ast_node* factor;
            char op;
            type_t type;
        } term;

        struct {
            struct ast_node* expr;
            struct ast_node* fn_call;
            struct ast_node* var_access;
            int number;
            type_t type;
        } factor;

        struct {
            string name;
            vector<struct ast_node*>* params;
            type_t type;
        } fn_call;

        struct {
            string ident;
            type_t type;
        } plain_var;

        struct {
            struct ast_node* var_access;
            vector<struct ast_node*>* indices;

            type_t type;
        } indexed_var;

        struct {
            struct ast_node* var;
            string field;

            type_t type;
        } field;
    } val;
} ast_node_t;

extern "C" {

// todo add more constructor functions for the ast stuff

ast_node_t* prog_node(vector<ast_node_t*>* consts, vector<ast_node_t*>* types, vector<ast_node_t*>* vars, vector<ast_node_t*>* funcs, vector<ast_node_t*>* stmts);

ast_node_t* field_node(ast_node_t* n, char* field);
ast_node_t* indexed_node(ast_node_t* n, vector<ast_node_t*>* ns);
ast_node_t* var_access(char* ident);
ast_node_t* fn_call(char* fn, vector<ast_node_t*>* ns);
ast_node_t* factor_paren(ast_node_t* ex);
ast_node_t* factor_fn(ast_node_t* call);
ast_node_t* factor_varacc(ast_node_t* acc);
ast_node_t* factor_num(int n);
ast_node_t* term(ast_node_t* t, ast_node_t* f, char op);
ast_node_t* expr(ast_node_t* ex, ast_node_t* t, char op);

}

#endif
