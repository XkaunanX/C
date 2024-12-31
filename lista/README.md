# Lista Enlazada

Una **lista enlazada** es una estructura de datos que consiste en una secuencia de nodos. Cada nodo contiene un **dato** y un **puntero** (o referencia) al siguiente nodo en la lista. A diferencia de los arrays, la lista enlazada no tiene un tamaño fijo, y los elementos no estan almacenados de manera contigua en la memoria, sino que se enlazan entre si mediante los punteros.

## Estructura de la Lista Enlazada

La lista enlazada se maneja con los siguientes punteros importantes:

- **`cabeza`**: Apunta al primer nodo de la lista. Si la lista esta vacia, este puntero es `NULL`.
- **`final`**: Apunta al ultimo nodo de la lista. Si la lista esta vacia, tambien es `NULL`.

Cada **nodo** tiene dos componentes principales:
- **`Dato`**: Almacena la informacion que representa el nodo (en este caso, un valor de tipo `int` y un `id` unico).
- **`siguiente`**: Es un puntero que apunta al siguiente nodo en la lista. Si es el ultimo nodo, este puntero es `NULL`.

## Operaciones Principales

### 1. **Insertar Nodo**
   - Se agrega un nuevo nodo al final de la lista.
   - Si la lista esta vacia, el primer nodo sera tanto el `cabeza` como el `final`.
   - El puntero `final` se actualiza para que apunte al nuevo nodo.

### 2. **Eliminar Nodo**
   - Se recorre la lista para encontrar el nodo con el `id` especificado.
   - Una vez encontrado, el nodo se elimina y el puntero del nodo anterior se actualiza para que apunte al siguiente nodo.
   - Si el nodo eliminado es el ultimo, el puntero `final` se actualiza para que apunte al nodo anterior.

### 3. **Modificar Nodo**
   - Se recorre la lista para encontrar el nodo con el `id` especificado y se cambia su valor.

### 4. **Consultar Nodo**
   - Se recorre la lista para encontrar el nodo con el `id` especificado.
   - Si se encuentra el nodo, se puede consultar su valor.

## Logica de la Lista Enlazada

Imagina una lista de personas donde cada persona tiene un telefono y un nombre. En vez de almacenar todos los datos de forma contigua, cada persona tiene un enlace (puntero) al siguiente en la lista. Para acceder a alguien, empezamos desde el principio (desde la cabeza de la lista) y seguimos los enlaces hasta llegar a la persona deseada.

La lista enlazada es util para aplicaciones que requieren operaciones frecuentes de insercion y eliminacion, ya que estas operaciones pueden hacerse de manera mas eficiente que en un array.

# Tipos de listas

## Lista Simplemente Enlazada

Una **lista simplemente enlazada** es una estructura de datos donde cada elemento (nodo) contiene un valor y un puntero (o enlace) al siguiente nodo en la lista.

### Caracteristicas:
- **Nodo**: Cada nodo contiene un valor y un puntero al siguiente nodo.
- **Unidireccional**: El acceso a los elementos solo puede realizarse de forma secuencial, desde el primer nodo hasta el ultimo.
- **Ventajas**: Facil de implementar y tiene una estructura sencilla.
- **Desventajas**: No permite el acceso aleatorio a los elementos.

### Uso comun:
- Implementaciones basicas de listas y colas.
- Almacenamiento dinamico de elementos cuando no es necesario acceder a ellos rapidamente.

---

## Lista de Prioridad

Una **lista de prioridad** es una estructura de datos similar a una cola, donde los elementos tienen una prioridad asociada. Los elementos con mayor prioridad son atendidos antes que los de menor prioridad.

### Caracteristicas:
- **Prioridad**: Cada elemento tiene un valor de prioridad, que determina el orden de acceso.
- **Acceso**: Los elementos de mayor prioridad se extraen primero, independientemente de su orden de insercion.
- **Implementacion comun**: Puede implementarse con una cola o mediante un heap (monticulo).

### Uso comun:
- Algoritmos de planificacion de tareas (como en sistemas operativos).
- Gestion de eventos en simulaciones o sistemas de redes.

---

## Lista Reversible

Una **lista reversible** es una lista que permite recorrerla tanto de manera normal (del primer al ultimo nodo) como en reversa (del ultimo al primero).

### Caracteristicas:
- **Doble recorrido**: Se puede recorrer en ambas direcciones.
- **Implementacion**: Se puede implementar con una lista doblemente enlazada.
- **Ventajas**: Permite flexibilidad en el acceso a los elementos.

### Uso comun:
- Representacion de estructuras que necesitan ser recorridas en ambas direcciones, como en la implementacion de undo/redo.

---

## Lista de Punteros

Una **lista de punteros** es una lista donde los elementos son punteros a otros elementos o estructuras, en lugar de almacenar los datos directamente.

### Caracteristicas:
- **Punteros**: Los nodos de la lista contienen punteros a otros objetos o estructuras, lo que permite una mayor flexibilidad en el almacenamiento.
- **Acceso dinamico**: Es posible almacenar diferentes tipos de datos o incluso estructuras mas complejas.
  
### Uso comun:
- Listas que contienen estructuras complejas o variables de diferentes tipos.

