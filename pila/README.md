# Pila

Una **pila** es una estructura de datos que sigue el principio **LIFO** (Last In, First Out), lo que significa que el ultimo elemento en ser agregado es el primero en ser eliminado. Este comportamiento es similar a una pila de platos: el ultimo plato colocado en la cima es el primero en ser retirado.

## Punteros en la Pila

La pila se implementa usando **punteros** en C. El puntero **`tope`** (o **`cabeza`**) apunta al **ultimo nodo** de la pila. Este nodo contiene los datos y un puntero al siguiente nodo de la pila. El puntero al siguiente nodo permite que cada nodo "apunte" al siguiente, formando una cadena.

Cuando se realiza una operacion de **push**, se crea un nuevo nodo que apunta al nodo que estaba previamente en el tope. De esta manera, el nuevo nodo se convierte en el nuevo **tope** de la pila. Al realizar una operacion de **pop**, simplemente se mueve el puntero **`tope`** al siguiente nodo, eliminando el nodo superior de la pila.

## Logica en la vida real

Piensa en una pila de libros. Cuando pones un nuevo libro en la cima, lo colocas sobre el anterior, y cuando necesitas un libro, tomas el que esta en la cima. En una pila de computacion, el ultimo libro (dato) agregado sera el primero en ser retirado.

## Resumen

- **Pila**: Estructura LIFO.
- **Puntero tope**: Apunta al ultimo nodo insertado.
- **Operaciones**: Push (insertar), Pop (eliminar), Peek (consultar).
- **Punteros**: Permiten una gestion eficiente de la memoria y las operaciones.

La pila es util en situaciones donde necesitamos procesar los elementos en orden inverso al que fueron agregados, como en el manejo de funciones recursivas o la reversion de acciones en programas.

# Tipos de pilas

## Pila LIFO (Last In, First Out)

La **pila LIFO** es la forma basica de pila y sigue estrictamente el principio **Last In, First Out**, donde el ultimo elemento insertado es el primero en ser eliminado.

### Caracteristicas:
- **Orden**: El acceso y la eliminacion de los elementos solo se puede realizar desde el **tope** de la pila.
- **Operaciones principales**: `push` (insertar), `pop` (eliminar), `peek` (ver el tope).
- **Uso comun**: Algoritmos de retroceso, como el recorrido en profundidad de grafos y el analisis de expresiones matematicas.

### Ventajas:
- **Simplicidad**: Es facil de implementar y muy eficiente para problemas que requieren un acceso LIFO.

## Pila Reversible

Una **pila reversible** es una pila que permite invertir el orden de los elementos, es decir, puedes recorrerla desde el ultimo elemento hasta el primero o viceversa.

### Caracteristicas:
- **Acceso bidireccional**: Permite recorrer los elementos desde el ultimo hasta el primero (como una pila normal) o desde el primero hasta el ultimo (de manera inversa).
- **Operaciones adicionales**: Algunas implementaciones pueden ofrecer una operacion para revertir la pila.
- **Implementacion**: Puede requerir el uso de una lista doblemente enlazada o una estructura auxiliar para realizar la inversion.

### Uso comun:
- Procesamiento de datos que necesitan ser recorridos en ambas direcciones.
- Implementacion de algoritmos que requieren tanto un acceso secuencial como reverso a los elementos.

## Pila de Prioridad

Una **pila de prioridad** es una variacion de la pila estandar en la que cada elemento tiene una prioridad asociada. Los elementos con mayor prioridad son atendidos antes que los de menor prioridad, sin seguir el principio LIFO tradicional.

### Caracteristicas:
- **Prioridad**: Cada elemento tiene una prioridad, y el elemento con la mayor prioridad es el primero en ser extraido.
- **Operaciones principales**: `insertar` (insertar con prioridad), `extraer` (extraer el elemento con mayor prioridad).
- **Implementacion**: Se puede implementar usando una estructura de datos como un heap o una lista ordenada.

### Uso comun:
- Sistemas que requieren la ejecucion de tareas segun su urgencia (como en la planificacion de procesos de un sistema operativo).
- Algoritmos como Dijkstra para encontrar el camino mas corto en un grafo.

## Pila Multiple

Una **pila multiple** es una estructura que permite tener varias pilas independientes en una sola estructura de datos.

### Caracteristicas:
- **Varias pilas**: Permite manejar multiples pilas dentro de una sola estructura, generalmente con un indice o identificador para cada pila.
- **Operaciones**: Las pilas pueden ser manejadas de manera independiente, pero todas pertenecen a la misma estructura.
- **Implementacion**: Puede implementarse mediante una estructura de array de pilas o una lista enlazada con punteros adicionales.

### Uso comun:
- Gestion de multiples tareas en paralelo o simulacion de multiples pilas en un sistema de procesamiento.
- Aplicaciones que requieren multiples pilas de manera eficiente, como en la simulacion de memoria compartida.

## Pila Circular

Una **pila circular** es una variante de la pila que, al igual que la lista circular, hace que el ultimo elemento este conectado al primero, creando un ciclo. Esto permite reutilizar espacio cuando la pila alcanza su limite de capacidad.

### Caracteristicas:
- **Ciclo**: El ultimo elemento de la pila apunta de nuevo al primero, lo que hace que no haya desperdicio de espacio cuando la pila esta llena.
- **Implementacion**: Usualmente se implementa mediante un arreglo que contiene punteros al primer y ultimo elemento de la pila.
- **Ventaja**: Evita el desbordamiento de la pila al aprovechar el espacio no utilizado despues de eliminar elementos.

### Uso comun:
- Implementacion de buffers circulares, donde los datos se reciclan continuamente.
- Aplicaciones donde se debe asegurar el uso eficiente del espacio, como en estructuras de datos de tipo "stack" con tamaño fijo.

## Comparacion de Tipos de Pilas

| **Tipo de Pila**           | **Caracteristicas Clave**                                  | **Uso Comun**                                              |
|----------------------------|------------------------------------------------------------|------------------------------------------------------------|
| **Pila LIFO**              | Sigue el principio Last In, First Out (LIFO).              | Algoritmos de retroceso, como recorrido de grafos y parsing de expresiones. |
| **Pila Reversible**        | Permite recorrer los elementos en ambas direcciones.       | Procesamiento de datos que requieren recorridos bidireccionales. |
| **Pila de Prioridad**      | Los elementos tienen una prioridad asociada.               | Planificacion de tareas, algoritmos de busqueda de caminos. |
| **Pila Multiple**          | Maneja varias pilas independientes dentro de una estructura. | Simulacion de procesos en paralelo, gestion de memoria compartida. |
| **Pila Circular**          | El ultimo elemento apunta al primero, formando un ciclo.   | Buffers circulares, optimizacion de espacio en estructuras de datos de tamaño fijo. |
