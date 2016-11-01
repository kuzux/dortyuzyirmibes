%{
#include <stdio.h>
#include <stdlib.h>
#include "grammar.tab.h"
%}

%option yylineno

%%
program                 return PROGRAM;
;                       return SEMICOLON;
\.                      return DOT;
constants               return CONSTANTS;
=                       return EQUALS;
types                   return TYPES;
integer                 return INTEGER;
array                   return ARRAY;
\[                      return SQBR_ON;
\]                      return SQBR_OFF;
of                      return OF;
record                  return RECORD;
end                     return END;
:                       return COLON;
,                       return COMMA;
var                     return VAR;
forward                 return FORWARD;
procedure               return PROCEDURE;
function                return FUNCTION;
\(                      return PAR_ON;
\)                      return PAR_OFF;
\{                      return CURLY_ON;
\}                      return CURLY_OFF;
print                   return PRINT;
read                    return READ;
while                   return WHILE;
do                      return DO;
if                      return IF;
then                    return THEN;
else                    return ELSE;
==                      return EQ;
!=                      return NEQ;
\<                      return LT;
\>                      return GT;
\<=                     return LEQ;
\>=                     return GEQ;
for                     return FOR;
:=                      return COLON_EQ;
upto                    return UPTO;
downto                  return DOWNTO;
\+                      return PLUS;
\-                      return MINUS;
\*                      return MULT;
\/                      return DIV;

[a-zA-Z_][a-zA-Z_0-9]*  return IDENTIFIER;
[0-9]+                  return NUMBER;

\n                      ; /* ignore newline */
[ \t]                   ; /* ignore whitespace */

%%
