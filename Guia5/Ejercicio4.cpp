#include<iostream>
#include<iomanip>
using namespace std;

void mostrarVector(float[],int);
void random(float[],int);
int minimoDelVector(float[],int);
int maximoDelVector(float[],int);
void normalizarVector(float[],int);

int main(){
    int TL = 10;
    float v[TL];
    random(v,TL);
    cout<<"Vector: "; mostrarVector(v,TL);
    normalizarVector(v,TL);
    cout<<"Vector Normalizado: "; mostrarVector(v,TL);
    return 0;
}

void normalizarVector(float v[],int TL){
    int Max = maximoDelVector(v,TL), Min = minimoDelVector(v,TL);
    for(int i = 0 ; i < TL; i++){
        v[i] = ((v[i] - Min) / (float)(Max - Min))*100;
    }
}

int maximoDelVector(float v[],int TL){
    int mayor;
    for(int i = 0; i < TL; i++){
        if(i == 0) mayor = v[i];
        else{
            if(v[i] > mayor) mayor = v[i];
        } 
    }
    return mayor;
}

int minimoDelVector(float v[],int TL){
    int menor;
    for(int i = 0; i < TL; i++){
        if(i == 0) menor = v[i];
        else if(v[i] < menor) menor = v[i]; 
    }
    return menor;
}

void random(float v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%100;
    }
}

void mostrarVector(float v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<fixed<<setprecision(2)<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}