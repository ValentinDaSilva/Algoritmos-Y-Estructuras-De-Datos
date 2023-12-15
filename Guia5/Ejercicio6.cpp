#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
bool esSumaDeAlguno(int[],int,int);

int main(){
    int TL = 10, v[TL], numero;
    inicializar_teclado(v,TL);
    do{
        cin >> numero;  
    } while (esSumaDeAlguno(v,TL,numero));
    return 0;
}

int sumaDigitos(int numero){
    if(numero<10) return numero;
    return numero%10 + sumaDigitos(numero/10);
}

bool esSumaDeAlguno(int v[],int TL, int elemento){
    int suma, i = 0;
    bool esIgual = false;
    while(!esIgual and i < TL){
        suma = sumaDigitos(v[i]);
        if(suma == elemento) esIgual = true;
    }
    return esIgual;
}

void inicializar_teclado(int v[], int TL){
    for(int i = 0; i < TL; i++){
        cin>>v[i];
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}
