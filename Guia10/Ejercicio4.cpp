#include<iostream>
#include<fstream>
using namespace std;

void alternativa1(ofstream&,int);
void alternativa2(ofstream&,int);

int main(){
    int valor;
    ofstream archivo("archivoBinario.bin",ios::trunc|ios::binary);
    
    return 0;
}

void leerAlternativa1(ofstream& archivo){
    
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
        archivo.write((char*)i,sizeof(int)); 
    }
}