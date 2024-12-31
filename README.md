# C

El lenguaje de programacion C es uno de los lenguajes mas antiguos y populares que ha sido fundamental en el desarrollo de sistemas operativos, software embebido y aplicaciones de alto rendimiento. C es conocido por su simplicidad, eficiencia y control directo sobre el hardware, lo que lo convierte en una opcion ideal para aplicaciones de bajo nivel.

## Contexto

C fue desarrollado a principios de la decada de 1970 por Dennis Ritchie en los laboratorios Bell para crear el sistema operativo UNIX. Debido a su eficiencia y versatilidad, se ha utilizado ampliamente en el desarrollo de software para sistemas operativos, compiladores, juegos, y mas. Es considerado uno de los lenguajes base de la programacion moderna y es la base de muchos lenguajes actuales como C++, C#, y Objective-C.

## Usos

- **Desarrollo de sistemas operativos**: C es ampliamente utilizado para escribir sistemas operativos debido a su capacidad para interactuar directamente con el hardware y manipular memoria.
- **Programacion embebida**: Se usa en sistemas con recursos limitados, como dispositivos IoT, microcontroladores y hardware especifico.
- **Aplicaciones de alto rendimiento**: C es ideal para aplicaciones que requieren un alto rendimiento, como juegos, procesamiento de imagenes o software de simulacion.
- **Compiladores y herramientas**: Muchos compiladores y herramientas de desarrollo estan escritos en C debido a su eficiencia y control sobre los recursos del sistema.

## Paradigma de Programacion

C es un lenguaje **procedural**, lo que significa que se basa en la ejecucion secuencial de instrucciones o procedimientos (funciones) que manipulan datos. En el paradigma procedural, se enfoca en describir las acciones que el programa debe realizar para resolver un problema, en lugar de centrarse en los datos o las relaciones entre los datos. 

Aunque C es principalmente un lenguaje procedural, tambien permite trabajar con estructuras de datos mas complejas y ofrece un control detallado sobre la memoria y el hardware, lo que lo convierte en una herramienta poderosa en programacion de sistemas.

## Conceptos importantes

1. **Sintaxis**: C tiene una sintaxis simple que se basa en la notacion de llaves `{}` para definir bloques de codigo y punto y coma `;` para finalizar las instrucciones.
2. **Punteros**: Los punteros son una caracteristica clave en C, que permite la manipulacion directa de direcciones de memoria, esencial para la optimizacion de rendimiento y el acceso a recursos de bajo nivel.
3. **Funciones**: El lenguaje C es modular, lo que permite dividir el codigo en funciones reutilizables. Las funciones pueden recibir parametros y devolver valores.
4. **Estructuras**: Las estructuras permiten agrupar diferentes tipos de datos bajo un mismo nombre, lo que facilita la organizacion del codigo.
5. **Control de flujo**: C tiene estructuras de control como `if`, `while`, `for`, y `switch`, que permiten el flujo condicional y repetitivo del programa.

## Compiladores

C se puede compilar utilizando diferentes compiladores, que transforman el codigo fuente en codigo ejecutable. Algunos de los compiladores mas comunes son:

- **gcc (Ubuntu 13.2.0-23ubuntu4) 13.2.0**: Una de las implementaciones mas populares de C en sistemas basados en UNIX/Linux.
- **gcc (MinGW.org GCC-6.3.0-1) 6.3.0**: Version de GCC para sistemas Windows mediante MinGW.

## Compilar

Para compilar un programa en C, usa el siguiente comando:

```bash
gcc test.c -o test
```
## Ejecutar

```bash
./test
```
