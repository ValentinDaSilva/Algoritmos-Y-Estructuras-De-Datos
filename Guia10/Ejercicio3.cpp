#include<iostream>
#include<fstream>
using namespace std;

int cantPalabras(ifstream&);
int palabraMasLarga(ifstream&);
int cantidadDePalabrasQueComienzaCon(ifstream&,char);

int main(){
    ifstream archivo("archivo.txt",ios::app);
    cout<<"Elige una letra: "; char letra; cin>>letra;
    cout<<"Cantidad de palabras: "<<cantPalabras(archivo)<<endl;
    archivo.seekg(0, ios::beg);
    cout<<"Longitud de la palabra mas larga: "<<palabraMasLarga(archivo)<<endl;
    archivo.seekg(0, ios::beg);
    cout<<"La cantidad de palabras que comienzan con "<<letra<<" es de: "<<cantidadDePalabrasQueComienzaCon(archivo,letra)<<endl;
    return 0;
}

int cantidadDePalabrasQueComienzaCon(ifstream& archivo, char letra){
    if(archivo.eof()) return 0;
    string palabra; getline(archivo,palabra, ' ');
    // cout<<palabra<<endl;
    if(palabra[0] == letra) return 1 + cantidadDePalabrasQueComienzaCon(archivo,letra);
    return cantidadDePalabrasQueComienzaCon(archivo,letra);
}

int palabraMasLarga(ifstream& archivo){
    if(archivo.eof()) return 0;
    string palabra; getline(archivo,palabra,' '); int largo = palabra.length();
    int siguiente = palabraMasLarga(archivo);
    if(largo > siguiente) return largo;
    return siguiente;
}

int cantPalabras(ifstream& texto){
    if(texto.eof()) return 0;
    string palabra; getline(texto,palabra,' ');
    return 1 + cantPalabras(texto);
}