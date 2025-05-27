#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;


// Versión optimizada del algoritmo Bubble Sort
void bubbleSortOptimized(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Si no hubo intercambio, el arreglo ya está ordenado
        if (!swapped) {
            break;
        }
    }
}

int main() {
    // Leer el archivo de entrada
    cout << "Ingrese el nombre del archivo de entrada: ";
    string archivo;
    cin >> archivo;
    vector<int> data = readFile(archivo);

    // Iniciar el temporizador
    startTimer();

    // Ordenar el vector usando Bubble Sort
    bubbleSortOptimized(data);

    // Detener el temporizador
    stopTimer();

    // Verificar si el vector está ordenado
    if (!isSorted(data)) {
        cout << "Error: El vector no está ordenado correctamente." << endl;
    }
    
    return 0;
}