#include <iostream>
using namespace std;

struct Nodo {
    string dato;
    Nodo *siguiente;
};
typedef Nodo* PNodo;
PNodo Lista = NULL;

void mostrarLista(PNodo);
bool buscarElemento(PNodo, string);
void insertarAlFinal(PNodo&,string);
void insertarOrdenado(PNodo&,string);
void insertarAlPrincipio(PNodo&,string);
void insertarPosicion(PNodo&,string,int);
void eliminarTodosLosElementos(PNodo&);
void eliminarElemento(PNodo&,string);
void eliminarUltimaPosicion(PNodo&);
void eliminarPrimerPosicion(PNodo&);
void eliminarPosicion(PNodo&,int);
void eliminarRepetidos(PNodo);
PNodo retornarElemento(PNodo,string);

int main(int argc, char *argv[]) {
    string nombre;
    cout<<"Ingrese una serie de nombres para ordenarlos alfabeticamente"<<endl;
    do{
        getline(cin,nombre);
        if(nombre!= "0") insertarOrdenado(Lista,nombre);
    }while(nombre != "0");
    mostrarLista(Lista);
    return 0;
}

void insertarAlPrincipio(PNodo& lista, string elemento){
    PNodo ptr = new Nodo;
    ptr->dato = elemento;
    ptr->siguiente = lista;
    lista = ptr;
    return;
}

void insertarAlFinal(PNodo& lista, string elemento){
    if(lista == NULL){
        insertarAlPrincipio(lista,elemento);
        return;
    }
    insertarAlFinal(lista->siguiente,elemento);
}

void insertarOrdenado(PNodo& Lista, string elemento){
    PNodo nuevo_elemento = new Nodo;
    nuevo_elemento->dato = elemento;

    PNodo aux1 = Lista;
    PNodo aux2;

    while(aux1 != NULL and aux1->dato < elemento){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

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

PNodo retornarElemento(PNodo lista, string elemento){
    if(lista == NULL) return lista;
    else if (elemento == lista->dato) return lista;
    return retornarElemento(lista->siguiente,elemento);
}

void eliminarElemento(PNodo& lista, string elemento){
    if(lista == NULL) cout<<"Elemento no encontrado"<<endl;
    else if(lista->dato == elemento){
        lista = lista->siguiente;
        return;
    }
    else if (elemento == lista->siguiente->dato) {
        PNodo aux = lista->siguiente;
        lista->siguiente = lista->siguiente->siguiente;
        delete aux;
        return;
    }
    eliminarElemento(lista->siguiente,elemento);
}

bool buscarElemento(PNodo lista, string elemento){
    if(lista == NULL) return false;
    else if (elemento == lista->dato) return true;
    return retornarElemento(lista->siguiente,elemento);
}

void eliminarTodosLosElementos(PNodo& lista){
    if(lista == NULL) return;
    PNodo siguiente = lista->siguiente;
    delete lista;
    lista = nullptr;
    eliminarTodosLosElementos(siguiente);
}

void insertarPosicion(PNodo& lista, string elemento, int posicion){
    if(posicion == 0){
        insertarAlPrincipio(lista,elemento);
        return;
    }
    if(posicion == 1){
        PNodo ptr = new Nodo;
        ptr->dato = elemento;
        ptr->siguiente = lista->siguiente;
        lista->siguiente = ptr;
        return;
    }
    insertarPosicion(lista->siguiente,elemento,--posicion);
}

void eliminarPrimerPosicion(PNodo& lista){
    PNodo aux = lista;
    lista = lista->siguiente;
    delete aux;
}

void eliminarPosicion(PNodo& lista, int posicion){
    if(posicion == 0){
        eliminarPrimerPosicion(lista);
        return;
    }
    if(posicion == 1){
        PNodo aux = lista->siguiente;
        lista->siguiente = lista->siguiente->siguiente;
        delete aux;
        return;
    }
    eliminarPosicion(lista->siguiente,--posicion);
}

void eliminarUltimaPosicion(PNodo& lista){
    if(lista->siguiente == nullptr){
        lista = nullptr;
        return;
    }
    eliminarUltimaPosicion(lista->siguiente);
}

void eliminarRepetidos(PNodo lista){
    if(lista == nullptr) return;
    string dato = lista->dato;
    while(buscarElemento(lista->siguiente,dato)){
        eliminarElemento(lista->siguiente,dato);
    }
    eliminarRepetidos(lista->siguiente);
}