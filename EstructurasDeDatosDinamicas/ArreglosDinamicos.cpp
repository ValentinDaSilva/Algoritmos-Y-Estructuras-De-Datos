#include<iostream>
using namespace std;
typedef int* PInt;

void mostrarVector(int[],int);
void random(int[],int);

int main(){
    int Tam;
    cout<<"Ingrese la cantidad de elementos que quiere ingresar: ";cin>>Tam;
    PInt v = new int[Tam];
    random(v,Tam);
    mostrarVector(v,Tam);
    return 0;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%50;
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}