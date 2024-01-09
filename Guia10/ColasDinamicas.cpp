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
int tamanoCola(Cola);

int main(){
    Cola miCola, frente;
    inicializarCola(miCola,frente);
    encolar(miCola,frente,5);
    encolar(miCola,frente,10);
    encolar(miCola,frente,15);

    cout<<frente->dato<<endl;
    desencolar(miCola,frente);
    cout<<frente->dato<<endl;
    return 0;
}

void inicializarCola(Cola& miCola, Cola& frente){
    miCola = nullptr;
    frente = nullptr;
}

bool estaVacia(Cola miCola){
    return miCola == nullptr;
}

void encolar(Cola& fin,Cola& frente, int elemento){
    Cola nuevo_nodo = new Nodo;
    nuevo_nodo->dato = elemento;
    nuevo_nodo->siguiente = nullptr;

    if(estaVacia(frente)){
        frente = nuevo_nodo;
    }else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}

void desencolar(Cola& fin,Cola& frente){
    Cola aux = frente;
    if(estaVacia(frente)) cout<<"No hay elementos para retirar"<<endl;
    else{
        if(frente == fin){
            frente = fin = NULL;
        }else{
            frente = frente->siguiente;
            delete aux;
        }
    }
    return;
}
