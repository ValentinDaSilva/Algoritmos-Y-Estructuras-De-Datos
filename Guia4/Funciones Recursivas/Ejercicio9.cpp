#include<iostream>
using namespace std;

int BinarioADecimal(int);

int main(){
    int numero;
    cout<<"Ingrese un numero binario para convertirlo a decimal: ";cin>>numero;
    cout<<BinarioADecimal(numero)<<endl;
    return 0;
}

int BinarioADecimal(int numero){
    if(numero < 10) return numero;
    return 2 * BinarioADecimal(numero/10) + numero%10 ;
}