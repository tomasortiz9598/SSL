#include "string.h"

// La cadena debe terminar en '\0'
// getLength: Σ* → |N
int getLength(const char * text){
    int length = 0;
    char * copy;
    for (copy =text; *copy != '\0'; copy++)
        length++;
    return length;
}
// Sin precondicion
// isEmpty: Σ* → |N
int isEmpty( const char * text){
    return *text=='\0';
}

// Las cadena debe terminar en '\0'
// strcmp: Σ* X Σ* → |N
int strcmp(const char* first_text, const char*second_text){
    if(getLength(first_text) !=getLength(second_text))
        return 0;
    for (int i = 0; i <= getLength(first_text); i++)
        if(first_text[i]!=second_text[i])
            return 0;
    return 1;
}

// La cadena debe terminar en '\0' y en destination, donde guardamos el resultado, debe estar reservada la suficiente memoria
// power: Σ* X |N → Σ*

void power( const char*text, unsigned n, char destination[]){
    int length = getLength(text);
    int destLength = getLength(destination);
    int i;
    if (n!= 0){
        for ( i = 0; i < length; i++){
            destination[destLength + i] = text[i%length];
        }
        destination[destLength + i] = '\0';

        power( text, n-1,  destination);
    }
    
}
