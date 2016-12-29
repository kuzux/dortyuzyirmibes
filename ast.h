#ifndef _AST_H
#define _AST_H

#include <stddef.h>
#include <stdint.h>

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

/* tagged union type for ast node */
typedef struct ast_node {
    int8_t type;

    union {
        struct {
            /* those are all linked lists */
            struct ast_node* consts;
            struct ast_node* types;
            struct ast_node* vars;
            struct ast_node* funcs;

            struct ast_node* stmts;
        } prog;

        struct {
            void* vars;

            struct ast_node* stmts;
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
            struct ast_node* stmts;
        } if_, while_;

        struct {
            struct ast_node* start;
            char* direction;
            struct ast_node* end;
        } for_;

        struct {
            char* fn_name;
            struct ast_node* args;
        } fn_call;

        struct {
            struct ast_node* stmts;
        } stmt_block;
    } val;
} ast_node_t;

#endif
