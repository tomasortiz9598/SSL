
#include <stdio.h>
#include "parser.h"


int main(void){
    if (parser())
        printf("La expresion es valida");
    else
      printf("La expresion no es valida");
    return 0;
}