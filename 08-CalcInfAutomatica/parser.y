%{
  #include <stdio.h>
  #include <string.h>
  #include "scanner.h"
  #include "parser.h"
  #include "tablaSimbolos.h"
  #include "logger.h"


void yyerror(char const *s){log_error ("Error en el Parser: %s\n", s);} 
static int yylex();


%}

%union { 
  int intVal;
  char strVal[100];
}

%token <strVal> T_MULTIPLICACION
%token <strVal> T_SUMA
%token <strVal> T_IDENTIFICADOR
%token <intVal> T_CONSTANTE
%token <strVal> T_LBRACKET
%token <strVal> T_RBRACKET
%token <strVal> T_ASIGNACION
%token <strVal> T_INVALIDO
%token <strVal> T_EVALUACION
%token <strVal> T_EOF 0 // es necesario darle el valor cero para indicar que es el token de EOF

%type <intVal> factor
%type <intVal> termino
%type <intVal> expresion
%type <intVal> sentencia
%type <intVal> listaSentencias
%type <intVal> programa

%%
programa: listaSentencias T_EOF;

listaSentencias: sentencia 
  | listaSentencias sentencia;

sentencia: T_IDENTIFICADOR T_ASIGNACION T_CONSTANTE {setTS($1,$3); }
  | T_EVALUACION expresion {log_info("El resultado es: %d\n", $2);};

expresion: termino {$$=$1;}
 | expresion T_SUMA termino {$$=$1+$3;}
 ;

termino: factor {$$=$1;}
 | factor T_MULTIPLICACION termino {$$=$1*$3;}
 ;

factor: T_IDENTIFICADOR {$$=getTS($1);}
 | T_CONSTANTE {$$=$1;}
 | T_LBRACKET expresion T_RBRACKET {$$=$2;}
;



%%


static int yylex(void){   
    return GetNextToken();
}

void parser(){
  switch(yyparse()){
    case 0:
      return;
    case 1:
     log_error("Error Sintactico \n");
     return;
    default:
      log_error("Otro Error\n");
      return;
  }
}