---

## Lista de Listas

Una **lista de listas** es una lista cuyo cada elemento es otra lista, permitiendo representar colecciones jerarquicas o multidimensionales.

### Caracteristicas:
- **Jerarquia**: Cada nodo puede apuntar a una lista que a su vez contiene mas elementos.
- **Flexibilidad**: Permite representar datos complejos, como matrices o colecciones anidadas.
  
### Uso comun:
- Representacion de matrices o tablas multidimensionales.
- Implementacion de estructuras como grafos o tablas de hash.

---

## Lista de Arrays

Una **lista de arrays** es una estructura en la que cada elemento es un array. Esto permite almacenar multiples elementos en un solo nodo.

### Caracteristicas:
- **Array interno**: Cada nodo contiene un array de tamaño fijo.
- **Acceso rapido**: Permite acceder a los elementos del array de forma eficiente.
  
### Uso comun:
- Almacenamiento de datos en bloques fijos.
- Cuando se necesita un conjunto de datos que crezca de forma dinamica, pero se desea tener el control sobre el tamaño de los bloques.

---

## Lista de Insertado Ordenado

Una **lista de insertado ordenado** es una lista que mantiene sus elementos siempre ordenados. Cuando se inserta un nuevo elemento, la lista se reorganiza para mantener el orden.

### Caracteristicas:
- **Ordenamiento**: Los elementos se mantienen en orden despues de cada insercion.
- **Insercion eficiente**: La insercion de nuevos elementos puede ser mas lenta que en una lista no ordenada, ya que se debe mantener el orden.

### Uso comun:
- Aplicaciones que requieren una lista ordenada en todo momento, como listas de elementos clasificados por prioridad o fecha.

---

## Lista Doblemente Enlazada

Una **lista doblemente enlazada** es una lista en la que cada nodo contiene dos punteros: uno al siguiente nodo y otro al nodo anterior.

### Caracteristicas:
- **Bidireccional**: Permite recorrer la lista en ambas direcciones.
- **Mas compleja**: Requiere mas memoria debido a los punteros adicionales.
  
### Uso comun:
- Implementacion de estructuras de datos mas complejas, como pilas o colas dobles.
- Navegacion en aplicaciones donde se requiere la posibilidad de movernos hacia adelante y hacia atras, como en navegadores web.

---

## Lista Circular

Una **lista circular** es una lista cuyo ultimo nodo apunta al primer nodo, creando un ciclo continuo de nodos.

### Caracteristicas:
- **Ciclo**: El ultimo nodo de la lista apunta de nuevo al primer nodo, formando un ciclo.
- **Uso eficiente**: No es necesario mantener un puntero separado al primer o ultimo nodo, ya que ambos estan conectados.
  
### Uso comun:
- Implementacion de estructuras como las colas circulares en sistemas de procesamiento de eventos o tareas.
  
---

## Lista Circular Doblemente Enlazada

Una **lista circular doblemente enlazada** es una combinacion de una lista circular y una lista doblemente enlazada. En ella, cada nodo tiene punteros tanto al nodo anterior como al siguiente, y el ultimo nodo apunta de nuevo al primero.

### Caracteristicas:
- **Bidireccional y ciclica**: Permite recorrer la lista en ambas direcciones, y el ultimo nodo apunta de nuevo al primero.
- **Ventaja**: Ofrece flexibilidad y eficiencia para navegar en ambos sentidos en un ciclo continuo.

### Uso comun:
- Aplicaciones que requieren una navegacion eficiente en ambas direcciones de manera continua, como en la gestion de buffers circulares.

---

## Comparacion de Tipos de Listas

| **Tipo de Lista**                | **Caracteristicas Clave**                        | **Uso Comun**                               |
|-----------------------------------|--------------------------------------------------|---------------------------------------------|
| **Lista Simplemente Enlazada**    | Cada nodo tiene un puntero al siguiente nodo.    | Implementaciones basicas de listas.         |
| **Lista de Prioridad**            | Elementos con prioridades, accesados segun su valor. | Planificacion de tareas, algoritmos de busqueda. |
| **Lista Reversible**              | Permite recorrerla en ambas direcciones.        | Aplicaciones con necesidades de deshacer/rehacer. |
| **Lista de Punteros**             | Almacena punteros a otros objetos o estructuras. | Listas de estructuras complejas.            |
| **Lista de Listas**               | Cada nodo es otra lista.                        | Representacion de datos multidimensionales. |
| **Lista de Arrays**               | Cada nodo contiene un array.                    | Almacenamiento de bloques de datos.         |
| **Lista de Insertado Ordenado**   | Mantiene el orden de los elementos.             | Listas que requieren mantener el orden.    |
| **Lista Doblemente Enlazada**     | Cada nodo tiene punteros al siguiente y anterior. | Pilas, colas, estructuras jerarquicas.     |
| **Lista Circular**                | El ultimo nodo apunta al primero, formando un ciclo. | Implementacion de colas circulares.        |
| **Lista Circular Doblemente Enlazada** | Combina caracteristicas de listas circulares y doblemente enlazadas. | Navegacion continua bidireccional eficiente. |
