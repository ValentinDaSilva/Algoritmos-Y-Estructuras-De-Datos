#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};
typedef Nodo* Lista;

void mostrarLista(Lista);
void cargarLista(Lista&);
void agregarElemento(Lista&,int);
void eliminarNodo(Lista,Lista);
void verificarCreciente(Lista);

int main(){
    Lista numeros;
    cargarLista(numeros);
    verificarCreciente(numeros);
    mostrarLista(numeros);
    return 0;
}

void verificarCreciente(Lista lista){
    if(lista == nullptr) return;
    while((lista ->siguiente != nullptr) and (lista->dato > lista->siguiente->dato)){
        eliminarNodo(lista,lista->siguiente);
    }
    verificarCreciente(lista->siguiente);
}

void eliminarNodo(Lista lista, Lista nodo) {
    if (lista == nullptr || nodo == nullptr) {
        cout << "Error: Lista vacía o nodo a eliminar inválido" << endl;
        return;
    }

    if (lista->siguiente == nodo) {
        Lista aux = lista->siguiente;
        lista->siguiente = lista->siguiente->siguiente;
        delete aux;
        return;
    }

    eliminarNodo(lista->siguiente, nodo);
}

void cargarLista(Lista& L){
    L = nullptr;
    int dato;
    while(cin>>dato){
        agregarElemento(L,dato);
    }
}

void agregarElemento(Lista& L,int elemento){
    if(L == nullptr){
        Lista nuevo_elemento = new Nodo;
        nuevo_elemento->dato = elemento;
        nuevo_elemento->siguiente = nullptr;
        L = nuevo_elemento;
        return;
    }
    agregarElemento(L->siguiente,elemento);
}

void mostrarLista(Lista lista){
    if(lista == nullptr){
         cout<<endl;
         return ;
    }
    cout<<lista->dato<<" ";
    mostrarLista(lista->siguiente);
}