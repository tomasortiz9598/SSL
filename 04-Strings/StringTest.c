#include"string.h"
#include <assert.h>

int main(){

    
    char *text = "hi";

    assert(getLength(text) ==2);
    assert(isEmpty(text) ==0);
    assert(isEmpty("") ==1);
    char prueba[9];
    power(text, 4, prueba);
    
    printf("%s\n", prueba );
    assert( strcmp(prueba,"hihihihi")==1);
    assert( strcmp(prueba,"hihihihiasd")==0);

    return 0;
}