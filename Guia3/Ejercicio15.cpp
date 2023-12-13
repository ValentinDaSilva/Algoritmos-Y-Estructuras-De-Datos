#include<iostream>
using namespace std;

int main(){
    int valor1, valor2;
    cout<<"Ingrese el valor de inicio: ";cin>>valor1;
    cout<<"Ingrese el valor final: ";cin>>valor2;
    for(int i=valor2; i >= valor1; i--){
        cout<<i<<" ";
    }
    return 0;
}