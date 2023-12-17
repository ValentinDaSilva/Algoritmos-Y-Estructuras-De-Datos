#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
void eliminarPosicion(int[],int&,int);
int eliminarMultiplos(int[],int&,int);
void merge(int[],int,int,int,int);
void mergeSort(int[],int,int);

int main(){
    int TL = 30, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    eliminarMultiplos(v,TL,2);
    mergeSort(v,0,TL-1);
    mostrarVector(v,TL);
    return 0;
}

void mergeSort(int v[],int inicio, int final){
   if (final - inicio == 0)
        return;
    else {
        mergeSort (v, inicio, (inicio+final) / 2);
        mergeSort (v,(inicio+final) / 2 + 1, final);
        merge(v, inicio, (inicio+final) / 2, (inicio+final)/ 2 + 1, final);
    }
}

void merge(int v[],int inicio1, int final1, int inicio2, int final2){
    int i = inicio1, j = inicio2, k = 0;
    int v3[final2-inicio1+1];
    while(i <= final1 and j <= final2){
        if(v[i] < v[j]) v3[k++] = v[i++];
        else v3[k++] = v[j++];  
    }
    while(i <= final1){
        v3[k++] = v[i++];
    }
    while(j <= final2){
        v3[k++] = v[j++];
    }
    for(int k = 0; k < (final2 - inicio1 +1); k++){
        v[inicio1 + k] = v3[k];
    }
}

int eliminarMultiplos(int v[], int& TL, int numero){
    int TLinicial = TL;
    for(int i = 0; i < TL; i++){
        if(v[i]%numero == 0){
             eliminarPosicion(v,TL,i);
             i--;
        }
        
    }
    return (TLinicial- TL);
}

void eliminarPosicion(int v[],int& TL,int posicion){
    for(int i = 0; i < TL; i++){
        if(i >= posicion) v[i] = v[i+1];
    }
    TL--;
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