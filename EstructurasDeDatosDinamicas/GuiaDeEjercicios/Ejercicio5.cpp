#include<iostream>
using namespace std;
int cantNodos;

struct Nodo{
    int numero;
    char letra;
    Nodo* siguiente;
};
typedef Nodo* Lista;

void cargarLista(Lista&);
void mostrarLista(Lista);
void actualizarListas(Lista,Lista);
bool estaEnLaLista(Lista,int);

int main(){
    Lista A = NULL, B = NULL;
    cout<<"Ingrese cantidad de nodos: ";cin>>cantNodos;
    cargarLista(A); cargarLista(B);
    mostrarLista(A); mostrarLista(B);
    cout<<"\nLista actualizada: "<<endl;
    actualizarListas(A,B);
    mostrarLista(A);
    return 0;
}

void actualizarListas(Lista A, Lista B){
    if(A == NULL) return;
    if(estaEnLaLista(B,A->numero)){
        A->letra += 1;
        if(A->letra > 'z') A->letra -= 'z'; 
    }
    actualizarListas(A->siguiente,B);
}

bool estaEnLaLista(Lista lista, int elemento){
    if(lista == NULL) return false;
    if(lista->numero == elemento) return true;
    return estaEnLaLista(lista->siguiente,elemento);
}

void cargarLista(Lista& lista){
    for(int i = 0; i < cantNodos; i++){
        Lista nuevo_nodo = new Nodo;
        nuevo_nodo->numero = rand()%100;
        nuevo_nodo->letra = 'a' + (rand() % ('z' - 'a'));
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;  
    }
}

void mostrarLista(Lista lista){
    if(lista == NULL){
        cout<<endl;
        return;
    }
    cout<<"[ "<<lista->numero<<" "<<lista->letra<<" ]  ";
    mostrarLista(lista->siguiente);
}
