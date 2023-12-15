#include<iostream>
using namespace std;

int cantDigitos(int);
int cantDigPares(int);
bool tieneDigPares(int);
int sumaDigMul(int,int);

int main(){
    int numero,multiplo;
    cout<<"Ingrese un numero: ";cin>>numero;
    cout<<"Ingrese un numero para sumar los multiplos de el: ";cin>>multiplo;
    cout<<"Cantidad de digitos: "<<cantDigitos(numero)<<endl;
    cout<<"Tiene Digitos Pares?: "<<boolalpha<<tieneDigPares(numero)<<endl;
    cout<<"Cantidad de digitos Pares: "<<cantDigPares(numero)<<endl;
    cout<<"Suma de los numeros multiplos de "<<multiplo<<": "<<sumaDigMul(numero,multiplo)<<endl;
    return 0;
}

int cantDigitos(int numero){
    if(numero < 10) return 1;
    return 1 + cantDigitos(numero/10);
}

int cantDigPares(int numero){
    if(numero < 10){
        if(numero%10%2 == 0) return 1;
        else return 0;
    }
    if(numero%10%2 == 0) return 1 + cantDigPares(numero/10);
    else return cantDigPares(numero/10);
}

bool tieneDigPares(int numero){
    if(numero < 10){
        if(numero%10%2 == 0) return true;
        return false;
    }
    if(numero%10%2 == 0) return true;
    return tieneDigPares(numero/10);
}

int sumaDigMul(int numero, int multiplo){
    if(numero < 9){
        if(numero%10%multiplo == 0) return numero%10;
        return 0;
    }
    if(numero%10%multiplo == 0) return numero%10 + sumaDigMul(numero/10,multiplo);
    return sumaDigMul(numero/10,multiplo);
}