#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <fstream>

using namespace std;

// Función para generar un vector de enteros aleatorios
vector<int> generateRandomVector(int size, int minValue, int maxValue) {
    vector<int> randomVector(size);
    random_device rd;  // Obtiene un número aleatorio del sistema
    mt19937 gen(rd()); // Inicializa el generador de números aleatorios
    uniform_int_distribution<> dis(minValue, maxValue); // Distribución uniforme

    for (int i = 0; i < size; ++i) {
        randomVector[i] = dis(gen); // Genera un número aleatorio en el rango especificado
    }

    return randomVector;
}

// Función para guardar el vector en un archivo
void saveVectorToFile(const vector<int>& vec, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }

    for (const auto& val : vec) {
        file << val << " "; // Escribe cada valor en el archivo
    }

    file.close();
    cout << "Vector guardado en el archivo: " << filename << endl;
}

int main() {
    int size, minValue, maxValue;
    
    // Solicitar al usuario el tamaño del vector y el rango de valores
    cout << "Ingrese el tamaño del vector: ";
    cin >> size;
    cout << "Ingrese el valor mínimo: ";
    cin >> minValue;
    cout << "Ingrese el valor máximo: ";
    cin >> maxValue;


    cout << "Ingrese el nombre del archivo para guardar el vector: ";
    string filename;
    cin >> filename;
    if (filename.empty()) {
        filename = "random_vector.txt"; // Nombre por defecto si no se proporciona
    }

    // Generar el vector aleatorio
    vector<int> randomVector = generateRandomVector(size, minValue, maxValue);
    // Guardar el vector en un archivo
    saveVectorToFile(randomVector, filename);

    return 0;
}