#include <vector>
#include "Bubble_Sort.hpp"

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