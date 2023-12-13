#include<iostream>
using namespace std;

int main(){
    int numero;
    char caracter;
    cout<<"Ingrese un numero: ";cin>>numero;
    cout<<"Ingrese un caracter: ";cin>>caracter;
    for(int i = 0; i < numero; i++){    
        for(int j = 0; j < numero; j++){
            cout<<caracter;
        }
        cout<<endl;
    }
    return 0;
}