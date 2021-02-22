#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

//FUNCIONES PRIVADAS
static Token scanner();
static bool esMultiplicacion(const int );
static bool esSuma(const int );
static bool esEOF(const int );
static bool esLBracket(const int c);
static bool esRBracket(const int c);
static bool esAsignacion (const int c);
static bool esEvaluacion(const int c);
static void cleanLexema();
static void writeToken(int c);
static void endToken();
static void leerId();
static void leerCte();
static void errorLexico();
static const char * getToken(Token token);

//VARIABLES
char lexema[MAXVAL];
Token tokenActual;
int flagToken = 0;
static int pos=0;

//FUNCIONES PUBLICAS
int GetNextToken(){
    if (!flagToken){  //Entro si es 0
        tokenActual = scanner();
        log_debug("[Scanner] Token identificado: %s\n", getToken(tokenActual));
        flagToken = 1;
    }
    return tokenActual;
}

//FUNCIONES PRIVADAS
static Token scanner(){
    cleanLexema();
    int c;
    c = getchar();
    
    
    if (esEOF(c)){
        writeToken(c);
        return T_EOF;
    }

    else if (isalpha(c)){
        writeToken(c);
        leerId();
        return T_IDENTIFICADOR;
    }
    
    else if (isdigit(c)){
        writeToken(c);
        leerCte();
        return T_CONSTANTE;
    }

    else if (esMultiplicacion(c)){
        writeToken(c);
        endToken();
        return T_MULTIPLICACION;
    }
    else if (esSuma(c)){
        writeToken(c);
        endToken();
        return T_SUMA;
    }
    else if (esLBracket(c)){
        writeToken(c);
        endToken();
        return T_LBRACKET;
    }
    else if (esRBracket(c)){
        writeToken(c);
        endToken();
        return T_RBRACKET;
    }
    else if (isspace(c)){
        GetNextToken();
    }
    else if (esAsignacion(c)){
        writeToken(c);
        endToken();
        return T_ASIGNACION;
    }
    else if (esEvaluacion(c)){
        writeToken(c);
        endToken();
        return T_EVALUACION;
    }
    else {   
        errorLexico();
    }
    
}

static bool esMultiplicacion(const int c){
   return c=='*';
}
static bool esSuma(const int c){
    return c=='+';
}
static bool esEOF(const int c){
    return c==EOF;
}
static bool esLBracket(const int c){
  return c == '(';
}
static bool esRBracket(const int c){
  return c == ')';
}
static bool esAsignacion (const int c){
  return c == '=';
}
static bool esEvaluacion(const int c){
  return c == '$';
}
static void leerId(){
    int c;
    c = getchar();
    if (isalpha(c)){
        writeToken(c);
        leerId();
    }
    else{
        endToken();
        ungetc(c, stdin);
        return;
    }    

}
void leerCte(){
    int c ;
    c = getchar();
    if (isdigit(c)){
        writeToken(c);
        leerCte();
    }
    else{
        endToken();
        ungetc(c, stdin);
        return;
    }
}


static void cleanLexema(){
  pos=0;
  lexema[pos]='\0';
  log_debug("[Scanner] Limpiando lexema\n");
}


static void writeToken(int c){
  if (pos > MAXVAL){
    log_error("[Scanner] El lexema supera el máximo definido para el buffer");
    exit(0);
  }

  lexema[pos++] = c;
  log_debug("[Scanner] Guardando caracter '%c', en pos: %d\n", c, pos);
  return;
}

static void endToken(){
  writeToken('\0');
}

static const char * getToken(Token token){
    switch(token){
        case T_MULTIPLICACION:
            return "MULTIPLICACION";
        case T_SUMA:
            return "SUMA";
        case T_CONSTANTE:
            return "CONSTANTE";
        case T_IDENTIFICADOR:
            return "IDENTIFICADOR";
        case T_LBRACKET:
            return "LBRACKET";
        case T_RBRACKET:
            return "RBRACKET";
        case T_INVALIDO:
            return "INVALIDO";
        case T_EVALUACION:
            return "EVALUACION";
        case T_ASIGNACION:
            return "ASIGNACION";
        case T_EOF:
            return "EOF";
    }
    return "WRONG TOKEN";
}

static void errorLexico(){
  log_error("[Scanner] Error Lexico - Caracter invalido\n");
  exit(0);
}