#include <vector>
#include <algorithm>
#include "Radix_Sort_V2.hpp"

using namespace std;

namespace {

// Obtener el máximo valor del vector
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Counting Sort por dígito (optimizado con buffer y menos divisiones)
void countingSort(vector<int>& arr, vector<int>& output, int exp) {
    int count[10] = {0};
    int n = arr.size();

    // Contar ocurrencias de cada dígito
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Calcular las posiciones
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construir el vector de salida (en orden estable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    // Intercambiar el contenido sin copiar
    arr.swap(output);
}

// Radix Sort general para enteros positivos
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = getMax(arr);
    vector<int> output(arr.size());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, output, exp);
    }
}

}


// Radix Sort completo con soporte para negativos
void radixSortWithNegativesV2(vector<int>& arr) {
    vector<int> negatives, positives;
    negatives.reserve(arr.size() / 2);
    positives.reserve(arr.size() / 2);

    // Separar negativos y positivos
    for (int num : arr) {
        if (num < 0) negatives.push_back(-num); // se invierte el signo
        else positives.push_back(num);
    }

    // Ordenar ambos vectores por separado
    radixSort(positives);
    radixSort(negatives);

    // Restaurar signo y orden de negativos
    for (int& num : negatives) num = -num;

    // Combinar resultados: negativos (en orden inverso) + positivos
    arr.clear();
    arr.reserve(negatives.size() + positives.size());
    arr.insert(arr.end(), negatives.rbegin(), negatives.rend());
    arr.insert(arr.end(), positives.begin(), positives.end());
}