#include<iostream>
using namespace std;

struct NODO {
    int dato;
    NODO* siguiente = NULL;
};
typedef NODO* Nodo;

void agregarNodo(NODO*& lista){
    Nodo nuevo_nodo = new NODO;
    nuevo_nodo->dato = 1;
    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
}
int main(){
    Nodo lista = new NODO;
    lista->dato = 5;
    agregarNodo(lista);
    cout<<lista->dato<<endl;
    cout<<lista->siguiente->dato<<endl;
    return 0;
}