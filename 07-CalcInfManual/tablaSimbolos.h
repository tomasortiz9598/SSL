#include "logger.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXVAL 100


typedef struct {
    char variable[MAXVAL];
    int valor;
}Simbolos;


void setTS(char [],int);
int getTS(char []);