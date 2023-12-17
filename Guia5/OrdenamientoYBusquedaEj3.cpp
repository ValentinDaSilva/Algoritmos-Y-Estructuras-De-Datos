#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int); 
void Uno(int[],int[],int,int,bool);
void intercambiar(int[],int,int);
bool estaEnElVector(int[],int,int);

int main(){
    int TL1 = 10, TL2 = 10,v1[TL1] = {0, 3, 4, 6, 7, 0, 7, 2, 6, 8},v2[TL2]={2, 9, 9, 5, 9, 7, 2, 3, 2, 1};
    bool c;
    mostrarVector(v1,TL1);mostrarVector(v2,TL2);
    Uno(v1,v2,TL1,TL2,c);
    return 0;
}

void Uno(int v1[],int v2[],int TL1, int TL2, bool c){
    int TL3 = 0,v3[TL1+TL2];
    for(int i = 0; i < TL2; i++){
        if(estaEnElVector(v1,TL1,v2[i]) and !estaEnElVector(v3,TL3,v2[i])){
            v3[TL3] = v2[i];
            TL3++;
        }
    }
    int intercambios = 1, k = 0;                                                                                                         
    while(intercambios!=0 and k < TL3){
        intercambios = 0;
        for(int i = 0; i < TL3-(1 + k); i++){
            if(v3[i] > v3[i+1]){
                intercambiar(v3,i,i+1);
                intercambios++;
            }
        }
        k++;
    }
    mostrarVector(v3,TL3);
}

void intercambiar(int v[],int pos1,int pos2){
    int aux= v[pos1];
    v[pos1]=v[pos2];
    v[pos2]=aux;
}

bool estaEnElVector(int v[],int TL, int elemento){
    bool encontrado = false;
    int i = 0;
    while(i < TL and !encontrado){
        if(v[i] == elemento) encontrado = true;
        i++;
    }
    return encontrado;
}

void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%10;
    }
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}