#include <stdio.h>
#include <stdbool.h>

typedef enum{
    T_MULTIPLICADOR,
    T_SUMA,
    T_CONSTANTE,
    T_IDENTIFICADOR,
    T_INVALIDO,
    T_EOF
} Token;


bool esMultiplicacion(const int );
bool esSuma(const int );
bool esEOF(const int );
bool esLetra(const int );
bool esDigito(const int );
void leerId();
void leerCte();

void errorLexico(const int);


Token GetNextToken(); 