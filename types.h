#ifndef _TYPES_H
#define _TYPES_H

#include "ast.h"

void type_calc(ast_node_t* root);
void type_check(ast_node_t* root);

#endif
