#include<iostream>
using namespace std;
//Uno dos listas y no deben tener repetidos

struct Nodo{
    string dato;
    Nodo* siguiente;
};
typedef Nodo* Lista;

void cargarLista(Lista&);
void agregarElemento(Lista&,string);
bool estaEnLaLista(Lista,string);
void mostrarLista(Lista);
void unirListas(Lista,Lista&);

int main(){
    Lista A, B;
    cargarLista(A);
    cargarLista(B);
    unirListas(A,B);
    mostrarLista(B);
    return 0;
}

void unirListas(Lista A, Lista& B){
    if(A == nullptr) return;
    Lista siguiente = A->siguiente;
    string dato = A->dato;
    agregarElemento(B,dato);
    delete A;
    unirListas(siguiente,B);
}


void mostrarLista(Lista lista){
    if(lista == nullptr) return ;
    cout<<lista->dato<<endl;
    mostrarLista(lista->siguiente);
}

void cargarLista(Lista& L){
    L = nullptr;
    string dato;
    do{
        getline(cin,dato);
        if(dato!="0") agregarElemento(L,dato);
    }while(dato!="0");
}

void agregarElemento(Lista& L,string elemento){
    if(!estaEnLaLista(L,elemento)){
        Lista nuevo_elemento = new Nodo;
        nuevo_elemento->dato = elemento;
        nuevo_elemento->siguiente = L;
        L = nuevo_elemento;
    }
}

bool estaEnLaLista(Lista lista, string elemento){
    if(lista == nullptr) return false;
    if(lista->dato == elemento) return true;
    return estaEnLaLista(lista->siguiente,elemento);
}