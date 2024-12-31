# Grafo

Un **grafo** es una estructura de datos que se utiliza para representar relaciones entre elementos. Esta compuesto por:

- **Nodos (Vertices)**: Representan los elementos que estan siendo conectados o relacionados.
- **Aristas (Enlaces)**: Representan las conexiones entre los nodos, indicando que existe una relacion entre ellos.

En el contexto de este proyecto, estamos trabajando con un **grafo dirigido**, lo que significa que las aristas tienen una direccion, es decir, una arista va de un nodo a otro.

## Componentes de la Estructura de Datos

La estructura de datos utilizada consta de varias partes:

### Nodo

Cada nodo en el grafo contiene los siguientes elementos:

- **ID**: Un identificador unico para cada nodo, utilizado para referenciarlo en el grafo.
- **Valor**: Un valor asociado al nodo que puede representar cualquier tipo de informacion relevante (en este caso, un numero aleatorio generado al insertar el nodo).
- **Aristas (adyacentes)**: Una lista de aristas que conectan el nodo con otros nodos en el grafo.

### Arista

Las aristas son las conexiones entre los nodos y tienen los siguientes elementos:

- **Destino**: El nodo al que la arista lleva.
- **Siguiente**: Un puntero que apunta a la siguiente arista, permitiendo que cada nodo tenga multiples conexiones (es decir, aristas dirigidas a otros nodos).

### Grafo

El grafo en si esta compuesto por:

- **Cabeza**: El primer nodo del grafo (puede considerarse el "nodo raiz" o punto de inicio).
- **Numero de nodos**: Un contador de la cantidad total de nodos en el grafo.

## Operaciones sobre el Grafo

El programa permite realizar diversas operaciones sobre el grafo, las cuales incluyen:

- **Insertar Nodo**: Añadir un nuevo nodo al grafo.
- **Eliminar Nodo**: Eliminar un nodo existente y todas las conexiones asociadas a el.
- **Modificar Nodo**: Cambiar el valor de un nodo ya existente.
- **Insertar Arista**: Crear una conexion entre dos nodos.
- **Eliminar Arista**: Eliminar una conexion entre dos nodos.
- **Consultar Nodo**: Ver la informacion de un nodo especifico.
- **Imprimir Grafo**: Mostrar todos los nodos y sus conexiones.

# Representacion de Grafos: Matriz de Adyacencia vs. Lista de Adyacencia

Este documento explica las dos principales formas de representar un grafo: **matriz de adyacencia** y **lista de adyacencia**. Ambas estructuras tienen sus ventajas y desventajas, y son utilizadas dependiendo del tipo de grafo y las necesidades de eficiencia.

## 1. Matriz de Adyacencia

Una **matriz de adyacencia** es una representacion del grafo utilizando una matriz bidimensional. En esta matriz, las filas y las columnas corresponden a los nodos del grafo, y las celdas de la matriz indican si existe o no una arista entre los nodos.

### Caracteristicas:
- Es una **matriz cuadrada** de tamaño \(N \times N\), donde \(N\) es el numero de nodos del grafo.
- Si hay una arista entre el nodo \(i\) y el nodo \(j\), el valor en la posicion \(A[i][j]\) es distinto de cero (comunmente 1 en grafos no ponderados). Si no hay arista, el valor es cero.
- **Grafos dirigidos**: La matriz no sera simetrica. Si hay una arista de \(i\) a \(j\), pero no de \(j\) a \(i\), el valor de la celda sera diferente entre \(A[i][j]\) y \(A[j][i]\).
- **Grafos no dirigidos**: La matriz es simetrica, ya que si hay una arista de \(i\) a \(j\), tambien hay una de \(j\) a \(i\).

### Ejemplo de Matriz de Adyacencia (Grafo no dirigido):

Considerando un grafo con 4 nodos y las siguientes aristas:
- Nodo 1 esta conectado con Nodo 2.
- Nodo 2 esta conectado con Nodo 3.
- Nodo 3 esta conectado con Nodo 4.
- Nodo 4 esta conectado con Nodo 1.

La matriz de adyacencia seria:

1   2   3   4
1 [ 0 1 0 1 ] 2 [ 1 0 1 0 ] 3 [ 0 1 0 1 ] 4 [ 1 0 1 0 ]

