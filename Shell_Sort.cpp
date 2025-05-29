#include <vector>
#include "Shell_Sort.hpp"

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