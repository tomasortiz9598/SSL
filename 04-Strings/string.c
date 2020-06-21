#include "string.h"

int getLength(char * text){
    int length = 0;
    char * copy;
    for (copy =text; *copy != '\0'; copy++)
        length++;
    return length;
}

int isEmpty( char * text){
    return *text=='\0';
}
int strcmp(char* first_text, char*second_text){
    if(getLength(first_text) !=getLength(second_text))
        return 0;
    for (int i = 0; i <= getLength(first_text); i++)
        if(first_text[i]!=second_text[i])
            return 0;
    return 1;
}
void power( char*text, int n, char destination[]){
    int length = getLength(text);
    for (int i = 0; i < length*n; i++){
        destination[i] = text[i%length];
    }
    destination[length*n] = '\0';
}
