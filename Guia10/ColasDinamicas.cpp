#include<iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

typedef Nodo* Cola; 

void inicializarCola(Cola&,Cola&);
bool estaVacia(Cola);
void encolar(Cola&,Cola&,int);
void desencolar(Cola&,Cola&);
int tope(Cola);
int tamanoCola(Cola);

int main(){
    Cola miCola, frente;
    
    return 0;
}

void inicializarCola(Cola& miCola, Cola& frente){
    miCola = nullptr;
    frente = nullptr;
}

bool estaVacia(Cola miCola){
    return miCola == nullptr;
}

void encolar(Cola& frente,Cola& fin, int elemento){
    Cola nuevo_nodo = new Nodo;
    nuevo_nodo->dato = elemento;
    nuevo_nodo->siguiente = nullptr;

    if(estaVacia(frente)){
        fin = frente = nuevo_nodo;
    }else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;

}
