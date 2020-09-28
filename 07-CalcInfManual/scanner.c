#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

Token GetNextToken(){
    int c;
    c = getchar();
    printf("[Scanner] Caracter: %c\n",c);
    if (esMultiplicacion(c))
        return T_MULTIPLICADOR;
    if (esSuma(c))
        return T_SUMA;
    if (esEOF(c))
        return T_EOF;
    if (esLetra(c)){
        leerId();
        return T_IDENTIFICADOR;
    }
    if (esDigito(c)){
        leerCte();
        return T_IDENTIFICADOR;
    }
    errorLexico(c);
    return T_INVALIDO;
}

bool esMultiplicacion(const int c){
   return c=='*';
}
bool esSuma(const int c){
    return c=='+';
}
bool esEOF(const int c){
    return c==EOF;
}
bool esLetra(const int c){
    return isalpha(c);
}
bool esDigito(const int c){
    return isdigit(c);
}

void leerId(){
    int c;
    c = getchar();
    if (esEOF(c)){
        ungetc(c, stdin);
        return;
    }
    else if (esLetra(c))
        leerId();
    else if (esDigito(c))
        leerId();
    else{
        ungetc(c, stdin);
        return;
    }    

}
void leerCte(){
    int c ;
    c = getchar();
    if (esEOF(c)){
        ungetc(c, stdin);
        return;
    }
    else if (esDigito(c))
        leerCte();
    else{
        ungetc(c, stdin);
        return;
    }
}


void errorLexico(const int c){
    printf("[Scanner] Error Lexico\n");
    printf("[Scanner] Caracter invalido: %c\n",c);
}