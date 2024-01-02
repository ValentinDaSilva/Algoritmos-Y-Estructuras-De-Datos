#include<iostream>
using namespace std;

int main(){
    string texto;
    int desplazamiento;
    cout<<"Ingrese el texto a cifrar: ";getline(cin,texto);
    cout<<"Ingrese el numero de desplazamiento para cada caracter: "; cin>>desplazamiento;
    for(int i = 0; i < texto.length(); i++){
        if(texto[i] != ' ') texto[i] += desplazamiento;
    }
    cout<<texto<<endl;
    return 0;
}