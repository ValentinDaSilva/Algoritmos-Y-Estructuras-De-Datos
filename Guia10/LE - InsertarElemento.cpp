#include <iostream>
using namespace std;

struct Nodo {
    string dato;
    Nodo *siguiente;
};
typedef Nodo* PNodo;
PNodo Lista = NULL;
//a
void insertarElemento(PNodo& Lista, string elemento){
    PNodo nuevo_elemento = new Nodo;
    nuevo_elemento->dato = elemento;

    PNodo aux1 = Lista;
    PNodo aux2;

    while(aux1 != NULL and aux1->dato < elemento){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    //asd
    if(aux1 == Lista){
        Lista = nuevo_elemento;
    }else{
        aux2->siguiente = nuevo_elemento;
    }
    nuevo_elemento->siguiente = aux1;
}

void mostrarLista(PNodo lista){
    if(lista == NULL) cout<<endl;
    else{
        cout<<"\n"<<lista->dato;
        mostrarLista(lista->siguiente);
    }
}

int main(int argc, char *argv[]) {
    string nombre;
    cout<<"Ingrese una serie de nombres para ordenarlos alfabeticamente"<<endl;
    do{
        getline(cin,nombre);
        if(nombre!= "0") insertarElemento(Lista,nombre);
    }while(nombre != "0");
    mostrarLista(Lista);
    return 0;
}