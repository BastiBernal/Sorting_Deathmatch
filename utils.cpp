#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "utils.hpp"
#include "animation.hpp"

using namespace std;

// Variable estática para almacenar el tiempo de inicio del temporizador
static chrono::high_resolution_clock::time_point startTime;


// Función para leer un archivo y devolver un vector con los valores enteros
vector<int> readFile(const string& archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << archivo << endl;
        exit(1);
    }

    // Iniciar animación de lectura
    SimpleAnimator anim;
    anim.start();

    vector<int> data;
    int valor;

    // Leer todos los valores del archivo y almacenarlos en el vector
    while (file >> valor) {
        data.push_back(valor);
    }

    file.close();

    // Verificar si se leyeron los valores correctamente
    if (data.size() < 1) {
        cerr << "Error: El archivo no contiene suficientes datos." << endl;
        exit(1);
    }

    // Terminar animación de lectura
    anim.end("Archivo leído con éxito.");

    return data;
}


// Función para imprimir un vector de enteros
void printVector(const vector<int>& vec) {
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
void startTimer() {
    cout << "Temporizador iniciado." << endl;
    startTime = chrono::high_resolution_clock::now();
}


// Función para detener temporizador y mostrar el tiempo transcurrido
void stopTimer() {
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
    auto durationSeconds = chrono::duration_cast<chrono::seconds>(endTime - startTime);
    cout << "Tiempo transcurrido: " << duration.count() << " microsegundos (" << durationSeconds.count() << " segundos)." << endl;
    startTime = endTime; // Reiniciar el temporizador para la próxima vez
}


// Función para chequear si un vector está ordenado
bool isSorted(const vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false; // Si encontramos un elemento menor que el anterior, no está ordenado
        }
    }
    return true; // Si no encontramos ningún desorden, el vector está ordenado
}