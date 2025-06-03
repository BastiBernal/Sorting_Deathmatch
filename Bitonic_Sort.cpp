#include <vector>
#include <thread>
#include "Bitonic_Sort.hpp"

using namespace std;


namespace {    
// Definimos constantes para el ordenamiento ascendente y descendente
#define ASCENDING true
#define DESCENDING false

const int MAX_DEPTH = 4; // Profundidad máxima de la recursión

// Función para fusionar dos mitades de un arreglo bitónico (secuencial)
void bitonicMerge(vector<int>& arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        // Comparar y ordenar los elementos
        for (int i = low; i < low + k; ++i) {
            if ((dir == ASCENDING && arr[i] > arr[i + k]) || 
                (dir == DESCENDING && arr[i] < arr[i + k])) {
                swap(arr[i], arr[i + k]);
            }
        }

        // Llamada recursiva para fusionar las dos mitades
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

// Función recursiva para realizar el Bitonic Sort con hilos
void bitonicSort(vector<int>& arr, int low, int cnt, bool dir, int depth = 0) {
    if (cnt > 1) {
        int k = cnt / 2;

        if (depth < MAX_DEPTH) {
            thread t1(bitonicSort, ref(arr), low, k, ASCENDING, depth + 1);
            thread t2(bitonicSort, ref(arr), low + k, k, DESCENDING, depth + 1);
            t1.join();
            t2.join();
        } else {
            // Si alcanzamos la profundidad máxima, hacemos la ordenación secuencial
            bitonicSort(arr, low, k, ASCENDING, depth + 1);
            bitonicSort(arr, low + k, k, DESCENDING, depth + 1);
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
        int nextPower = nextPowerOfTwo(n);
        arr.resize(nextPower, 0); // Rellenamos con ceros hasta la siguiente potencia de 2
        n = arr.size(); // Actualizamos el tamaño del vector
    }

    bitonicSort(arr, 0, n, ASCENDING); // Llamada inicial al bitonic sort
}    