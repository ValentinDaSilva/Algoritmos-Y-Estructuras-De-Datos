#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void inicializar_teclado(int[],int);
bool todos_iguales(int[],int);

int main(){
    int TL = 5, v[TL];
    inicializar_teclado(v,TL);
    cout<<todos_iguales(v,TL)<<endl;
    if(cin>>TL) main();
    return 0;
}

bool todos_iguales(int v[],int TL){
    int i = 0;
    bool todosIguales = true;
    while(todosIguales and i < (TL - 1)){
        if(v[i] != v[i+1]) todosIguales = false;
        i++;
    }
    return todosIguales;
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