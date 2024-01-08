#include<iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

typedef Nodo* Pila; 

void inicializarPila(Pila&);
bool estaVacia(Pila);
void apilar(Pila&,int);
void desapilar(Pila&);
int elementoCima(Pila);
int tamanoPila(Pila);


int main(){
    
    return 0;
}