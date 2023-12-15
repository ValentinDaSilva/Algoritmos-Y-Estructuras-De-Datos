#include<iostream>
using namespace std;

void inverso(int);

int main(){
    int numero;
    cout<<"Ingrese un numero para invertir: ";cin>>numero;
    inverso(numero);
    return 0;
}

void inverso(int numero){
    if(numero < 10) cout<<numero<<endl;
    else{
        cout<<numero%10<<" ";
        inverso(numero/10);
    }
}

