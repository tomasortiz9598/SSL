
### 1. Nivel lexico

Para el nivel léxico se generó una máquina de estado y una gramática léxica, para identificar los tokens y lexemas válidos para el LP

Para la implementación del nivel léxico, se desarrollo un `Scanner`, que toma los caracteres del stdin con la función `getchar()`, y expone tokens válidos mediande la función `GetNextToken()`

### Maquina de Estado
![NivelLexico](./img/maquina.gv.svg)

**Categorias Lexicas**
- Constante.
- Identificador.
- Suma.
- Multiplicacion
- asignacion
- evaluacion

**Gramática léxica**
```
<token> ::=  <identificador> | <constante> | <suma> | <multiplicación> | <evaluacion> | <asignacion> 
<constante> ::= <dígito> | <constante> <dígito>
<dígito> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<identificador> ::= <letra> | <identificador> <letra>
<letra> ::= a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z
<suma> ::= +
<multiplicacion> ::= *
<asignacion> ::= =
<evaluacion> ::= $
```

### 2. Nivel sintactico

**Categorias Sintacticas**
- Programa
- listaSentencias
- sentencia
- Expresion
- Termino
- Factor

**Gramatica sintactica**
```
<programa> ::=  <listaSentencias> FDT
<listaSentencias> ::=  <sentencia> | <listaSentencias> <sentencia>
<sentencia> ::= <identificador> <asignacion> <constante>  |  <evaluacion> <expresión> 
<expresión> ::=  <término> | <expresión> <suma> <término>
<término> ::= <factor> |  <factor> <multiplicacion> <término>
<factor> ::= <constante> | <identificador> | ( <expresión> ) 
```