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

%}

%token PROGRAM IDENTIFIER SEMICOLON DOT CONSTANTS EQUALS NUMBER TYPES INTEGER ARRAY SQBR_ON SQBR_OFF OF RECORD END COLON COMMA VAR FORWARD PROCEDURE FUNCTION PAR_ON PAR_OFF CURLY_ON CURLY_OFF PRINT READ WHILE DO IF THEN ELSE EQ NEQ LT GT LEQ GEQ FOR COLON_EQ UPTO DOWNTO PLUS MINUS MULT DIV MOD

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
typeDefn: IDENTIFIER EQUALS typeDenoter SEMICOLON
typeDenoter: INTEGER
           | IDENTIFIER
           | newType
newType: arrayType
       | recordType
arrayType: ARRAY SQBR_ON NUMBER SQBR_OFF OF typeDenoter
recordType: RECORD recordItemList END
recordItemList: recordItemList SEMICOLON recordItem 
              | recordItem
              | error
recordItem: identifierList COLON typeDenoter
identifierList: identifierList COMMA IDENTIFIER
              | IDENTIFIER

varDefns: /* empty */
        | VAR varDefnList
varDefnList: varDefnList varDefn
           | varDefn SEMICOLON
           | error SEMICOLON
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
                  | error 
formalParam: valueParam 
           | variableParam
valueParam: identifierList COLON returnType
variableParam: VAR identifierList COLON returnType

stmts: CURLY_ON stmtList CURLY_OFF
stmtList: stmtList SEMICOLON stmt 
        | stmt
        | error
stmt: assignmentStmt
    | ioStmt
    | procStmt
    | stmts
    | ifStmt
    | whileStmt
    | forStmt

assignmentStmt: variableAccess EQUALS expr
variableAccess: IDENTIFIER
              | indexedVariable
              | fieldDesignator

indexedVariable: variableAccess SQBR_ON indexExprList SQBR_OFF
indexExprList: indexExprList COMMA expr 
             | expr
             | error

fieldDesignator: variableAccess DOT IDENTIFIER
               | variableAccess DOT error
ioStmt: PRINT PAR_ON variableAccess PAR_OFF
      | READ PAR_ON variableAccess PAR_OFF

procStmt: IDENTIFIER params
params: PAR_ON paramList PAR_OFF
      | PAR_ON PAR_OFF
paramList: paramList COMMA expr 
         | expr

ifStmt: IF condExpr THEN stmt
      | IF condExpr THEN stmt ELSE stmt

whileStmt: WHILE condExpr DO stmt

condExpr: expr relop expr
        | expr 
relop: EQ | NEQ | GT | LT | GEQ | LEQ

forStmt: FOR IDENTIFIER COLON_EQ expr direction expr DO stmt
direction: UPTO | DOWNTO

expr: expr PLUS term
    | expr MINUS term
    | term
term: term MULT factor 
    | term DIV factor
    | term MOD factor
    | factor
factor: PAR_ON expr PAR_OFF
      | functionCall
      | variableAccess
      | NUMBER
      | error

functionCall: IDENTIFIER params
