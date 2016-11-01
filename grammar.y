%{
#include <stdio.h>
#include <string.h>
 
void yyerror(const char *str) {
    extern int yylineno;
    fprintf(stderr,"error: %s at %d\n",str, yylineno);
}
 
int yywrap() {
    return 1;
} 
  
int main() {
    yyparse();
    return 0;
} 

%}

%token PROGRAM IDENTIFIER SEMICOLON DOT CONSTANTS EQUALS NUMBER TYPES INTEGER ARRAY SQBR_ON SQBR_OFF OF RECORD END COLON COMMA VAR FORWARD PROCEDURE FUNCTION PAR_ON PAR_OFF CURLY_ON CURLY_OFF PRINT READ WHILE DO IF THEN EQ NEQ LT GT LEQ GEQ FOR COLON_EQ UPTO DOWNTO PLUS MINUS MULT DIV 

%%

program: PROGRAM IDENTIFIER SEMICOLON progBlock DOT

progBlock: constantDefns typeDefns varDefns procFuncDefns stmts

block: varDefns stmts

constantDefns: /* empty */
             | CONSTANTS constantList
constantList: constantList constDefn
            | constDefn
constDefn: IDENTIFIER EQUALS NUMBER SEMICOLON

typeDefns: /* empty */
         | TYPES typeList
typeList: typeList typeDefn 
        | typeDefn
typeDefn: IDENTIFIER typeDenoter SEMICOLON
typeDenoter: INTEGER
           | newType
newType: arrayType
       | recordType
arrayType: ARRAY SQBR_ON NUMBER SQBR_OFF OF typeDenoter
recordType: RECORD recordItemList END
recordItemList: recordItemList SEMICOLON recordItem 
              | recordItem
recordItem: identifierList COLON typeDenoter
identifierList: identifierList COMMA IDENTIFIER
              | IDENTIFIER

varDefns: /* empty */
        | VAR varDefnList SEMICOLON
varDefnList: varDefnList SEMICOLON varDefn
           | varDefn 
varDefn: identifierList COLON typeDenoter

procFuncDefns: /* empty */
             | procFuncDefnList SEMICOLON
procFuncDefnList: procFuncDefnList SEMICOLON procFuncDefn 
                | procFuncDefn
procFuncDefn: procDefn | funcDefn
procDefn: procHead SEMICOLON FORWARD
        | procHead SEMICOLON block
procHead: PROCEDURE IDENTIFIER
        | PROCEDURE IDENTIFIER formalParamList
funcDefn: funcHead SEMICOLON FORWARD
        | funcHead SEMICOLON block
funcHead: FUNCTION IDENTIFIER COLON returnType
        | FUNCTION IDENTIFIER formalParamList COLON returnType
returnType: INTEGER
          | IDENTIFIER
formalParamList: PAR_ON formalParamSecList PAR_OFF
formalParamSecList: formalParamSecList SEMICOLON formalParam
                  | formalParam
formalParam: valueParam 
           | variableParam
valueParam: identifierList COLON returnType
variableParam: VAR identifierList COLON returnType

stmts: CURLY_ON stmtList CURLY_OFF
stmtList: stmtList SEMICOLON stmt 
        | stmt
stmt: assignmentStmt
    | ioStmt
    | procStmt
    | stmts
    | ifStmt
    | whileStmt
    | forStmt

assignmentStmt: variableAccess COLON_EQ expr
variableAccess: IDENTIFIER
              | indexedVariable
              | fieldDesignator
indexedVariable: variableAccess SQBR_ON indexExprList SQBR_OFF
indexExprList: indexExprList COMMA expr 
             | expr
fieldDesignator: variableAccess DOT IDENTIFIER

ioStmt: /* empty */

procStmt: /* empty */

ifStmt: /* empty */

whileStmt: /* empty */

forStmt: /* empty */

expr: /* empty */
