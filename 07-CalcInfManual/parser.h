#include <stdio.h>
#include <stdbool.h>
#include "scanner.h"


typedef enum
{
  P_INIT,
  P_OPERADOR,
  P_IDENTIFICADOR,
  P_CONSTANTE,
  P_INVALIDO
} Estado;


bool parser();
