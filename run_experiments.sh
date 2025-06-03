#!/bin/bash

EJECUTABLE=./sorting_app.exe
ARCHIVOS=("Vector1k")
ALGORITMOS=("Bubble_Sort" "Quick_Sort" "Insertion_Sort" "Merge_Sort" "Radix_Sort" "Selection_Sort" "Shell_Sort" "Tim_Sort")
REPETICIONES=5
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