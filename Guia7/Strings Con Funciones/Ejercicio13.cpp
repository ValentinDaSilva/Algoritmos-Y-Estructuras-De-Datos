#include<iostream>
using namespace std;

int main(){
    string sopaDeLetras[10] = {"Valentin", "Joaquin", "Justo", "Franco", "Julio", "Vanesa", "Javier", "Claudia", "Martina", "Gamma"};
    string palabra;
    cout<<"Ingrese la palabra a buscar: ";getline(cin,palabra);
    int i = 0;
    bool encontrado = false;
    while(!encontrado and i < 10){
        if(sopaDeLetras[i].find(palabra) < sopaDeLetras[i].length()){ 
            cout<<"Encontrado en la fila: "<<i + 1<<endl;
            encontrado = true;
        }
        i++;
    }
    if(!encontrado) cout<<"La palabra no fue encontrada!"<<endl;
    
    return 0;
}