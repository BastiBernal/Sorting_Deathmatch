#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include "utils.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <ArchivoEntrada>" << endl;
        return 1;
    }

    // Obtener el nombre del algoritmo y el archivo de entrada
    string archivo = argv[1];
   	vector<int> data = readFile(archivo);
   	cout << "Escoger tipo (order o backward)" << endl;
   	string tipo;
   	cin >> tipo;
   	if (tipo =="order"){
   		sort(data.begin(),data.end());
   	} else if(tipo == "backward"){
   		sort(data.begin(),data.end(), greater<int>());
   	} else{
   		cout << "Opcion incorrecta." << endl ;
   		return 1;
   	}
   	string filename = tipo ;
   	filename.append("_");
   	filename = filename + archivo;
   	saveVectorToFile(data,filename);
   	return 0; 

}