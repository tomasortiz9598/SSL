%{
  #include <stdio.h>
  #include <string.h>
  #include "scanner.h"
  #include "parser.h"
  #include "tablaSimbolos.h"


void yyerror(char const *s){printf ("Error en el Parser: %s\n", s);} // cuando yyparser detecta un error sintacto hace uso de yyerror, por lo cual es necesario declararla

  
static int yylex();


%}

%union { //declara los tipos de valores de los token para el analisis semantico
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
  | T_EVALUACION expresion {printf("El resultado es: %d\n", $2);};

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
     printf("Error Sintactico \n");
     return;
    default:
      printf("Otro Error\n");
      return;
  }
}


