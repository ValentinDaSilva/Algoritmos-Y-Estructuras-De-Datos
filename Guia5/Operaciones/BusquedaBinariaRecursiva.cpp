#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void random(int[],int);
bool busquedaBinaria(int[],int,int);

int main(){
    int TL = 7, v[TL] = {1,2,3,4,5,6,7};
    int elemento;
    cout<<"Elemento: ";
    while(cin>>elemento){
        cout<<boolalpha<<busquedaBinaria(v,TL,elemento)<<endl;
        main();
    }
    return 0;
}

bool busquedaBinaria(int v[],int TL, int elemento){
    if(v[TL/2] == elemento) return true;
    if(TL == 0 or TL == 1) return false;
    int med = TL/2;
    if(TL%2 != 0 and v[med] < elemento) med+=1;
    if(v[TL/2] > elemento) return busquedaBinaria(v,med,elemento);    
    return busquedaBinaria(&v[med],med,elemento);
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