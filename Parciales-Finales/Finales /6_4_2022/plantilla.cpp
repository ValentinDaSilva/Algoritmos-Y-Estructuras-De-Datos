#include<iostream>
#include<cstring>
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
    for(int i=0, j=5; ; i++, j--) {cout << i << "  " << j << endl;}
    return 0;
}