#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logger.h"
#define MAXVAL 100

extern int flagToken;

typedef enum{
    T_MULTIPLICACION,
    T_SUMA,
    T_CONSTANTE,
    T_IDENTIFICADOR,
    T_LBRACKET,
    T_RBRACKET,
    T_INVALIDO,
    T_EVALUACION,
    T_ASIGNACION,
    T_EOF
} Token;

extern int  GetNextToken(); 