#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;


// Función para ordenar un vector usando Insertion Sort
void insertionSort(vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        // Movemos los elementos del array que son mayores que key,
        // a una posición adelante de su posición actual
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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

    // Ordenar el vector usando Insertion Sort
    insertionSort(data);

    // Detener el temporizador
    stopTimer();

    // Verificar si el vector está ordenado
    if (!isSorted(data)) {
        cout << "Error: El vector no está ordenado correctamente." << endl;
    }
    
    return 0;
}