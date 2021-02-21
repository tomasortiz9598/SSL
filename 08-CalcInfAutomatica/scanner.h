#ifndef scanner_h_
#define scanner_h_
#include "bison.h"

extern int GetNextToken(); // Devuelve el tipo de token que encuentra

static void errorLexico();

int fileno( FILE * stream );


#endif
