#!/bin/bash

EJECUTABLE=./sorting_app
COMPILER=g++
FLAGS="-Wall -Wextra"
PROGRAMS=("main.cpp" "utils.cpp" "Radix_Sort_V3.cpp" "Radix_Sort_V2.cpp" "Bubble_Sort.cpp" "Insertion_Sort.cpp" "Merge_Sort.cpp" "Selection_Sort.cpp" "Radix_Sort.cpp" "Shell_Sort.cpp" "Tim_Sort.cpp" "Quick_Sort.cpp" "Heap_Sort.cpp" "Quick_SortV2.cpp")

# Unificar el nombre de los archivos fuente
SRC_FILES="${PROGRAMS[@]}"

# Compilar el programa
$COMPILER $FLAGS -o $EJECUTABLE $SRC_FILES

# Verificar si la compilación fue exitosa
if [ $? -ne 0 ]; then
    echo -e "\033[1;31mError al compilar el programa.\033[0m"
    exit 1
fi

# Verificar si el ejecutable se creó correctamente
if [ ! -f $EJECUTABLE ]; then
    echo -e "\033[1;31mEl ejecutable no se creó correctamente.\033[0m"
    exit 1
fi

# Dar permisos de ejecución al ejecutable
chmod +x $EJECUTABLE

# Verificar si se otorgaron los permisos correctamente
if [ $? -ne 0 ]; then
    echo -e "\033[1;31mError al otorgar permisos de ejecución al ejecutable.\033[0m"
    exit 1
fi

# Mensaje de éxito
echo -e "\033[1;34mCompilación completada!\033[0m"