# C

El lenguaje C es un lenguaje de programacion de bajo nivel con capacidades de alto nivel, ampliamente utilizado para el desarrollo de sistemas operativos, control de hardware, y aplicaciones de alto rendimiento. Disenado por Dennis Ritchie en los anos 70, C sigue siendo fundamental en la informatica moderna debido a su eficiencia, flexibilidad y control detallado sobre los recursos del sistema.

## Caracteristicas Principales

### 1. Lenguaje de Bajo Nivel
C proporciona acceso directo al hardware, permitiendo operaciones a nivel de bits y manipulacion de registros de memoria. Esto lo convierte en una opcion ideal para programacion de sistemas y desarrollo de controladores.

### 2. Ausencia de Recoleccion de Basura
A diferencia de muchos lenguajes modernos, C no incluye un recolector de basura. Esto brinda a los desarrolladores control total sobre la asignacion y liberacion de memoria, pero tambien requiere una gestion manual cuidadosa para evitar fugas de memoria y errores.

### 3. Uso de Punteros
C destaca por su potente manejo de punteros, permitiendo:
- Acceso directo a direcciones de memoria.
- Manipulacion de estructuras complejas.
- Creacion y navegacion de estructuras de datos dinamicas como listas enlazadas, arboles y grafos.

### 4. Paradigma Procedimental
C adopta un paradigma de programacion estructurada o procedimental. Esto implica:
- Uso de funciones para dividir el codigo en modulos.
- Fomenta la reutilizacion y la legibilidad.

### 5. Portabilidad
El codigo en C puede compilarse en una amplia variedad de plataformas con cambios minimos o nulos. Esto lo convierte en una opcion comun para el desarrollo multiplataforma.

### 6. Bibliotecas Estandar
C cuenta con una rica biblioteca estandar que incluye:
- Manejo de entrada/salida.
- Manipulacion de cadenas y memoria.
- Operaciones matematicas y funciones de utilidad.
Estas bibliotecas proporcionan bloques fundamentales para el desarrollo de aplicaciones.

### 7. Tipado Estatico
C es un lenguaje con tipado estatico, lo que significa que los tipos de las variables deben ser definidos en tiempo de compilacion y no pueden cambiar durante la ejecucion. Esto permite una mayor eficiencia en la compilacion y ejecucion, pero requiere que los desarrolladores definan claramente las variables y sus tipos.

### 8. Compilado
C es un lenguaje compilado, lo que significa que el codigo fuente es transformado en codigo de maquina antes de ser ejecutado. Este proceso se realiza mediante un compilador que traduce el codigo a un archivo ejecutable.

### 9. Sintaxis y Declaracion de Funciones
En C, las funciones son declaradas especificando su tipo de retorno y los parametros. La sintaxis es sencilla pero rigurosa. Las funciones deben ser declaradas antes de ser utilizadas o bien definidas en archivos de cabecera (`.h`).

### 10. Palabras Claves
Algunas de las principales palabras clave en C son:
- `if`, `else`, `for`, `while`, `switch` (estructuras de control)
- `return`, `break`, `continue` (control de flujo)
- `void`, `struct`, `enum`, `typedef` (declaracion de tipos y estructuras)
- `sizeof`, `static`, `extern`, `const` (modificadores y operadores)
- **Manejo de Memoria:**
  - `malloc`, `free`, `calloc`, `realloc` (asignacion y liberacion de memoria dinamica)
  
### 11. Operadores
C soporta una amplia gama de operadores, incluyendo:
- `*`, `&` (operadores de punteros)
- `%` (operador de modulo)
- `+`, `-`, `*`, `/`, `=` (operadores aritmeticos y de asignacion)
- `==`, `!=`, `>`, `<`, `>=`, `<=` (operadores de comparacion)
- `&&`, `||` (operadores logicos)

### 12. Especificadores de Formato
Los especificadores de formato se usan para mostrar variables en la salida estandar. Algunos de los mas comunes son:
- `%d` para enteros.
- `%p` para punteros.
- `%s` para cadenas de caracteres.
- `%f` para numeros flotantes.

## Comparativa con otros lenguajes

| Caracteristica             | C             | Python       | Java        |
|----------------------------|---------------|--------------|-------------|
| Tipado                     | Estatico      | Dinamico     | Estatico    |
| Compilado/Interpretado      | Compilado     | Interpretado | Compilado   |
| Punteros                   | Si            | No           | No          |
| Paradigma                  | Procedimental | Multiparadigma| Orientado a objetos|
| Recoleccion de Basura      | No            | Si           | Si          |
| Sintaxis                   | Rigida        | Flexible     | Moderada    |
| Bibliotecas Estandar       | Si            | Si           | Si          |

