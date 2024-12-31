# Creacion de Procesos Hijos

La creacion de procesos hijos es una tecnica fundamental en sistemas operativos que permite a un proceso (llamado proceso padre) generar nuevos procesos (llamados procesos hijos). Esta tecnica es clave para la ejecucion de multiples tareas simultaneas o distribuidas, y es utilizada para mejorar la eficiencia y la escalabilidad de los programas.

## ¿Que es la Creacion de Procesos Hijos?

Cuando un proceso necesita realizar varias tareas al mismo tiempo o delegar tareas especificas a otros procesos, puede crear uno o mas procesos hijos. Cada proceso hijo ejecutara una tarea diferente, y pueden trabajar en paralelo con el proceso padre o entre si.

### Comportamiento de los Procesos Hijos

- **Independencia**: Los procesos hijos, aunque creados por el proceso padre, pueden ejecutarse de forma independiente. Sin embargo, pueden comunicarse con el proceso padre y entre si si es necesario.
- **Identificacion**: Cada proceso en un sistema operativo tiene un identificador unico llamado PID (Process ID). Los procesos hijos tienen su propio PID, y el proceso padre puede obtener este valor para gestionarlos o esperar su finalizacion.
- **Finalizacion**: Los procesos hijos pueden finalizar en cualquier momento, y dependiendo de su implementacion, pueden enviar informacion de vuelta al proceso padre o al sistema operativo.

## ¿Por que crear Procesos Hijos?

Los procesos hijos son utiles en situaciones donde se necesitan realizar multiples operaciones de forma concurrente o paralela. Al crear procesos hijos, se puede distribuir la carga de trabajo entre diferentes unidades de ejecucion, lo que puede mejorar el rendimiento general de un programa.

## Comunicacion entre Padre e Hijo

En muchos casos, el proceso padre y los procesos hijos necesitan intercambiar informacion. Esto se puede hacer utilizando mecanismos como **pipes**, **señales** o **memoria compartida**, dependiendo del sistema operativo y los requisitos de la aplicacion.

## Consideraciones al Crear Procesos Hijos

- **Consumo de recursos**: La creacion de procesos hijos puede consumir recursos del sistema, como memoria y capacidad de procesamiento. Es importante no crear mas procesos de los que el sistema puede manejar eficientemente.
- **Sincronizacion**: Cuando multiples procesos hijos estan trabajando en tareas relacionadas, puede ser necesario sincronizarlos para evitar condiciones de carrera o accesos simultaneos a recursos compartidos.
- **Manejo de errores**: Es crucial manejar adecuadamente los errores en la creacion y ejecucion de los procesos hijos, para evitar que el sistema quede en un estado inconsistente.

# Creacion de Procesos Hijos y la PCB en C

Cuando un proceso crea un proceso hijo en C, utilizando la funcion `fork()`, el proceso hijo hereda varios atributos del proceso padre. Uno de los elementos mas importantes que se copia es la **PCB** (Process Control Block, Bloque de Control del Proceso).

## ¿Que es la PCB?

La **PCB** es una estructura de datos que el sistema operativo utiliza para almacenar toda la informacion relacionada con un proceso en ejecucion. Esta informacion incluye:

- **PID (Identificador de Proceso)**: Un identificador unico asignado a cada proceso.
- **Estado del Proceso**: Indica si el proceso esta ejecutandose, esperando, detenido, etc.
- **Registros de CPU**: Los valores de los registros del procesador cuando el proceso fue suspendido.
- **Punteros a la Memoria**: Direcciones de memoria relacionadas con el proceso, como el espacio de direcciones virtuales.
- **Informacion de Entrada/Salida**: Detalles sobre archivos abiertos o dispositivos que el proceso esta utilizando.
- **Prioridad**: Define la prioridad del proceso en el sistema operativo.

## Copia de la PCB en el `fork()`

Cuando se llama a `fork()` en C, el sistema operativo crea un nuevo proceso (hijo) que es una copia del proceso original (padre). El proceso hijo hereda una copia de la **PCB** del proceso padre, lo que incluye la mayor parte del estado del proceso, pero con algunas diferencias claves:

### Atributos Copiados

1. **Registros de CPU**: El hijo obtiene una copia de los registros de CPU del padre, aunque el proceso hijo comenzara a ejecutarse desde el punto en el que `fork()` fue llamado, lo que significa que tiene su propia ejecucion a partir de ese momento.
  
2. **Espacio de Memoria**: El espacio de memoria del hijo es inicialmente una copia del del padre. Sin embargo, debido a optimizaciones como "copy-on-write", si alguno de los procesos (padre o hijo) modifica una parte de la memoria, esa parte se copia realmente y cada uno tendra su propio espacio de memoria para esa parte.

3. **Archivos Abiertos**: El proceso hijo hereda los descriptores de archivo abiertos por el padre, lo que significa que ambos procesos comparten los mismos descriptores de archivo, pero con sus propios punteros de archivo (la posicion en el archivo no se comparte).

