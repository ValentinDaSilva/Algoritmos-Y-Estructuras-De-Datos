#include<iostream>
using namespace std;

int main(){
    char SopaLetras[11][11] = {"Valentin", "Joaquin", "Claudia", "Javier", "Justo", "Franco", "Vanesa", "Julio", "Gamma", "Gina"};
    char palabra[11];
    cin.getline(palabra,10);
    int i = 0, j = 0;
    bool encontrada = false;
    while(!encontrada and SopaLetras[i]!='\0'){
        encontrada = true;
        while(encontrada and SopaLetras[i][j]!='\0'){
            if(palabra[j] != SopaLetras[i][j]) encontrada = false;
            j++;
        }
        if(encontrada) cout<<"Palabra "<<palabra<<" encontrada en la fila "<<i+1<<endl;
        i++;
    }
    if(!encontrada) cout<<"Palabra no encontrada"<<endl;
    return 0;
}