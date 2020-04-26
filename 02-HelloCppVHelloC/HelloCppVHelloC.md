# C vs C++

### C

```C
#include <stdio.h>
int main(){
    printf("Hola Mundo");   
}
```


### C++

```C++
#include <iostream>
using namespace std;
int main() {
    cout << "Hola Mundo";

}
```


|            |             | C++                                                 | C                                         |
| ---------- | ----------- | --------------------------------------------------- | ----------------------------------------- |
| Léxico     | Diferencias | **cout<<** "Hola Mundo" && **using namespace std;** | **printf**("Hola Mundo") **stdio.h**      |
|            |             | &&    **iostream**                                  |                                           |
|            | Similitudes | El resto de simbolos que usan son iguales           | El resto de simbolos que usan son iguales |
| Sintáctico | Diferencias | No hay diferencias                                  | No hay diferencias                        |
|            | Similitudes | Son similares                                       | Son similares                             |
| Semántico  | Diferencias | Se redirige el string                               | Se llama a la función **printf()**        |
|            | Similitudes | El resto de simbolos son iguales                    | El resto de simbolos son iguales          |