#include<iostream>
#include<ctime>
using namespace std;

void inicializar_teclado(int[],int);
void mostrarVector(int[],int);
void random(int[],int);
int mayorEnRango(int[],int);

int main(){
    int TL = 10,v[TL],inf,sup;
    random(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    cout<<"Ingrese el intervalo en los que quiere buscar el mayor elemento: ";cin>>inf>>sup;
    cout<<mayorEnRango(&v[inf],sup)<<endl;
    return 0;
}

int mayorEnRango(int v[],int TL){
    if(TL == 1) return v[0];
    else{
        int resto = mayorEnRango(&v[1],TL-1);
        if(v[0] > resto) return v[0];
        else return resto;
    }
}

void mostrarVector(int v[],int TL){
    if(TL == 0) cout<<"]"<<endl;
    else{
        cout<<v[0]<<" ";
        mostrarVector(&v[1],TL-1);
    }
}

void inicializar_teclado(int v[],int TL){
    if(TL == 0) return;
    cin >> v[0];
    inicializar_teclado(&v[1],TL-1);
}

void random(int v[],int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++)
        v[i] = rand()%50;
}