#include<iostream>
#include<fstream>
using namespace std;

void alternativa1(ofstream&,int);
void alternativa2(ofstream&,int);
void leerAlternativa1(ifstream&);

int main(){
    int valor = 5;
    ofstream archivo("archivoBinario.bin",ios::trunc|ios::binary);
    alternativa1(archivo,valor);
    archivo.close();
    ifstream archivo2("archivoBinario.bin",ios::binary);
    if(archivo2.fail()) cout<<"No se pudo abrir el archivo"<<endl;
    leerAlternativa1(archivo2);
    archivo2.close();
    return 0;
}

void leerAlternativa1(std::ifstream& archivo) {
    archivo.seekg(0, std::ios::end);
    int tamanio = archivo.tellg() / sizeof(int);
    archivo.seekg(0, ios::beg);
    int numero, i = 0;
    while(i < tamanio){
        archivo.read((char*)&numero,sizeof(int));
        cout<<numero<<" ";
        i++;
    }
    /* Alternativa
    int numero;
    while(archivo.good()){
        archivo.read((char*)&numero,sizeof(int));
        if(archivo.tellg() != EOF) cout<<numero<<" ";
    }   
     */
    cout<<endl;
}

void alternativa1(ofstream& archivo,int valor){
    cout<<"Ingrese hasta que numero desea contar: ";cin>>valor;
    int* vector = new int[valor];
    for(int i = 0; i < valor; i++){
        vector[i] = i;
    }
    archivo.write((char *)vector,sizeof(vector));
}

void alternativa2(ofstream& archivo,int valor){
    for(int i = 0; i < valor ; i++){
        archivo.write((char*)&i,sizeof(int)); 
    }
}