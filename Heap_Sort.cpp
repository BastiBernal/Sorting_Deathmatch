#include <vector>
#include "Heap_Sort.hpp"
#include <algorithm>

using namespace std;

int parent(int i) {
    return (i-1) / 2;
}

int leftChild(int i) {
    return 2 * i +1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void heapify(vector<int>& arr, int large, int root){

    //Asume el mayor como la raiz
    int largest = root;
    int l = leftChild(root);
    int r = rightChild(root);

    // Si leftChild es mayor intercambia
    if (l < large && arr[l] > arr[largest])
        largest = l;

    // Si rightChild es mayor intercambia
    if (r < large && arr[r] > arr[largest])
        largest = r;

    // Si la raiz no era el mas grande cambiar en cadena
    if (largest != root) {
        swap(arr[root], arr[largest]);

        heapify(arr, large, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();

    //Construye el heap tomando el arreglo y ordenandolo en forma de heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    //Extraer elementos del heap construyendo el arreglo ordenado
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}