
#include <stdio.h>
#include "parser.h"

static void conf(int argc, char **argv);
static void info(void);

int main(int argc, char **argv){
  conf( argc, argv);
  info();
  parser();
}



static void conf(int argc, char **argv){
  if (argc > 1 && !strcmp("-d", argv[1]) )
        DEBUG = 1;
}

static void info(void){
  log_info("========================================CALCULADORA INFIJA MANUAL========================================\n");
  log_info("\n Ejemplo de uso:\n");
  log_info("\n"
        "\tA=24\n"
        "\tB=4;\n"
        "\t$A*(2+5)+B;\n");

  log_info("\nLos identificadores y constantes tienen un máximo de %d caracteres cada uno\n", MAXVAL);
  log_info("Cada sentencia se debe ingresar en una línea nueva\n");
  log_info("Para terminar el programa enviar señal de FDT: Ctrl+D (Unix), Ctrl+Z (Windows)\n");
  log_info("Para ejecutar el programa en modo debug: ./calc.out -d\n");
  log_info("========================================COMENZANDO EJECUCIÓN========================================\n");
}