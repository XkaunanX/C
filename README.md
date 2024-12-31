# Miscelaneo

Este repositorio contiene ejemplos y explicaciones de temas avanzados en programacion en C. Cada seccion cubre un concepto clave y su aplicacion para desarrollar programas eficientes y funcionales.

## Contenido

1. **Pasar Argumentos a Scripts en C**  
   Los programas en C pueden recibir argumentos desde la linea de comandos mediante los parametros `argc` (contador de argumentos) y `argv` (vector de argumentos). Esto permite personalizar el comportamiento del programa en tiempo de ejecucion.

2. **Aritmetica de Punteros**  
   La aritmetica de punteros permite realizar operaciones como suma y resta sobre direcciones de memoria. Esto es util para navegar por arrays y estructuras de datos contiguas en memoria.

3. **Cast (Conversion de Tipos)**  
   El casting permite convertir valores de un tipo de dato a otro, ya sea de forma implicita o explicita. Es comunmente usado para interpretar datos en estructuras de bajo nivel o ajustar tipos en operaciones aritmeticas.

4. **Operador Ternario (`? :`)**  
   El operador ternario es una forma concisa de escribir condiciones. Se utiliza para evaluar una expresion y devolver uno de dos valores segun el resultado.

5. **Enumeraciones (Enums)**  
   Las enumeraciones son tipos de datos definidos por el usuario que asignan nombres simbolicos a valores enteros, mejorando la legibilidad del codigo y su mantenimiento.

6. **`extern`**  
   La palabra clave `extern` se utiliza para declarar variables o funciones que son definidas en otros archivos, permitiendo la vinculacion entre modulos de un programa.

7. **Manejo de Fechas**  
   C proporciona la biblioteca `<time.h>` para trabajar con fechas y horas. Incluye funciones para obtener la fecha actual, calcular diferencias entre fechas y formatear datos temporales.

8. **`goto`**  
   El `goto` permite saltar a una etiqueta especifica en el codigo. Aunque es poderoso, debe usarse con cuidado para evitar complicaciones en la lectura y mantenimiento del codigo.

9. **Funciones `inline`**  
   Las funciones `inline` sugieren al compilador insertar el codigo de la funcion directamente en lugar de realizar una llamada. Esto puede mejorar el rendimiento en funciones pequeñas y frecuentemente usadas.

10. **Generacion de Numeros Aleatorios**  
    Con la biblioteca `<stdlib.h>`, se pueden generar numeros pseudoaleatorios usando las funciones `rand()` y `srand()` para inicializar la semilla.

11. **Recursividad**  
    La recursividad es una tecnica donde una funcion se llama a si misma para resolver problemas que pueden dividirse en subproblemas similares. Es util en algoritmos como busquedas y ordenamientos.

12. **Restriccion `restrict`**  
    El calificativo `restrict` informa al compilador que un puntero es el unico medio para acceder a un bloque de memoria, permitiendo optimizaciones en operaciones intensivas.

13. **Uniones (`union`)**  
    Una union es una estructura de datos que permite almacenar diferentes tipos en la misma ubicacion de memoria. Es util para ahorrar espacio y para interpretaciones de datos de bajo nivel.
