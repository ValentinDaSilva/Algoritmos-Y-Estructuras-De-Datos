#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void inicializar_teclado(int[],int);
int modificarLista(int[],int&);
void insertarElemento(int[],int&, int, int);

int main(){
    int TL = 10, v[20] = {1,2,300,4,5,6,700,8,9,10};
    cout<<"Cantidad de agregados: "<<modificarLista(v,TL)<<endl;
    mostrarVector(v,TL);
    return 0;
}

int modificarLista(int v[], int& TL){
    int cantAgregados = 0;
    for(int i = 0; i < TL; i++){
        if(v[i]%100 == 0){
            insertarElemento(v,TL,v[i]+1,i);
            i++;
            cantAgregados++;
        }
    }
    return cantAgregados;
}

void insertarElemento(int v[],int& TL, int elemento, int posicion){
    for(int i = TL ; i > posicion; i--){
        v[i] = v[i - 1];
    }
    v[posicion] = elemento;
    TL++;
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