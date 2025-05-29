#include <vector>
#include "Merge_Sort.hpp"

using namespace std;


namespace {
// Función para fusionar dos subarreglos
void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Vectores temporales para almacenar los subarreglos
    vector<int> L(n1), R(n2);

    // Copiar los datos a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Fusionar los vectores temporales de vuelta al arreglo original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Implementación interna recursiva de Merge Sort
void mergeSortImpl(vector<int>& array, int left, int right) {
    if (left < right) {
        // Encontrar el punto medio
        int mid = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad
        mergeSortImpl(array, left, mid);
        mergeSortImpl(array, mid + 1, right);

        // Fusionar las dos mitades ordenadas
        merge(array, left, mid, right);
    }
}
}


// Función principal de Merge Sort (wrapper)
void mergeSort(vector<int>& array) {
    if (!array.empty()) {
        mergeSortImpl(array, 0, array.size() - 1);
    }
}