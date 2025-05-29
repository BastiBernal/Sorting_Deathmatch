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

    // Comenzar el temporizador
    startTimer();

    // Ordenar los datos según el algoritmo especificado
    if (algoritmo == "Bubble_Sort") {
        bubbleSortOptimized(data);
    } else if (algoritmo == "Insertion_Sort") {
        insertionSort(data);
    } else if (algoritmo == "Merge_Sort") {
        mergeSort(data);
    } else if (algoritmo == "Radix_Sort") {
        radixSortWithNegatives(data);
    } else if (algoritmo == "Selection_Sort") {
        selectionSort(data);
    } else if (algoritmo == "Shell_Sort") {
        shellSort(data);
    } else if (algoritmo == "Tim_Sort") {
        timSort(data);
    } else if (algoritmo == "Bitonic_Sort") {
        bitonicSort(data);
    } else {
        cerr << "Error: Algoritmo no reconocido." << endl;
        cerr << "Algoritmos disponibles: Bubble_Sort, Insertion_Sort, Merge_Sort, Radix_Sort, Selection_Sort, Shell_Sort, Tim_Sort, Bitonic_Sort." << endl;
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
}