#include<iostream>
using namespace std;

void random(int[],int);
void mostrarVector(int[],int);
void eliminarPosicion(int[],int,int);
int estaEnElVector(int[],int,int);
void eliminarRepetidos(int[],int,int&);
int sumaLista(int[],int);

int main(){
    int TL = 10, v[10], cantEliminados = 0,posicion;
    random(v,TL);
    cout<<"[ ";mostrarVector(v,TL);
    eliminarRepetidos(v,TL,cantEliminados);
    TL -= cantEliminados;
    cout<<"[ ";mostrarVector(v,TL);
    cout<<"Promedio Lista: "<<sumaLista(v,TL)/(float)TL<<endl;
    if(cin>>posicion) main();
    return 0;
}

int sumaLista(int v[],int TL){
    if(TL == 0) return 0;
    return v[0] + sumaLista(&v[1],--TL);
}

void eliminarRepetidos(int v[],int TL,int& cantEliminados){
    if(TL == 0) return;
    int x = estaEnElVector (&v[1],TL-1,v[0]);
    if(x < TL - 1) {
        eliminarPosicion(&v[1],TL-1,x);
        cantEliminados++;
        eliminarRepetidos(&v[1],TL-2,cantEliminados);
    }else{
        eliminarRepetidos(&v[1],--TL,cantEliminados);
    }
    
}

int estaEnElVector(int v[],int TL,int elemento){
    if(TL == 0) return 1;
    if(v[0] == elemento) return 0;
    return 1 + estaEnElVector(&v[1],--TL,elemento);
}

void eliminarPosicion(int v[],int TL,int posicion){
    if(TL == 1) return;
    else if(posicion != 0) eliminarPosicion(&v[1],TL-1,posicion-1);
    else if(posicion == 0){
        v[0] = v[1];
        eliminarPosicion(&v[1],--TL, 0);
    }
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