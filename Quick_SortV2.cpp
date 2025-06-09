#include <bits/stdc++.h>
using namespace std;

namespace {
    int partition(vector<int>& arr, int low, int high) {
        // Elegir pivote aleatorio y moverlo al final
        int pivotIndex = low + rand() % (high - low + 1);
        swap(arr[pivotIndex], arr[high]);

        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // QuickSort optimizado sin cambiar el pivote
    void quickSortImpl(vector<int>& arr, int low, int high) {
        while (low < high) {
            int pi = partition(arr, low, high);

            // Recursivamente procesa el lado más pequeño para evitar pila profunda
            if (pi - low < high - pi) {
                quickSortImpl(arr, low, pi - 1); // llama primero al subarreglo más pequeño
                low = pi + 1; // recursión convertida en iteración para el lado más grande
            } else {
                quickSortImpl(arr, pi + 1, high);
                high = pi - 1;
            }
        }
    }    
}

void quickSort2(vector<int> &arr) {
    if (!arr.empty()) {
        quickSortImpl(arr, 0, arr.size() - 1);
    }
}
