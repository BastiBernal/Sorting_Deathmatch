#include <vector>
#include "utils.hpp"
#include "Bitonic_Sort.hpp"

using namespace std;

#define ASCENDING true
#define DESCENDING false


namespace {
// Función para fusionar dos mitades de un arreglo bitónico
void bitonicMerge(vector<int>& arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        
        #pragma omp parallel for
        for (int i = low; i < low + k; ++i) {
            if ((dir == ASCENDING && arr[i] > arr[i + k]) || 
                (dir == DESCENDING && arr[i] < arr[i + k])) {
                swap(arr[i], arr[i + k]);
            }
        }

        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

// Función recursiva para realizar el Bitonic Sort
void bitonicSort(vector<int>& arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;

        // Creamos paralelismo en las dos mitades del bitonic sort
        #pragma omp parallel sections
        {
            #pragma omp section
            bitonicSort(arr, low, k, ASCENDING); // Primera mitad en orden ascendente

            #pragma omp section
            bitonicSort(arr, low + k, k, DESCENDING); // Segunda mitad en orden descendente
        }

        // Fusionamos las dos mitades
        bitonicMerge(arr, low, cnt, dir);
    }
}

// Función para verificar si un número es potencia de 2
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Función para encontrar la siguiente potencia de 2 mayor o igual a n
int nextPowerOfTwo(int n) {
    if (n <= 0) return 1;
    int power = 1;
    while (power < n) {
        power <<= 1; // Desplazamiento a la izquierda para multiplicar por 2
    }
    return power;
}
}


// Función principal para ordenar un vector usando Bitonic Sort
void bitonicSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return; 

    // Aseguramos que el tamaño del vector sea una potencia de 2
    if (!isPowerOfTwo(n)) {
        cerr << "ADVERTENCIA: El tamaño del vector debe ser una potencia de 2 para Bitonic Sort, el arreglo se rellenará con ceros." << endl;
        int nextPower = nextPowerOfTwo(n);
        arr.resize(nextPower, 0); // Rellenamos con ceros hasta la siguiente potencia de 2
        n = arr.size(); // Actualizamos el tamaño del vector
    }

    bitonicSort(arr, 0, n, ASCENDING); // Llamada inicial al bitonic sort
}    