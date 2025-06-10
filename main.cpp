#include <iostream>
#include <string>
#include <vector>
#include "utils.hpp"
#include "Bubble_Sort.hpp"
#include "Insertion_Sort.hpp"
#include "Merge_Sort.hpp"
#include "Radix_Sort.hpp"
#include "Selection_Sort.hpp"
#include "Shell_Sort.hpp"
#include "Tim_Sort.hpp"
#include "Bitonic_Sort.hpp"
#include "Quick_Sort.hpp"
#include "Heap_Sort.hpp"
#include "Radix_Sort_V2.hpp"
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Uso: " << argv[0] << " <algoritmo> <ArchivoEntrada>" << endl;
        return 1;
    }

    // Obtener el nombre del algoritmo y el archivo de entrada
    string algoritmo = argv[1];
    string archivo = argv[2];

    // Leer el archivo y almacenar los datos en un vector
    vector<int> data = readFile(archivo);
    if (data.empty()) {
        cerr << "Error: El archivo está vacío o no se pudo leer." << endl;
        return 1;
    }

    // Ordenar los datos según el algoritmo especificado
    if (algoritmo == "Bubble_Sort") {
        startTimer();
        bubbleSortOptimized(data);
    } else if (algoritmo == "Insertion_Sort") {
        startTimer();
        insertionSort(data);
    } else if (algoritmo == "Merge_Sort") {
        startTimer();
        mergeSort(data);
    } else if (algoritmo == "Radix_Sort") {
        startTimer();
        radixSortWithNegatives(data);
    } else if (algoritmo == "Selection_Sort") {
        startTimer();
        selectionSort(data);
    } else if (algoritmo == "Shell_Sort") {
        startTimer();
        shellSort(data);
    } else if (algoritmo == "Tim_Sort") {
        startTimer();
        timSort(data);
    } else if (algoritmo == "Quick_Sort"){
        startTimer();
        quickSort(data);
    } else if (algoritmo == "Quick_SortV2"){
        startTimer();
        quickSort2(data);
    } else if(algoritmo == "Heap_Sort"){
        startTimer();
        heapSort(data);
    } else if (algoritmo == "Radix_Sort_V2"){
        startTimer();
        radixSortWithNegativesV2(data);
    } else if(algoritmo == "STL"){
        startTimer();
        sort(data.begin(),data.end());
    }else {
        cerr << "Error: Algoritmo no reconocido." << endl;
        cerr << "Algoritmos disponibles: Bubble_Sort, Quick_Sort, Quick_SortV2, Insertion_Sort, Merge_Sort, Radix_Sort, Selection_Sort, Shell_Sort, Tim_Sort, Heap_Sort, STL, Radix_Sort_V2." << endl;

        return 1;
    }

    // Detener el temporizador
    stopTimer();
    
    // Verificar si el vector está ordenado
    if (!isSorted(data)) {
        cout << -1 << endl;
        cerr << "Error: El vector no está ordenado correctamente." << endl;
        return 1;
    }
    return 0;
}