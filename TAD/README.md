# Tipos Abstractos de Datos (TADs) y su Implementacion en C

## ¿Que es un TAD?

Un **Tipo Abstracto de Datos (TAD)** es una estructura de datos definida por un conjunto de operaciones que se pueden realizar sobre el, pero sin especificar como se implementan esas operaciones internamente. En otras palabras, un TAD describe **que** se puede hacer con un conjunto de datos y **como** se debe interactuar con ellos, pero no se enfoca en como se almacenan o gestionan los datos en memoria.

La principal ventaja de los TADs es que proporcionan **abstraccion**. Los usuarios de un TAD no necesitan preocuparse por los detalles de su implementacion, solo necesitan saber que operaciones estan disponibles y como usarlas.

### Caracteristicas de los TADs:
1. **Abstraccion**: Los detalles de implementacion estan ocultos.
2. **Modularidad**: Permiten organizar el codigo en modulos independientes.
3. **Independencia de Implementacion**: La implementacion de un TAD se puede cambiar sin afectar al codigo que lo usa, siempre y cuando la interfaz (conjunto de operaciones) se mantenga igual.

## Implementacion de TADs en C

En el lenguaje de programacion C, los TADs no estan definidos como una caracteristica del lenguaje, pero se pueden implementar facilmente utilizando **estructuras (`struct`)** y **funciones**.

Para implementar un TAD en C, se siguen los siguientes pasos:

1. **Definir la estructura de datos**: Se utiliza la palabra clave `struct` para definir el tipo de datos que almacenara el TAD. La estructura de datos debe contener los elementos que representan el TAD.
   
2. **Definir las funciones**: Se crean funciones que realizan las operaciones sobre el TAD. Estas funciones operan sobre la estructura de datos definida en el paso anterior.

3. **Abstraccion de operaciones**: Las operaciones disponibles para interactuar con el TAD (como agregar, eliminar, acceder a los elementos, etc.) se proporcionan a traves de funciones. El usuario puede usar estas funciones sin conocer la implementacion interna.
