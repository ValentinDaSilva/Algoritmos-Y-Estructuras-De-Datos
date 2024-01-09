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
int tamanoCola(Cola,Cola);

int main(){
    Cola fin, frente;
    inicializarCola(frente,fin);
    encolar(frente,fin,5);
    encolar(frente,fin,10);
    encolar(frente,fin,15);
    tamanio(frente,fin);
    cout<<frente->dato<<endl;
    desencolar(frente,fin);
    cout<<frente->dato<<endl;
    return 0;
}

void inicializarCola(Cola& frente, Cola& fin){
    frente = nullptr;
    fin = nullptr;
}

bool estaVacia(Cola frente){
    return frente == nullptr;
}

void encolar(Cola& frente,Cola& fin, int elemento){
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

void desencolar(Cola& frente,Cola& fin){
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

int tamanio(Cola frente, Cola fin){
    if(frente = fin) return 1;
    return 1 + tamanio(fin, frente->siguiente);
}