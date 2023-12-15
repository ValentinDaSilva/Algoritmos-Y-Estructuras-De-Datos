#include<iostream>
using namespace std;

int potencia(int,int);

int main(){
    int n1,n2;
    cout<<"Ingrese dos numeros para calcular la potencia: ";cin>>n1>>n2;
    cout<<"Resultado = "<<potencia(n1,n2)<<endl;
    return 0;
}

int potencia(int n1,int n2){
    if(n2 == 1) return n1;
    return n1 * potencia(n1,n2-1);
}