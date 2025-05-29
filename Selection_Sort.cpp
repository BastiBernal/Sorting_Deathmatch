#include <vector>
#include "Selection_Sort.hpp"

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