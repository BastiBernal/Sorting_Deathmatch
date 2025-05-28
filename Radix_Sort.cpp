#include <vector>
#include "Radix_Sort.hpp"

using namespace std;


namespace {
// Función para encontrar el máximo valor en un vector
int getMax(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


// Función para realizar el conteo de dígitos
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Vector de salida
    int count[10] = {0}; // Inicializar el conteo de dígitos

    // Contar ocurrencias de cada dígito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Cambiar count[i] para que contenga la posición real del dígito en output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir el vector de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar el vector de salida a arr[], para que contenga los números ordenados por el dígito actual
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


// Función principal de Radix Sort
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    // Encontrar el valor máximo para determinar el número de dígitos
    int maxVal = getMax(arr);

    // Aplicar counting sort para cada dígito
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}
}


// Función para adaptar el Radix Sort para números negativos
void radixSortWithNegatives(vector<int>& arr) {
    vector<int> negatives, positives;

    // Separar los números negativos de los positivos
    for (int num : arr) {
        if (num < 0) negatives.push_back(-num);
        else positives.push_back(num);
    }

    // Ordenamos los positivos con normalidad
    radixSort(positives);

    // Ordenamos el valor absoluto de los negativos
    radixSort(negatives);

    // Invertimos el orden de los negativos y les restauramos el signo
    for (int& num : negatives) num = -num;

    // Combinamos ambos vectores
    arr.clear();
    arr.insert(arr.end(), negatives.rbegin(), negatives.rend());
    arr.insert(arr.end(), positives.begin(), positives.end());
}