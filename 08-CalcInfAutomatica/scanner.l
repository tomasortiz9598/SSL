%{
#include <stdio.h>
#include "scanner.h"
#include "logger.h"
%}

%option noyywrap
%%

[0-9]+    {yylval.intVal=atoi(yytext);return T_CONSTANTE;}
\(        return T_LBRACKET;
\)        return T_RBRACKET;
\*        return T_MULTIPLICACION;
\+        return T_SUMA;
\$        return T_EVALUACION;
\=        return T_ASIGNACION;
[a-zA-Z_][a-zA-Z]*      {strcpy(yylval.strVal, yytext);return T_IDENTIFICADOR;}
<<EOF>>   return T_EOF;
[ ]+ ;
.         {
            errorLexico();
            return T_INVALIDO;
          }

%%


int GetNextToken(){
  return yylex();
}

static void errorLexico(){
  log_error("[Scanner] Error Lexico - Caracter invalido\n");
  exit(0);
}