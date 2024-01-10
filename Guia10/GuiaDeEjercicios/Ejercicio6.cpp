#include<iostream>
using namespace std;
int dimensiones;

struct Nodo {
    int elemento;
    Nodo* siguiente;
};
typedef Nodo* Lista;

struct PILA {
    int suma, fila;
    PILA* siguiente;
};
typedef PILA* PPila;

struct MATRIZ {
    int fila, suma;
    MATRIZ* siguiente;
};
typedef MATRIZ* Matriz;

void buscarAislados(int**,Lista&);
void agregarNodo(Lista&,int);
void apilar(PPila&,int,int);
void desapilar(PPila&);
void mostrarLista(Lista);
void cargarMatriz(int**);
void mostrarMatriz(int**);
void cargarPila(int**,PPila&);
void agregarNodoAMatriz(Matriz&,int,int);
void mostrarPila(PPila);


int main(){
    int ** M;
    Lista listaAislados = NULL;
    PPila sumaFilas = NULL;
    cout<<"Ingrese la cantidad de filas y columnas: ";cin>>dimensiones;
    M = new int* [dimensiones];
    for(int i = 0; i < dimensiones; i++) M[i] = new int[dimensiones];
    cargarMatriz(M);
    mostrarMatriz(M);
    buscarAislados(M,listaAislados);
    cout<<"L";mostrarLista(listaAislados);
    cargarPila(M,sumaFilas);
    cout<<"P";mostrarPila(sumaFilas);
    return 0;
}

void buscarAislados(int** M , Lista& listaAislados){
    for(int i = 0; i < dimensiones; i++){
        for(int j = 0; j < dimensiones - 2; j++){
            if(*(*(M + i) + j + 1) != *(*(M + i) + j) and *(*(M + i) + j + 1) != *(*(M + i) + j + 2)){
                agregarNodo(listaAislados,*(*(M + i) + j + 1));
            }
        }
    }
}

void agregarNodo(Lista& lista, int dato){
    Lista nuevo_nodo = new Nodo;
    nuevo_nodo->elemento = dato;
    nuevo_nodo->siguiente = NULL;

    if(lista == NULL) lista = nuevo_nodo;
    else{
        Lista aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    } 
}

void apilar(PPila& miPila, int suma, int fila){
    PPila nuevo_nodo = new PILA;
    nuevo_nodo->suma = suma;
    nuevo_nodo->fila = fila;
    nuevo_nodo->siguiente = miPila;
    miPila = nuevo_nodo;
}

void desapilar(PPila& miPila){
    PPila aux = miPila;
    miPila = miPila->siguiente;
    delete aux;
}

void mostrarLista(Lista lista){
    if(lista == NULL){
        cout<<" -> NULL"<<endl;
        return;
    }
    cout<<" -> "<<lista->elemento;
    mostrarLista(lista->siguiente);
}

void cargarMatriz(int** M){
    for(int i = 0; i < dimensiones; i++){
        for(int j = 0; j < dimensiones; j++){
            cin>>*(*(M + i) + j);
        }
    }
}

void mostrarMatriz(int** M){
    for(int i = 0; i < dimensiones; i++){
        cout<<"[ ";
        for(int j = 0; j < dimensiones; j++){
            cout<<*(*(M + i) + j)<<" ";
        }
        cout<<"]"<<endl;
    }
}

void cargarPila(int** M,PPila& miPila){
    int suma = 0;
    Matriz sumaPorFilas = NULL;
    for(int i = 0 ; i < dimensiones; i++){
       for(int j = 0; j < dimensiones ; j++){
            suma += M[i][j];
       }
       agregarNodoAMatriz(sumaPorFilas,i,suma);
       suma = 0;
    }
    while(sumaPorFilas != NULL){
        cout<<"Entre"<<endl;
        apilar(miPila, sumaPorFilas->suma, sumaPorFilas->fila);
        sumaPorFilas = sumaPorFilas->siguiente;
    }

}

void agregarNodoAMatriz(Matriz& lista, int fila, int suma){
    Matriz nuevo_nodo = new MATRIZ;
    nuevo_nodo->fila = fila;
    nuevo_nodo->suma = suma;
    nuevo_nodo->siguiente = NULL;

    Matriz aux1 = lista;
    Matriz aux2;

    while(aux1 != NULL and aux1->suma > nuevo_nodo->suma  ){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(aux1 == lista){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void mostrarPila(PPila miPila){
    if(miPila == NULL){
        cout<<" -> NULL"<<endl;
        return;
    }
    cout<<" -> ( "<<miPila->fila<<", "<<miPila->suma<<" )";
    mostrarPila(miPila->siguiente);
}