### Ventajas:
- **Acceso rapido**: Permite verificar si existe una arista entre dos nodos en tiempo \(O(1)\).
  
### Desventajas:
- **Uso ineficiente de espacio**: Requiere \(O(N^2)\) espacio, lo cual puede ser un problema en grafos grandes y dispersos.
- **Ineficiencia en grafos dispersos**: Si el grafo tiene pocas aristas, se desperdicia mucha memoria.

## 2. Lista de Adyacencia

Una **lista de adyacencia** es una representacion en la que cada nodo tiene una lista que contiene los nodos a los que esta conectado directamente. Se usa una estructura de lista o array de listas para cada nodo del grafo.

### Caracteristicas:
- Cada nodo tiene una lista de sus nodos adyacentes (los nodos a los que esta conectado).
- Para **grafos dirigidos**, si existe una arista de \(i\) a \(j\), solo el nodo \(i\) tendra a \(j\) en su lista de adyacencia.
- Para **grafos no dirigidos**, si existe una arista de \(i\) a \(j\), ambos nodos tendran en su lista de adyacencia al otro nodo.

### Ejemplo de Lista de Adyacencia (Grafo no dirigido):

Considerando el mismo grafo que en el ejemplo de la matriz de adyacencia:

- Nodo 1 esta conectado con Nodo 2 y Nodo 4.
- Nodo 2 esta conectado con Nodo 1 y Nodo 3.
- Nodo 3 esta conectado con Nodo 2 y Nodo 4.
- Nodo 4 esta conectado con Nodo 1 y Nodo 3.

La lista de adyacencia seria:

1: [2, 4] 2: [1, 3] 3: [2, 4] 4: [1, 3]

### Ventajas:
- **Uso eficiente de espacio**: Utiliza \(O(N + M)\) espacio, donde \(N\) es el numero de nodos y \(M\) el numero de aristas.
- **Eficiencia en grafos dispersos**: Es mas eficiente en terminos de espacio para grafos con pocas aristas.

### Desventajas:
- **Acceso mas lento**: Para verificar si existe una arista entre dos nodos, es necesario recorrer la lista de adyacencia, lo que tiene un costo de \(O(k)\), donde \(k\) es el numero de adyacentes de un nodo.

## 3. Comparacion

| **Caracteristica**              | **Matriz de Adyacencia**               | **Lista de Adyacencia**                |
|----------------------------------|----------------------------------------|----------------------------------------|
| **Espacio**                      | \(O(N^2)\)                             | \(O(N + M)\)                           |
| **Acceso a aristas**            | \(O(1)\)                               | \(O(k)\), donde \(k\) es el numero de adyacentes |
| **Eficiencia en grafos dispersos**| Baja                                   | Alta                                   |
| **Simplicidad**                  | Facil de implementar                   | Requiere manejo de listas/estructuras  |
| **Ideal para**                   | Grafos densos                          | Grafos dispersos                       |

## 4. Conclusion

- **Matriz de adyacencia**: Es util para grafos pequeños o densos, donde las conexiones entre nodos son frecuentes. Permite un acceso rapido a las aristas, pero no es eficiente en terminos de memoria para grafos grandes o dispersos.
  
- **Lista de adyacencia**: Es mas eficiente en terminos de espacio y es ideal para grafos dispersos, donde hay muchos menos enlaces que nodos. Sin embargo, el acceso a las aristas no es tan rapido como en la matriz de adyacencia.

# Tipos de grafos

## Grafo Ponderado

Un **grafo ponderado** es un grafo en el que cada arista tiene un valor o peso asociado. Este valor puede representar, por ejemplo, la distancia, el costo, el tiempo o cualquier otra metrica que relacione los vertices conectados por la arista.

### Caracteristicas:
- **Vertices**: Los nodos del grafo.
- **Aristas**: Las conexiones entre los vertices, cada una con un peso asociado.
- **Uso comun**: Se utilizan en algoritmos de optimizacion como el calculo de caminos mas cortos (por ejemplo, el algoritmo de Dijkstra o el algoritmo de Bellman-Ford).

## Arbol de Expansion Minima (MST)

