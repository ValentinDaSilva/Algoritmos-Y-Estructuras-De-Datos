#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void inicializar_teclado(int[],int);
bool quini6(int[],int[],int);

int main(){
    int TL = 6, v1[TL], v2[TL],numero;
    random(v2,TL);
    mostrarVector(v2,TL);
    cout<<"Inserte su numero de jugador: ";cin>>numero;
    cout<<"Elija los numeros que quiere jugar en el Quini 6 (6): "<<endl;
    inicializar_teclado(v1,TL);
    if(quini6(v1,v2,TL)) cout<<numero<<endl;
    else cout<<"Perdio!"<<endl;
    return 0;
}

bool quini6(int v1[],int v2[],int TL){
    int i = 0;
    bool estaEnElVector = false;
    while(i < TL and !estaEnElVector){
        int j = 0;
        while(j < TL and !estaEnElVector){
            if(v1[i] == v2[j]) estaEnElVector = true;
            j++;
        }   
        i++;
    }
    return estaEnElVector;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%45;
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}

void inicializar_teclado(int v[], int TL){
    for(int i = 0; i < TL; i++){
        cin>>v[i];
    }
}