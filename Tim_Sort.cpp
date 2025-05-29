#include <vector>
#include "Tim_Sort.hpp"

using namespace std;

const int RUN = 32; // Tamaño del subarreglo para Insertion Sort


namespace {
// Función para ordenar un vector usando Insertion Sort
void insertionSort(vector<int>& array, int left = 0, int right = -1) {
    if (right == -1) {
        right = array.size() - 1; // Si no se especifica el final, ordenar todo el vector
    }

    // Iterar sobre el subarreglo desde left hasta right
    for (int i = left + 1; i < right; i++) {
        int key = array[i];
        int j = i - 1;

        // Movemos los elementos del array que son mayores que key,
        // a una posición adelante de su posición actual
        while (j >= left && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

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
}


// Función principal de Tim Sort
void timSort(vector<int>& array) {
    int n = array.size();

    // Ordenar los subarreglos pequeños usando Insertion Sort
    for (int start = 0; start < n; start += RUN) {
        int end = min(start + RUN - 1, n - 1);
        insertionSort(array, start, end + 1);
    }

    // Fusionar los subarreglos ordenados
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right) {
                merge(array, left, mid, right);
            }
        }
    }
}