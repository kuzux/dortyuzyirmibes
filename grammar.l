%{
#include <stdio.h>
#include <stdlib.h>
#include "grammar.tab.h"
%}

%%
program                 return PROGRAM;
;                       return SEMICOLON;
\.                      return DOT;
constants               return CONSTANTS;
=                       return EQUALS;
types                   return TYPES;
array                   return ARRAY;

[a-zA-Z_][a-zA-Z_0-9]*  return IDENTIFIER;
[0-9]+                  return NUMBER;

\n                      ; /* ignore newline */
[ \t]                   ; /* ignore whitespace */
%%
