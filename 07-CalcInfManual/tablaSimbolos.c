#include "tablaSimbolos.h"

Simbolos TablaSimbolos[MAXVAL];
int id_TablaSimbolos=0;

static int search(char nombre[MAXVAL]);

void setTS(char nombre[MAXVAL],int valor){
  int pos = search( nombre);
  if (pos == -1){
    log_debug("[tablaSimbolos] Agregando identificador '%s' en posición %d, valor: %d\n", nombre, id_TablaSimbolos, valor);
    strcpy(TablaSimbolos[id_TablaSimbolos].variable,nombre);
    TablaSimbolos[id_TablaSimbolos].valor=valor;
    id_TablaSimbolos++;
  }
  else{
    log_debug("[tablaSimbolos] Actualizando identificador '%s', valor actual: %d, nuevo valor: %d\n", nombre, TablaSimbolos[pos].valor, valor);
    TablaSimbolos[pos].valor=valor;
  }
}


int getTS(char nombre[MAXVAL]){
  int pos = search( nombre);
  if (pos == -1){
    log_error("[tablaSimbolos] identificador no declarado: %s\n", nombre);
    exit(0);
  }
  return TablaSimbolos[pos].valor;
}

static int search(char nombre[MAXVAL]){
    for (int i = 0; i < id_TablaSimbolos; i++)
        if (strcmp(TablaSimbolos[i].variable, nombre) == 0)
            return i;
    log_debug("[tablaSimbolos] Identificador '%s' no encontrado\n", nombre);
    return -1;
}