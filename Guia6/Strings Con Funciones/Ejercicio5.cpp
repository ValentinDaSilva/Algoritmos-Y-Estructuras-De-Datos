#include<iostream>
using namespace std;
//contar palabras y caracteres
int main(){
    string texto;
    int cantEspacios = 0, indice = 0;
    cout<<"Ingrese el texto para contar palabras y caracteres: "<<endl;getline(cin,texto);
    while(indice >= 0 and indice < texto.length()){
        indice = texto.find(' ');
        if(indice >= 0 and indice < texto.length()) cantEspacios++;
    }
    cout<<"Cantidad de palabras: "<<cantEspacios+1<<endl;
    cout<<"Cantidad de caracteres: "<<texto.length()<<endl;
    return 0;
}