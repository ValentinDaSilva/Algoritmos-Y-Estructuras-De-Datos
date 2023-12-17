#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void inicializar_teclado(int[],int);
bool todos_distintos(int[],int);

int main(){
    int TL = 5, v[TL];
    inicializar_teclado(v,TL);
    cout<<todos_distintos(v,TL)<<endl;
    if(cin>>TL) main();
    return 0;
}

bool todos_distintos(int v[],int TL){
    int i = 0;
    bool todosDistintos = true;
    while(todosDistintos and i < (TL - 1)){
        int j = 0;
        while(todosDistintos and j < TL){
            if(i != j){
                if(v[i] == v [j]) todosDistintos = false;
            }
            j++;
        }
        i++;
    }
    return todosDistintos;
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