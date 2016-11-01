%{
#include <stdio.h>
#include <string.h>
 
void yyerror(const char *str)
{
        fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
        return 1;
} 
  
int main()
{
        yyparse();
        return 0;
} 

%}

%token PROGRAM IDENTIFIER SEMICOLON DOT CONSTANTS EQUALS NUMBER TYPES INTEGER ARRAY SQBR_ON SQBR_OFF OF RECORD END COLON COMMA VAR FORWARD PROCEDURE FUNCTION PAR_ON PAR_OFF CURLY_ON CURLY_OFF PRINT READ WHILE DO IF THEN EQ NEQ LT GT LTEQ GTEQ FOR COLON_EQ UPTO DOWNTO PLUS MINUS MULT DIV 

%%

program: /* empty */
       | IDENTIFIER