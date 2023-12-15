#include<iostream>
using namespace std;

int conejos(int);

int main(){
    int cantidadDeMeses;
    cout<<"Ingrese un numero N para saber cuantas crias habra al cabo de esos meses: ";cin>>cantidadDeMeses;
    cout<<conejos(cantidadDeMeses)<<endl;
    return 0;
}

int conejos(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return conejos(n-1) + conejos(n-2);
}