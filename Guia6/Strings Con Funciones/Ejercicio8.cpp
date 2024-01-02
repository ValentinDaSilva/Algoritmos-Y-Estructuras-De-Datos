#include<iostream>
using namespace std;

int main(){
    string texto;
    cout<<"Ingrese el texto para eliminar los ruidos(numeros): ";getline(cin,texto);
    for(int i = 0; i < texto.length(); i++){
        if(isdigit(texto[i])){
            texto.erase(i,1);
            i--;
        }
    }
    cout<<texto<<endl;
    return 0;
}