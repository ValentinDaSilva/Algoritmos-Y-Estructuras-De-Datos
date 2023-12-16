#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void merge(int[],int,int,int,int);
void mergesort(int[],int,int);
void random(int[],int);

int main(){
    int TL = 10, v[TL];
    random(v,TL);
    mostrarVector(v,TL);
    mergesort(v,0,TL-1);
    mostrarVector(v,TL);
    return 0;
}

void mergesort (int v[], int inicio, int final) { 
    if (final - inicio == 0)
        return;
    else {
        mergesort (v, inicio, (inicio+final) / 2);
        mergesort (v,(inicio+final) / 2 + 1, final);
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

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%10;
    }
}