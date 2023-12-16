#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
int cantRepetidosMas10(int[],int);
void mergeSort(int[],int,int);
void merge(int[],int,int,int,int);

int main(){
    int TL = 1000, v[TL];
    random(v,TL);
    mergeSort(v,0,TL-1);
    mostrarVector(v,TL);
    cout<<cantRepetidosMas10(v,TL)<<endl;
    return 0;
}

void merge(int v[],int inicio1, int final1, int inicio2, int final2){
    int i = inicio1, j = inicio2, k = 0;
    int v2[final2-inicio1+1];
    while(i <= final1 and j <=final2){
        if(v[i] < v[j]) v2[k++] = v[i++];
        else v2[k++] = v[j++];
    }
    while(i <= final1) v2[k++] = v[i++];
    while(j <= final2) v2[k++] = v[j++];
    for(int k = 0; k < (final2 - inicio1 +1); k++){
        v[inicio1 + k] = v2[k];
    }
}

void mergeSort(int v[],int inicio, int final){
    if(final - inicio == 0) return;
    else{
        int med = (final + inicio) / 2;
        mergeSort(v, inicio, med);
        mergeSort(v,med+1,final);
        merge(v,inicio,med,med+1,final);
    }
}

int cantRepetidosMas10(int v[],int TL){
    int cantRepetidos = 0, cantRepetidosAux = 0;
    for(int i = 0; i < TL; i++){
        if(v[i] == v[i+1]) cantRepetidosAux++;
        else{
            cantRepetidosAux++;
            if(cantRepetidosAux >= 10) cantRepetidos++;
            cantRepetidosAux = 0;
        }
    }
    return cantRepetidos;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%100;
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}