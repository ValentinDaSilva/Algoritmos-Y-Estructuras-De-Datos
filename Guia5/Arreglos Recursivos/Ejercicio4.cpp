#include<iostream>
#include<ctime>
using namespace std;


void mostrarVector(float[],int);
void random(float[],int);
void modificar(float[],int,float,float);
float menorEnElVector(float[],int);
float mayorEnElVector(float[],int);

int main(){
    int TL = 10;
    float v[TL],menor,mayor;
    random(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    menor = menorEnElVector(v,TL);
    mayor = mayorEnElVector(v,TL);
    modificar(v,TL,mayor,menor);
    cout<<"[ ";mostrarVector(v,TL);

    return 0;
}

void modificar (float v[],int TL, float mayor, float menor){
    if(TL == 0) return;
    else{
        v[0] = ((v[0] - menor) / (mayor - menor))*100;
        modificar(&v[1],TL-1,mayor,menor);
    }
}

float mayorEnElVector(float v[],int TL){
    if(TL == 1) return v[0];
    else{
        int resto = mayorEnElVector(&v[1],TL-1);
        if(v[0] > resto) return v[0];
        else return resto;
    }
}

float menorEnElVector(float v[],int TL){
    if(TL == 1) return v[0];
    else{
        int resto = menorEnElVector(&v[1],TL-1);
        if(v[0] < resto) return v[0];
        else return resto;
    }
}

void mostrarVector(float v[],int TL){
    if(TL == 0) cout<<"]"<<endl;
    else{
        cout<<v[0]<<" ";
        mostrarVector(&v[1],TL-1);
    }
}

void random(float v[],int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++)
        v[i] = rand()%50;
}