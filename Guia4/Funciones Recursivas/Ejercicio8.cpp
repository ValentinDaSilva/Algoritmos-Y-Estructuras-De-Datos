#include<iostream>
using namespace std;

void decABinario(int);

int main(){
    int numero;
    cout<<"Ingrese un numero para convertirlo a binario: ";cin>>numero;
    decABinario(numero);
    cout<<endl;
    return 0;
}

void decABinario(int numero){
    if(numero == 1) cout<<numero;
    else{
        decABinario(numero/2);
        cout<<numero%2;
    }
}