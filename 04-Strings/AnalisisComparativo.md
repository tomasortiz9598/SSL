
|     | C                                                                  | Python                                                                       |
| --- | ------------------------------------------------------------------ | ---------------------------------------------------------------------------- |
| A   | A nivel semantico es una secuencia de caracteres                   | El tipo de dato pertenece al lenguaje y                                      |
|     | independientes     Ej:  ["h", "o", "l", "a"]                       | contiene operaciones propias del string como "string".upper()                |
| B   | No hay tipo de dato String, sino un array de chars                 | Existe el String como tipo de dato pero tiene un funcionamiento              |
|     | Se puede importar string.h para tener funciones de cadenas de char | parecido al array de chars,  se incluyen algunas operaciones                 |
|     |                                                                    | mas                                                                          |
| C   | a..z A..Z 0..9 y simbolos                                          | Idem c + caracteres Unicode                                                  |
| D   | Se almacena el puntero al primer elemento de la cadena             | Internamente se almacena la direccion de memoria del objeto string pero como |
|     |                                                                    | programadores no operamos con el puntero sino directamente con el string, el |
|     |                                                                    | lenguaje nos provee de esta abstraccion                                      |
| E   | Al ser una cadena sus componentes son mutables                     | Inmutable. Cada vez que modificamos un string crea en memoria                |
|     |                                                                    | una nueva instancia del objeto con el  nuevo resultado                       |
| F   | La cadena no es FCC                                                | El string si                                                                 |
| G   | Se pasa la direccion del primer elemento del array                 | Se pasa el string directamente                                               |
| H   | Se retorna la direccion de primer elemento del array               | Se retorna la el string directamente                                         |