4. **Variables de Entorno y Argumentos**: El proceso hijo tambien copia las variables de entorno y los argumentos pasados al programa, aunque este puede modificarlos independientemente del padre.

### Diferencias Entre el Padre y el Hijo

Aunque el proceso hijo copia la **PCB** del padre, hay algunas diferencias clave:

- El valor retornado por `fork()` es **0** en el hijo y es el **PID** del proceso hijo en el padre.
- El **PID** del hijo sera unico, diferente al del padre.
- Las direcciones de memoria pueden ser iguales al inicio, pero debido a optimizaciones como "copy-on-write", el proceso hijo puede tener su propio espacio de memoria si realiza modificaciones.

### Importancia de la Copia de la PCB

La copia de la PCB permite que el proceso hijo continue con el mismo contexto de ejecucion que el proceso padre, facilitando el paralelismo y la multitarea. Sin embargo, debido a que los procesos son independientes, el sistema operativo tambien mantiene mecanismos para sincronizar y gestionar los procesos de manera que se pueda evitar el acceso simultaneo y no controlado a los recursos compartidos.

## Conclusion

La creacion de un proceso hijo mediante `fork()` en C es un mecanismo eficiente que permite la creacion de nuevos procesos, donde el proceso hijo hereda una copia casi identica de la **PCB** del proceso padre. Esto garantiza que el proceso hijo pueda ejecutarse con un contexto de ejecucion similar al del padre, mientras que sigue siendo independiente en su propia ejecucion.


# Libreria: `#include <unistd.h>`
La libreria `unistd.h` proporciona acceso a funciones y constantes del sistema operativo Unix y sistemas basados en Unix. Algunas de sus funciones mas utilizadas son:

- **Lectura y escritura de archivos**: `read()`, `write()`
- **Gestion de procesos**: `fork()`, `exec()`, `getpid()`
- **Control de dispositivos**: `open()`, `close()`
- **Manipulacion de directorios**: `chdir()`, `getcwd()`
- **Uso de identificadores de usuario y grupo**: `getuid()`, `getgid()`

## Funciones de Gestion de Procesos

### `int pid = fork();`
La funcion `fork()` se utiliza para crear un nuevo proceso, denominado "proceso hijo", a partir del proceso que realiza la llamada, denominado "proceso padre".

#### Valor de Retorno:
- **En el proceso padre**: Devuelve el **PID** del proceso hijo. Esto permite al proceso padre identificar y gestionar el proceso hijo.
- **En el proceso hijo**: Devuelve **0**, indicando que es el proceso hijo.
- **En caso de error**: Devuelve **-1** si ocurre un error al intentar crear el proceso (por ejemplo, si se alcanza el limite maximo de procesos).

### `getpid();`
La funcion `getpid()` devuelve el identificador del proceso que esta ejecutando la llamada.

#### Retorno:
- Devuelve un valor de tipo `pid_t`, que es un numero entero unico asignado al proceso actual.
- Se utiliza para obtener el PID del proceso en ejecucion, lo cual es util para la depuracion o para manejar logica que dependa de dicho identificador.

### `getppid();`
La funcion `getppid()` devuelve el identificador del proceso padre del proceso actual.

#### Retorno:
- Devuelve el **PID** del proceso padre, lo cual es util cuando un proceso hijo necesita conocer quien lo creo, por ejemplo, para gestionar registros o realizar operaciones de depuracion.

## Funciones de Terminacion y Control de Procesos

### `exit(0);`
La funcion `exit(0)` termina el proceso actual de manera inmediata.

#### Codigo de Salida:
- **0**: Indica que el proceso ha terminado con exito.
- **Cualquier valor distinto de 0**: Indica que el proceso termino debido a un error o una condicion excepcional, lo que permite al sistema operativo o a otros procesos conocer el resultado de la ejecucion.

### `exit(EXIT_FAILURE);`
Llama a `exit()` con el codigo de salida `EXIT_FAILURE`, lo que indica que el proceso ha fallado.

### `perror("Error al crear el proceso H1");`
La funcion `perror()` imprime un mensaje de error en la salida estandar que describe por que una operacion fallo, utilizando la variable global `errno` para obtener detalles del error.

## Ejecucion de Comandos del Sistema

### `system("./script.sh");`
La funcion `system()` se utiliza para ejecutar un comando del sistema operativo desde un programa en C.

#### Comportamiento:
- Crea un nuevo proceso para ejecutar el comando especificado en el shell del sistema operativo (por ejemplo, Bash).
- **Retorno**: Devuelve un valor entero:
  - Si el comando se ejecuta correctamente, devuelve el codigo de salida del shell.
  - Si ocurre un error (por ejemplo, si el comando no existe), devuelve un valor negativo.
- **Bloqueo**: La funcion `system()` bloquea la ejecucion del programa original hasta que el comando haya terminado de ejecutarse.

## Reemplazo de Proceso

