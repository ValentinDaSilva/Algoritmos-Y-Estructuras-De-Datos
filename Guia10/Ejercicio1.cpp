#include <fstream>
#include <iostream>
using namespace std;

void alternativa1();
void alternativa2();

int main() {
    alternativa1();
    return 0;
}

void alternativa2(){
    ifstream archivo("archivo.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }
    int contador = 0;
    char caracter;
    while(!archivo.eof()){
        archivo.get(caracter);
        if(isalnum(caracter)) contador++;
    }
    cout<<"Cantidad de caracteres: "<<contador<<endl;
    archivo.close();
}

void alternativa1(){
    ifstream archivo("archivo.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }
    int contador = 0;
    char caracter;
    while (!archivo.eof()) {
        archivo >> (caracter);
        if(archivo.peek() != EOF) { // esto para evitar que lea el ultimo caracter.
            contador++;
        }
    }
    cout<<"Cantidad de caracteres: "<<contador<<endl;
    archivo.close();
}
