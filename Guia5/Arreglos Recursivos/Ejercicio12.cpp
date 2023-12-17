#include<iostream>
using namespace std;

void inicializar_teclado(int[],int);
void mostrarVector(int[],int);
void random(int[],int);
bool quini6(int[],int[],int);
bool estaEnElVector(int[],int,int);
int main(){
    int TL = 6,nJ[6],nS[6], numeroJugador;
    random(nS,TL);
    cout<<"[ ";mostrarVector(nS,TL);
    cout<<"Ingrese su numero de jugador: ";cin>>numeroJugador;
    cout<<"Ingrese los 6 numeros que quiere jugar"<<endl; inicializar_teclado(nJ,TL);
    if(quini6(nJ,nS,TL)) cout<<numeroJugador<<endl;
    else cout<<"Tus numeros no salieron elejidos, perdiste"<<endl;
    return 0;
}

bool quini6(int nJ[],int nS[], int TL){
    if(TL == 0) return false;
    if(estaEnElVector(nS,6,nJ[0])) return true;
    return quini6(&nJ[1],nS,TL-1);
}

bool estaEnElVector(int v[],int TL,int elemento){
    if(TL == 0) return false;
    if(v[0] == elemento) return true;
    return estaEnElVector(&v[1],--TL,elemento);
}

void random(int v[],int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++)
        v[i] = rand()%45;
}

void inicializar_teclado(int v[],int TL){
    if(TL == 0) return;
    cin >> v[0];
    inicializar_teclado(&v[1],TL-1);
}

void mostrarVector(int v[],int TL){
    if(TL == 0) cout<<"]"<<endl;
    else{
        cout<<v[0]<<" ";
        mostrarVector(&v[1],TL-1);
    }
}