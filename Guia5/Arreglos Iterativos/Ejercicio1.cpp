#include<iostream>
#include<ctime>
using namespace std;

void inicializar_teclado(int[],int);
void inicializacion_random(int[],int);
void mostrarVector(int[],int);

int main(){
    //Carga al inicializar
    int v[5] = {1,2,3,4,5}, TL = 5;
    //Inicializar por teclado
    inicializar_teclado(v,TL);
    //Inicializar con valores aleatorios
    inicializacion_random(v,TL);
    //Mostrar el vector
    mostrarVector(v,TL);
    return 0;
}

void inicializar_teclado(int v[], int TL){
    for(int i = 0; i < TL; i++){
        cin>>v[i];
    }
}

void inicializacion_random(int v[], int TL){
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