### `execl("/bin/ls", "ls", NULL);`
La funcion `execl()` reemplaza el proceso actual con un nuevo programa. En este caso, ejecuta el comando `ls` para listar el contenido de un directorio.

#### Argumentos:
- **path**: La ruta completa del programa que deseas ejecutar (por ejemplo, "/bin/ls").
- **arg0**: El primer argumento que se pasa al programa ejecutado (usualmente, el nombre del propio ejecutable).
- **...**: Puedes pasar otros argumentos adicionales que el programa pueda necesitar, separados por comas.
- **NULL**: La lista de argumentos debe terminar con `NULL`.

#### Comportamiento:
- **Reemplazo de proceso**: El proceso original se reemplaza completamente por el nuevo proceso que se esta ejecutando.
- Si `execl()` se ejecuta correctamente, **no retorna** al proceso original. Si hay un error, devuelve **-1** y se puede utilizar `errno` para obtener detalles del fallo.

## Espera de un Proceso Hijo

### `wait(NULL);`
La funcion `wait()` permite que un proceso padre espere a que uno de sus procesos hijos termine su ejecucion.

#### Comportamiento:
- **Argumentos**: Si se pasa un puntero a un entero, se almacenara el estado de finalizacion del proceso hijo. Si se pasa `NULL`, se ignora el estado.
- **Espera**: El proceso padre se bloquea y espera hasta que uno de sus procesos hijos termine.
- **Retorno**: Devuelve el PID del proceso hijo que termino. Si no hay mas hijos que esperar, devuelve **-1** y establece `errno` a `ECHILD`.
  
#### Uso del Estado:
- Si se proporciona un puntero `status`, puede usarse para determinar si el proceso hijo termino correctamente o si hubo algun error.

#### Consideraciones:
- **Bloqueo**: `wait()` bloquea al proceso padre hasta que el hijo termine. Esto es util cuando el padre necesita esperar resultados de su hijo o asegurar que el hijo haya completado su tarea.
- **Multiples Hijos**: Si el proceso tiene varios hijos, puede llamar a `wait()` en un bucle o usar `waitpid()` con los PIDs de los hijos.

# Tipos de creacion de procesos hijos

## 1. Creacion Lineal de Procesos Hijos

### Descripcion
La creacion lineal de procesos hijos implica que cada proceso padre crea un solo proceso hijo en una secuencia ordenada. Es decir, el proceso padre crea un hijo, espera (o no) que el hijo termine y luego procede a crear otro hijo. Este proceso se repite de manera secuencial.

### Caracteristicas:
- **Secuencial**: Los procesos se crean uno por uno en un orden determinado.
- **Control del padre**: El proceso padre tiene control sobre cuando y cuantos hijos se crean.
- **Ideal para**: Situaciones donde se necesita un control estricto sobre la creacion y ejecucion de los procesos hijos.

## 2. Creacion Exponencial de Procesos Hijos

### Descripcion
En la creacion exponencial de procesos hijos, cada proceso creado (ya sea un proceso padre o hijo) crea multiples procesos hijos, lo que provoca un crecimiento exponencial en el numero de procesos. Este enfoque es util cuando se necesitan crear una gran cantidad de procesos rapidamente.

### Caracteristicas:
- **Crecimiento rapido**: La cantidad de procesos crece exponencialmente, lo que puede generar muchos procesos en poco tiempo.
- **Menos control**: El padre no tiene un control preciso sobre la cantidad exacta de procesos que se crean debido al comportamiento exponencial.
- **Ideal para**: Escenarios que requieren crear muchos procesos en poco tiempo, como en tareas paralelizadas a gran escala.

## 3. Creacion en Arbol (Jerarquica)

### Descripcion
En la creacion en arbol de procesos, cada proceso padre crea multiples procesos hijos, pero estos hijos tambien pueden crear mas procesos, resultando en una estructura jerarquica. Es decir, los procesos se organizan en niveles, donde un proceso padre puede generar varios procesos hijos que a su vez generan mas hijos.

### Caracteristicas:
- **Estructura jerarquica**: Los procesos siguen una organizacion en niveles, creando una estructura tipo arbol.
- **Escalable**: El numero de procesos puede crecer de manera controlada, permitiendo una mejor gestion.
- **Ideal para**: Situaciones en las que los procesos deben organizarse de manera jerarquica y gestionarse de manera eficiente.

## 4. Creacion en Paralelo (Sincronizacion Opcional)

### Descripcion
En la creacion en paralelo, multiples procesos son creados simultaneamente, sin necesidad de que el proceso padre espere que los hijos terminen antes de crear mas procesos. Este enfoque permite la ejecucion de tareas en paralelo, optimizando el tiempo de ejecucion.

### Caracteristicas:
- **Ejecucion simultanea**: Los procesos hijos se ejecutan de manera paralela.
- **Sincronizacion opcional**: No se requiere que el padre espere la finalizacion de los hijos antes de crear mas.
- **Ideal para**: Tareas que se pueden ejecutar en paralelo sin necesidad de secuenciar los procesos.
