#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};
typedef Nodo* Lista;

void cargarLista(Lista&);
void agregarElemento(Lista&,int);
bool estaEnLaLista(Lista,int);
void mostrarLista(Lista);

int main(){
    Lista A, B;
    cargarLista(A);
    mostrarLista(A);
    return 0;
}

void mostrarLista(Lista lista){
    if(lista == nullptr) return ;
    cout<<lista->dato<<endl;
    mostrarLista(lista->siguiente);
}

void cargarLista(Lista& L){
    L = nullptr;
    int dato;
    do{
        cin>>dato;
        if(dato!=0) agregarElemento(L,dato);
    }while(dato!=0);
}

void agregarElemento(Lista& L,int elemento){
    if(!estaEnLaLista(L,elemento)){
        Lista nuevo_elemento = new Nodo;
        nuevo_elemento->dato = elemento;
        nuevo_elemento->siguiente = L;
        L = nuevo_elemento;
    }
}

bool estaEnLaLista(Lista lista, int elemento){
    if(lista == nullptr) return false;
    if(lista->dato == elemento) return true;
    return estaEnLaLista(lista->siguiente,elemento);
}