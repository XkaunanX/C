# Cola

Una **cola** es una estructura de datos que sigue el principio de **FIFO** (First In, First Out), lo que significa que el primer elemento en entrar es el primero en salir. Es similar a una fila en la vida real, como cuando haces cola para comprar algo o esperar tu turno en una caja.

## Estructura Interna de una Cola

La estructura de una cola generalmente esta formada por dos partes clave: los **punteros** y los **registros** que contienen los elementos de la cola. La implementacion interna puede variar dependiendo del tipo de cola, pero la mayoria de las implementaciones siguen una estructura similar.

### 1. **Punteros (Front y Rear)**

En una cola, los punteros son fundamentales para gestionar el acceso a los elementos de la cola de manera eficiente. Los dos punteros mas comunes son:

- **Front**: Este puntero señala el primer elemento de la cola (el que se encuentra en la "frente" de la cola). El elemento apuntado por el puntero `front` es el primero que se eliminara cuando se realice una operacion de **dequeue** (sacar un elemento de la cola).
  
- **Rear (o Tail)**: Este puntero señala el ultimo elemento de la cola (el "final" de la cola). El elemento apuntado por el puntero `rear` es donde se agregara un nuevo elemento cuando se realice una operacion de **enqueue** (agregar un elemento a la cola).

Estos dos punteros son esenciales para mantener el orden y la integridad de la cola, asegurando que los elementos se procesen en el orden adecuado.

### 2. **Registros de Datos (Elementos de la Cola)**

El contenido de la cola se almacena en registros o nodos. Estos registros son las unidades de datos que contienen el valor de los elementos que se encuentran en la cola. Dependiendo de la implementacion, estos registros pueden almacenarse en diferentes estructuras:

- **En una cola implementada con un arreglo**: Los elementos de la cola se almacenan en las posiciones del arreglo. El puntero `front` indicara la posicion del primer elemento, y el puntero `rear` indicara la ultima posicion ocupada.
  
- **En una cola implementada con una lista enlazada**: Los elementos se almacenan en nodos individuales, y cada nodo contiene un valor y un puntero al siguiente nodo. En este caso, el puntero `front` apunta al primer nodo, y el puntero `rear` apunta al ultimo nodo. Cuando se agrega un nuevo elemento, el puntero del ultimo nodo se actualiza para apuntar al nuevo nodo.

### 3. **Operaciones Internas**

Las operaciones de las colas dependen de como se manipulan los punteros y los registros:

- **Enqueue (agregar un elemento)**: Cuando se agrega un elemento a la cola, se coloca en la posicion indicada por el puntero `rear`. Si la cola esta implementada con una lista enlazada, el puntero `rear` se actualiza para apuntar al nuevo nodo que contiene el elemento agregado. Si esta implementada con un arreglo, el elemento se coloca en el indice correspondiente y el puntero `rear` se mueve a la siguiente posicion disponible.

- **Dequeue (eliminar un elemento)**: Cuando se elimina un elemento de la cola, el elemento apuntado por el puntero `front` es removido, y el puntero `front` se mueve hacia el siguiente elemento de la cola. Esto garantiza que el elemento mas antiguo (el primero en entrar) sea el primero en salir.

### 4. **Ciclo en Colas Circulares**

En algunas implementaciones, especialmente en **colas circulares**, el espacio de almacenamiento de la cola se organiza de manera que el `rear` y el `front` pueden "dar la vuelta" cuando alcanzan el final del arreglo o la lista. En una cola circular:

- Cuando el puntero `rear` llega al final del arreglo o lista, se mueve de nuevo al principio (esto sucede de forma circular).
- Esto permite que se aproveche mejor el espacio, ya que una vez que los elementos son removidos de la cola, ese espacio puede ser reutilizado.

### 5. **Tamaño de la Cola**

En algunas implementaciones, es importante llevar un registro del **tamaño** de la cola para evitar errores, como intentar eliminar un elemento de una cola vacia o agregar un elemento a una cola llena (en el caso de colas con un tamaño fijo). Esto se puede hacer mediante una variable que mantenga el numero de elementos actuales en la cola.

### Resumen

En resumen, la estructura interna de una cola generalmente involucra:

- **Punteros** (front y rear) para gestionar el acceso al primer y ultimo elemento de la cola.
- **Registros de datos** (elementos) que se almacenan en una estructura subyacente (arreglo o lista enlazada).
- En colas **circulares**, los punteros se "envuelven" para reutilizar el espacio de manera eficiente.

Esta estructura es clave para mantener el orden de los elementos en la cola y garantizar que las operaciones se realicen de acuerdo con el principio FIFO.

## Caracteristicas Principales

- **FIFO**: La caracteristica clave de una cola es que el primer elemento insertado es el primero en ser removido.
- **Operaciones**: Las operaciones basicas que se realizan en una cola son:
  - **Enqueue (insertar)**: Agregar un nuevo elemento al final de la cola.
  - **Dequeue (eliminar)**: Eliminar el primer elemento de la cola.
  - **Peek (ver el frente)**: Ver el primer elemento de la cola sin eliminarlo.
  - **isEmpty (verificar si esta vacia)**: Verificar si la cola no tiene elementos.
  - **size (tamaño)**: Obtener el numero de elementos en la cola.

## Aplicaciones de la Cola

Las colas se utilizan ampliamente en muchos algoritmos y sistemas, como:

- **Procesamiento de tareas**: En sistemas operativos y servidores, las colas se utilizan para gestionar y procesar tareas o solicitudes de manera ordenada.
- **Simulacion de eventos**: En simulaciones de sistemas como lineas de espera, colas para la atencion de clientes, etc.
- **Control de flujo**: En comunicaciones y redes, las colas son fundamentales para el control de paquetes de datos o mensajes.
- **Algoritmos de busqueda**: En estructuras de datos como el algoritmo de busqueda en anchura (BFS) en grafos.

## Tipos de Colas

Existen variaciones de la cola que permiten adaptarse mejor a diferentes necesidades, como:

- **Colas de Prioridad**: Permiten asignar una prioridad a cada elemento, asegurando que los elementos con mayor prioridad sean procesados antes que los de menor prioridad.
- **Colas Dobladas (Deque)**: Permiten la insercion y eliminacion de elementos en ambos extremos (frente y final).
- **Colas Circulares**: Se utilizan cuando el espacio de almacenamiento es limitado y se desea reutilizar el espacio de manera eficiente.
