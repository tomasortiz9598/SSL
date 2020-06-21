#include "string.h"

int getLength(char * text){
    int length = 0;
    char * copy;
    for (copy =text; *copy != '\0'; copy++)
        length++;
    return length;
}

int isEmpty(char * text){
    return *text=='\0';
}

char *strcat(char *text,  char *concat){
    int i,j;
    for (i = 0; text[i] != '\0'; i++)
        ;
    for (j = 0; concat[j] != '\0'; j++)
        text[i+j] = concat[j];
    text[i+j] = '\0';
    return text;
}

void power(char*text, int n){
    int length = getLength(text);
    text = (char*) realloc(text, length*(n-1)  );
    for (int i = 1; i < n; i++){
        text[length*i] = *text;
    }
}

int main(){
    char * text = "asd";
    printf("%d\n", getLength(text));
    return 0;
}