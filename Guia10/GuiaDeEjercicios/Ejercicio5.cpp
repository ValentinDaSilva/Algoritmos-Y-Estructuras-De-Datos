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

int main(){
    Lista A = NULL, B = NULL;
    cargarLista(A); cargarLista(B);
    
    return 0;
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