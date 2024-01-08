#include<iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

typedef Nodo* Cola; 

void inicializarCola(Cola&,Cola&);
bool estaVacia(Cola);
void encolar(Cola,Cola&,int);
void desencolar(Cola&,Cola&);
int frenteCola(Cola);
int tamanoCola(Cola);

int main(){
    
    return 0;
}