#include <vector>
#include "Insertion_Sort.hpp"

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