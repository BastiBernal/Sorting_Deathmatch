#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;


// Función para ordenar un vector usando Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // Comenzar con un gap grande y reducirlo a la mitad en cada iteración
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realizar una inserción de Shell para el gap actual
        for (int i = gap; i < n; i++) {
            // Guardar el elemento actual y mover los elementos mayores al gap hacia adelante
            // hasta encontrar la posición correcta para el elemento actual
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Colocar el elemento actual en su posición correcta
            arr[j] = temp;
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

    // Ordenar el vector usando Shell Sort
    shellSort(data);

    // Detener el temporizador
    stopTimer();

    // Verificar si el vector está ordenado
    if (!isSorted(data)) {
        cout << "Error: El vector no está ordenado correctamente." << endl;
    }
    
    return 0;
}