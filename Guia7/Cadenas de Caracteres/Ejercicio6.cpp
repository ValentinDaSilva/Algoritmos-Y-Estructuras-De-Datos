#include<iostream>
using namespace std;

void censurarPalabra(char[],char[]);
bool cadenaIncluidaTotalMente(char[],char[]);
void reemplazoPalabra(char[],char[]);

int main(){
    char texto[100], fraseProhibida[20];
    cout<<"Ingrese el texto: ";cin.getline(texto,100);
    cout<<"Ingrese la palabra a censurar: ";cin.getline(fraseProhibida,20);
    censurarPalabra(texto,fraseProhibida);
    cout<<texto<<endl;
    return 0;
}

void censurarPalabra(char texto[],char palabra[]){
    int i = 0;
    while(texto[i] != '\0'){
        if(texto[i] == palabra[0]){
            if(cadenaIncluidaTotalMente(&texto[i],palabra)){
                reemplazoPalabra(&texto[i],palabra);
            }
        }
        i++;
    }
}

bool cadenaIncluidaTotalMente(char vG[], char  vC[]){
    if(vC[0] == '\0'){
        return true;
    }
    if(vG[0] != vC[0]) return false;
    return cadenaIncluidaTotalMente(&vG[1],&vC[1]);
}

void reemplazoPalabra(char vG[], char  vC[]){
    if(vC[0] == '\0') return;
    vG[0] = 'X';
    reemplazoPalabra(&vG[1],&vC[1]);
}