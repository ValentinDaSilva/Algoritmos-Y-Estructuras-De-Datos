#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void eliminarPrimeraPosicion(int[],int);
int eliminarImparesEntrePares(int[],int);

int main(){
    int TL = 10, v[TL] = {1, 2, 3, 4, 7, 9, 12, 14, 15, 20};
    TL -= eliminarImparesEntrePares(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    return 0;
}

int eliminarImparesEntrePares(int v[],int TL){
    if(TL <= 2) return 0;
    if(v[0]%2 == 0 and v[1]%2 != 0 and v[2]%2 == 0){
        eliminarPrimeraPosicion(&v[1],TL-1);
        TL-=1;
        return 1 + eliminarImparesEntrePares(&v[1],--TL);
    }
    return 0 + eliminarImparesEntrePares(&v[1],--TL);
}

void eliminarPrimeraPosicion(int v[],int TL){
    if(TL == 1) return;
    v[0] = v[1];
    eliminarPrimeraPosicion(&v[1],--TL);
}

void mostrarVector(int v[],int TL){
    if(TL == 0) cout<<"]"<<endl;
    else{
        cout<<v[0]<<" ";
        mostrarVector(&v[1],TL-1);
    }
}