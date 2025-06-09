#!/bin/bash

EJECUTABLE=./sorting_app.exe
ARCHIVOS=("vector100kV2" "vector1mV2" "vector5m" "vector10k")
ALGORITMOS=("Quick_Sort" "Insertion_Sort" "Merge_Sort" "Radix_Sort" "Shell_Sort" "Tim_Sort" "Heap_Sort" "STL")
REPETICIONES=20
CSV="resultados.csv"

echo "Algoritmo;Archivo;Tiempo(ns)" > "$CSV"

for archivo in "${ARCHIVOS[@]}"; do
    for algoritmo in "${ALGORITMOS[@]}"; do
        for ((i = 1; i <= REPETICIONES; i++)); do
            tiempo=$($EJECUTABLE "$algoritmo" "$archivo")
            echo "$algoritmo;$archivo;$tiempo" >> "$CSV"
        done
    done
done