#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;


// Función para ordenar un vector usando Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {

        // Encontrar el índice del elemento mínimo en el subarreglo no ordenado
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Intercambiar el elemento mínimo encontrado con el primer elemento del subarreglo no ordenado
        swap(arr[i], arr[minIndex]);
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

    // Ordenar el vector usando Selection Sort
    selectionSort(data);

    // Detener el temporizador
    stopTimer();

    // Verificar si el vector está ordenado
    if (!isSorted(data)) {
        cout << "Error: El vector no está ordenado correctamente." << endl;
    }
    
    return 0;
}