# Calculadora Infija.

## 1. Objetivos

* Experimentar el diseño de la especificación de lenguajes a nivel léxico y
sintáctico.
* Experimentar la implementación manual del nivel léxico y sintáctico de
lenguajes.

## 2. Temas

* Especificación del nivel Léxico y Sintáctico.
* Implementación del nivel Léxico y Sintáctico.
* Implementación de Scanner
* Implementación de Parser.
  
## 3. Problema

Análisis de expresiones aritméticas infijas simples que incluya:

* Números naturales con representación literal en base 10.
* Identificadores de variables.
* Adición.
* Multiplicación.

Ejemplos de expresiones correctas:

        A+2*3
        2*A+3
        A
        2

Ejemplos de expresiones incorrectas:

        +
        42+
        +A

## 4. Solución
Especificar e implementar los niveles léxicos y sintácticos del lenguaje.

## 5. Restricciones
* El scanner y el parser deben estar lógicamente separados.
* El parser se comunica con el scanner con la operación GetNextToken, el
scanner toma los caracteres de stdin con getchar.

### Crédito Extra
Estructurar la solución con separación física entre scanner
y parser.

## 6. Tareas
1. Diseñar el nivel léxico del lenguaje.
2. Diseñar el nivel sintáctico del lenguaje.
3. Implementar el scanner.
4. Implementar el parser.
5. Probar.
7. Productos

        DD-CalcInfManual
        46
        Productos
        |-- Calc.md
        |-- Makefile
        |-- Scanner.h // Opcional
        |-- Parser.h // Opcional
        |-- Parser.c // Opcional
        |-- Scanner.c // Opcional
        `-- Calc.c
