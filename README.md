# Sorting_Deathmatch
Entregable 2 del ramo Estructura de Datos.


### Modo de compilación:
#### Automático:
Ejecuta en el terminal ./compiler.sh
#### Manual:
g++ main.cpp Bubble_Sort.cpp Quick_Sort.cpp Quick_SortV2.cpp Insertion_Sort.cpp Merge_Sort.cpp Radix_Sort.cpp Selection_Sort.cpp Shell_Sort.cpp Tim_Sort.cpp Heap_Sort.cpp utils.cpp -o sorting_app.exe

### Ejecución:
./sorting_app.exe Algoritmo ArchivoEntrada

### Ejecución de experimentos:
./run_experiments.sh

Para crear vector de 5 millones y 10 millones (no caben en git):
g++ randomVectorGenerator.cpp -o vector_generator.exe

*Correr vector_generator*
Inputs: 
-Para vector 10 millones
10000000
-2147483648
2147483647
vector10m

-Para vector 5 millones
5000000
-2147483648
2147483647
vector5m

Para crear sus versiones ordenadas compilar: g++ orderSaver.cpp utils.cpp -o order_saver.exe
./order_saver ArchivoAOrdenar

En ejecucion colocar order para ordenado ascendente y backward para ordenado descendentemente.
