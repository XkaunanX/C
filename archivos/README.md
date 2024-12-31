# Manejo de Archivos en C

En C, el manejo de archivos se realiza a traves de funciones de la biblioteca estandar de C, que permiten leer, escribir, modificar y gestionar archivos de manera eficiente. El manejo de archivos es fundamental en la programacion de sistemas, bases de datos y otros programas que necesitan almacenar y recuperar datos persistentes.

## Tipos de Acceso a Archivos

Existen diferentes formas de acceso a archivos, cada una adecuada a distintos escenarios y necesidades. A continuacion, se describen los tipos mas comunes:

### 1. Acceso Secuencial

El **acceso secuencial** implica leer o escribir en el archivo de manera continua, uno tras otro, en el mismo orden en que los datos estan almacenados. Este tipo de acceso es adecuado cuando los datos se leen o se escriben de forma lineal, es decir, desde el principio del archivo hasta el final, sin saltarse registros.

**Caracteristicas:**
- Se realiza en orden consecutivo.
- Adecuado para pequeños archivos o cuando no se requiere acceso rapido a registros especificos.
- Relativamente facil de implementar y usar.

**Operaciones comunes:**
- `fread()`, `fwrite()`, `fgetc()`, `fputc()`, `fgets()`, `fputs()`.

### 2. Acceso Indexado

El **acceso indexado** implica el uso de un indice que permite localizar rapidamente los registros dentro del archivo. El indice es un conjunto de punteros o claves que indican la ubicacion de los registros en el archivo, permitiendo acceder directamente a los datos sin necesidad de recorrer todo el archivo secuencialmente.

**Caracteristicas:**
- Utiliza un indice que mapea las claves de los registros a las posiciones en el archivo.
- Ofrece una mayor velocidad de acceso en archivos grandes.
- Requiere espacio adicional para almacenar el indice.

**Operaciones comunes:**
- Busquedas rapidas usando claves.
- Modificacion o eliminacion de registros especificos sin leer todo el archivo.

### 3. Acceso Hash

El **acceso hash** utiliza una funcion hash para convertir una clave de busqueda en una direccion de ubicacion en el archivo. Este tipo de acceso es muy eficiente para busquedas rapidas, ya que la funcion hash permite obtener una ubicacion directa para acceder a los registros.

**Caracteristicas:**
- Utiliza una funcion hash para mapear claves a ubicaciones.
- Muy eficiente para busquedas de registros, especialmente en tablas grandes.
- La funcion hash debe estar diseñada para evitar colisiones (cuando diferentes claves generan la misma ubicacion).

**Operaciones comunes:**
- `fseek()`, `fread()`, `fwrite()` con calculos de la ubicacion mediante la funcion hash.

### 4. Acceso Directo

El **acceso directo** permite leer o escribir en cualquier parte del archivo de forma directa, sin necesidad de recorrer los registros de manera secuencial. El acceso directo usa posiciones absolutas o relativas para llegar a la ubicacion deseada dentro del archivo.

**Caracteristicas:**
- Permite saltar a cualquier parte del archivo rapidamente.
- Adecuado para archivos grandes donde se necesita acceso frecuente a posiciones especificas.
- Se utiliza en archivos binarios o bases de datos.

**Operaciones comunes:**
- `fseek()`, `ftell()`, `fread()`, `fwrite()`.

### 5. Acceso Bipartito

El **acceso bipartito** es un tipo de acceso que divide el archivo en dos secciones: una para los datos y otra para los indices. Este tipo de acceso permite mejorar la organizacion de la informacion y facilita la busqueda de registros especificos sin necesidad de recorrer todo el archivo.

**Caracteristicas:**
- El archivo se divide en dos partes: una para los datos y otra para los indices.
- Adecuado para bases de datos que requieren acceso eficiente a registros sin tener que leer todos los datos.
- La gestion de indices puede hacerse con un sistema de busqueda o arbol.

### 6. Acceso Aleatorio

El **acceso aleatorio** permite acceder a cualquier parte del archivo en cualquier momento sin la necesidad de leer secuencialmente los registros. Este tipo de acceso es util cuando se desea manipular grandes volumenes de datos sin necesidad de recorrer toda la estructura de almacenamiento.

**Caracteristicas:**
- Permite acceder a cualquier parte del archivo sin seguir un orden secuencial.
- Usualmente, se realiza mediante punteros o indices que determinan las ubicaciones en el archivo.
- Muy eficiente para operaciones en archivos grandes o complejos.

**Operaciones comunes:**
- `fseek()`, `ftell()`, `fread()`, `fwrite()`.

## Funciones Comunes para Manejo de Archivos

En C, el manejo de archivos se realiza principalmente a traves de las siguientes funciones:

- `fopen()`: Abre un archivo en un modo especifico (lectura, escritura, etc.).
- `fclose()`: Cierra un archivo.
- `fread()`: Lee datos de un archivo.
- `fwrite()`: Escribe datos en un archivo.
- `fseek()`: Mueve el puntero de lectura/escritura a una posicion especifica en el archivo.
- `ftell()`: Obtiene la posicion actual del puntero de lectura/escritura.
- `fprintf()`: Escribe una cadena de texto en un archivo.
- `fscanf()`: Lee una cadena de texto desde un archivo.
