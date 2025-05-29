#include <bits/stdc++.h>
using namespace std;


// Usando el Algoritmo de Partición de Lomuto 
int partition(vector<int>& arr, int low, int high) {
  
    // Se elige el pivote como el ultimo elemento del subarreglo.
    int pivot = arr[high];
  
    // Indica el último elemento reconocido como menor que el pivote.
    int i = low - 1;

    // Recorre el arreglo de izquierda a derecha omitiendo al pivote.
    // Sí encuentra un elemento menor al pivote, 
    // intercambia el primer numero no reconocido como menor que el pivote 
    // con el elemento en j.

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Mover el pivote al lugar despues de todos los menores a el (apuntado por i).
    // Devolver la posición del pivote.
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// implementacion de Quicksort
void quickSortImpl(vector<int>& arr, int low, int high) {
    
    if (low < high) {
      
        // pi es el pivote retornado por la particion
        int pi = partition(arr, low, high);


        quickSortImpl(arr, low, pi - 1);      // Recursivamente ordena los elementos mas pequeños,
        quickSortImpl(arr, pi + 1, high);     // Asi como los mayores o iguales. 
                                          // El pivote ya esta en la posicion correcta.
    }
}

void quickSort(vector<int> &arr){
    if(!arr.empty()){
        quickSortImpl(arr, 0, arr.size() - 1);
    }
}
