#include <vector>
#include <algorithm>
#include "Radix_Sort_V3.hpp"

using namespace std;

namespace {

// Counting Sort por byte (byte_idx es 0 para el byte menos significativo, 1 para el siguiente, etc.)
void countingSortByByte(vector<int>& arr, vector<int>& buffer, int byte_idx) {
    const int RADIX_BASE = 256; // 2^8, para procesar un byte a la vez
    int count[RADIX_BASE] = {0}; // Inicializa todos los contadores a 0
    int n = arr.size();
    int shift_amount = byte_idx * 8; // Cuántos bits desplazar para obtener el byte actual

    // Contar ocurrencias de cada valor de byte
    for (int i = 0; i < n; i++) {
        unsigned char current_byte = (arr[i] >> shift_amount) & (RADIX_BASE - 1); // (RADIX_BASE - 1) es 0xFF
        count[current_byte]++;
    }

    // Calcular las posiciones acumuladas (para la estabilidad)
    for (int i = 1; i < RADIX_BASE; i++) {
        count[i] += count[i - 1];
    }

    // Construir el vector de salida 'buffer'
    // Iterar desde el final para mantener la estabilidad
    for (int i = n - 1; i >= 0; i--) {
        unsigned char current_byte = (arr[i] >> shift_amount) & (RADIX_BASE - 1);
        buffer[--count[current_byte]] = arr[i];
    }

    // Intercambiar el contenido de arr con buffer para que arr contenga el resultado ordenado de esta pasada
    // y buffer contenga los datos originales de arr de esta pasada (que se sobrescribirán en la siguiente).
    arr.swap(buffer);
}

// Radix Sort general para enteros positivos (ahora byte-wise)
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    vector<int> buffer(arr.size()); // Buffer auxiliar para countingSortByByte

    // Iterar para cada byte de un entero. Para un int de 32 bits, sizeof(int) es 4.
    for (int byte_idx = 0; byte_idx < sizeof(int); byte_idx++) {
        // En cada pasada, 'arr' se ordena según el byte actual,
        // y el resultado se coloca de nuevo en 'arr' a través del swap en countingSortByByte.
        // 'buffer' se usa como el array de salida temporal dentro de countingSortByByte.
        countingSortByByte(arr, buffer, byte_idx);
    }
}

}


// Radix Sort completo con soporte para negativos
void radixSortWithNegativesV3(vector<int>& arr) {
    vector<int> negatives, positives;
    negatives.reserve(arr.size()); 
    positives.reserve(arr.size());

    // Separar negativos y positivos
    for (int num : arr) {
        if (num < 0) negatives.push_back(-num); // se invierte el signo para ordenar como positivos
        else positives.push_back(num);
    }

    // Ordenar ambos vectores por separado usando el radixSort byte-wise
    radixSort(positives);
    radixSort(negatives);

    // Restaurar signo y orden de negativos
    // Los negativos ordenados por su valor absoluto deben invertirse y luego colocarse en orden inverso.
    arr.clear(); // Limpiar el array original para reconstruirlo

    // Insertar los negativos (ya con signo negativo) en orden inverso de su lista ordenada (que era de abs)
    for (int i = negatives.size() - 1; i >= 0; --i) {
        arr.push_back(-negatives[i]);
    }
    // Insertar los positivos
    arr.insert(arr.end(), positives.begin(), positives.end());
}