#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char SopaLetras[11][11] = {"Valentin", "Joaquin", "Claudia", "Javier", "Justo", "Franco", "Vanesa", "Julio", "Gamma", "Gina"};
    char palabra[11];
    cin.getline(palabra,10);
    int i = 0, j = 0;
    bool encontrada = false;
    while(!encontrada and SopaLetras[i][0] != '\0'){
        encontrada = true;
        if(strlen(palabra) != strlen(SopaLetras[i])) encontrada = false;
        while(encontrada and SopaLetras[i][j]!='\0'){
            if(palabra[j] != SopaLetras[i][j]) encontrada = false;
            j++;
        }
        j = 0;
        if(encontrada) cout<<"Palabra "<<palabra<<" encontrada en la fila "<<i+1<<endl;
        i++;
    }
    if(!encontrada) cout<<"Palabra no encontrada"<<endl;
    cout<<"Cantidad de columnas con solo minusculas: ";
    i = 0;
    int contadorFilasMinusculas = 0;
    while(SopaLetras[i][0] != '\0'){
        int j = 0;
        bool todosMinusculas = true;
        while(todosMinusculas and SopaLetras[i][j] != '\0'){
            if(SopaLetras[i][j] < 'a' or SopaLetras[i][j] > 'z') todosMinusculas = false;
            j++;
        }
        if(todosMinusculas) contadorFilasMinusculas++;
        i++;
    }
    cout<<contadorFilasMinusculas<<endl;
    return 0;
}