Un **Arbol de Expansion Minima** (MST por sus siglas en ingles, Minimum Spanning Tree) es un subgrafo de un grafo ponderado que conecta todos los vertices con el menor peso total posible, sin formar ciclos. El MST garantiza que todos los vertices del grafo esten conectados con el menor costo.

### Caracteristicas:
- **Conexion**: Todos los vertices estan conectados, pero sin ciclos.
- **Peso minimo**: La suma de los pesos de las aristas es minima.
- **Algoritmos comunes**:
    - **Kruskal**: Basado en la clasificacion de las aristas por peso.
    - **Prim**: Basado en el crecimiento de un arbol desde un vertice inicial.

## Arbol K-d (K-dimensional)

Un **arbol K-d** (K-dimensional tree) es una estructura de datos utilizada para almacenar puntos en un espacio K-dimensional. Este tipo de arbol se utiliza comunmente en problemas de busqueda de vecinos mas cercanos y en la representacion de datos multidimensionales.

### Caracteristicas:
- **Division del espacio**: El espacio se divide en nodos de acuerdo con las coordenadas de los puntos.
- **Uso comun**: Se utiliza en aplicaciones como la busqueda de puntos cercanos, graficos de rutas o sistemas de recomendacion.
- **Balanceado**: El arbol se mantiene balanceado dividiendo los puntos de manera que el numero de nodos en cada subarbol sea aproximadamente igual.

## Grafo Aciclico Dirigido (DAG)

Un **Grafo Aciclico Dirigido** (DAG, por sus siglas en ingles) es un tipo de grafo dirigido que no contiene ciclos, es decir, no hay una secuencia de aristas que pueda llevar de un vertice de vuelta a si mismo siguiendo la direccion de las aristas.

### Caracteristicas:
- **Direccionalidad**: Las aristas tienen una direccion especifica, es decir, de un vertice a otro.
- **Ausencia de ciclos**: No hay ciclos en el grafo, lo que permite que se pueda ordenar topologicamente.
- **Uso comun**: Se utiliza en la programacion de tareas, flujos de trabajo, algoritmos de busqueda y bases de datos.

## Arbol Binario

Un **arbol binario** es un tipo especial de arbol en el que cada nodo tiene a lo sumo dos hijos, denominados hijo izquierdo e hijo derecho.

### Caracteristicas:
- **Numero limitado de hijos**: Cada nodo tiene como maximo dos hijos.
- **Estructura jerarquica**: Tiene una estructura jerarquica que permite busquedas rapidas, como en los arboles binarios de busqueda.
- **Uso comun**: Se utiliza en la implementacion de estructuras de datos como los arboles de busqueda binaria, los monticulos (heaps) y en algoritmos de recorridos.

## Arbol

Un **arbol** es un tipo especial de grafo que es conexo y aciclico. Un arbol es un grafo donde hay un unico camino entre cualquier par de vertices, y no contiene ciclos.

### Caracteristicas:
- **Vertice raiz**: Un arbol tiene un vertice especial denominado raiz desde donde se puede acceder a todos los demas vertices.
- **Nodos hoja**: Los nodos que no tienen hijos son llamados hojas.
- **Propiedad de conectividad**: Cualquier par de vertices esta conectado por un unico camino.
- **Uso comun**: Se utiliza en la representacion de estructuras jerarquicas como directorios de archivos, jerarquias organizacionales y estructuras de decisiones.

## Comparacion de Tipos de Grafos

| **Tipo de Grafo**              | **Caracteristicas Clave**               | **Uso Comun**                           |
|---------------------------------|-----------------------------------------|-----------------------------------------|
| **Grafo Ponderado**             | Vertices conectados por aristas con pesos. | Calculo de caminos mas cortos.          |
| **Arbol de Expansion Minima**  | Conecta todos los vertices con el menor peso total. | Redes, optimizacion de costos.         |
| **Arbol K-d**                  | Almacena puntos en un espacio K-dimensional. | Busqueda de vecinos mas cercanos.      |
| **Grafo Aciclico Dirigido (DAG)** | Grafo dirigido sin ciclos.              | Programacion de tareas, bases de datos. |
| **Arbol Binario**              | Cada nodo tiene a lo sumo dos hijos.     | Busqueda, estructuras de datos.        |
| **Arbol**                      | Grafo conexo y aciclico.                | Representacion jerarquica.             |
