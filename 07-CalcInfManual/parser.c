#include "parser.h"

//FUNCIONES PRIVADAS
static void listaSentencia();
static void sentencia();
static int expresion();
static int termino();
static int factor();
static void programa();
static void Match();
static void ErrorSintactico();

//VARIABLES
int resultado=0;

void parser (){
  programa();
}

//FUNCIONES PRIVADAS
static void programa(){
  listaSentencia();
  Match(T_EOF);
}

static void listaSentencia(){
  sentencia();
  while (1) {
    switch (GetNextToken()) {
      case T_IDENTIFICADOR:case T_EVALUACION:
        sentencia();
        break;
      default:
        return;
    }
  }
}

static void sentencia(){
  char variable[100];
  switch (GetNextToken()){
    case T_IDENTIFICADOR:
      Match(T_IDENTIFICADOR);
      strcpy(variable,lexema);
      log_debug("[Parser] Sentencia, nombre del identificador guardado en lexema: %s\n", lexema);
      Match(T_ASIGNACION);
      Match(T_CONSTANTE);
      setTS(variable,atoi(lexema));
      return;
    case T_EVALUACION:
      Match(T_EVALUACION);
      resultado=expresion();
      log_info("[Parser] Resultado de evaluación: %d\n", resultado);
      return;
  }
}

static int expresion(void){
  int r=termino();
  if (GetNextToken()==T_SUMA){
      Match(T_SUMA);
      r=r+expresion();
    }
  return r;
}

static int termino(){
  int r =factor();
  if (GetNextToken()==T_MULTIPLICACION){
        Match(T_MULTIPLICACION);
        r=r*termino();
  }
  return r;
}

static int factor(){
  int r;
  Token tok = GetNextToken();
  switch (tok){
    case T_IDENTIFICADOR:  
      Match(T_IDENTIFICADOR);
      return getTS(lexema);
    case T_CONSTANTE:
      Match(T_CONSTANTE);
      return atoi(lexema);
    case T_LBRACKET:
      Match(T_LBRACKET);
      r=expresion();
      Match(T_RBRACKET);
      return r;
    default:
      ErrorSintactico();     
      return r;
  }
}

static void Match(Token t){
  if ( !(t == GetNextToken())) 
    ErrorSintactico();
  flagToken = 0; 
}

static void ErrorSintactico(){
  log_error("Error Sintactico\n");
  exit(0);
}