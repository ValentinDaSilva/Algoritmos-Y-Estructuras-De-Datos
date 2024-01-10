#include<iostream>
using namespace std;
int dimensiones;

struct Nodo {
    int elemento;
    Nodo* siguiente;
};
typedef Nodo* Lista;

void agregarNodo(Lista&,int);
void mostrarLista(Lista);
void buscarAislados(int**,Lista&);
void cargarMatriz(int**);
void mostrarMatriz(int**);

int main(){
    int ** M;
    Lista listaAislados = NULL;
    cout<<"Ingrese la cantidad de filas y columnas: ";cin>>dimensiones;
    M = new int* [dimensiones];
    for(int i = 0; i < dimensiones; i++) M[i] = new int[dimensiones];
    cargarMatriz(M);
    mostrarMatriz(M);
    buscarAislados(M,listaAislados);
    cout<<"L";mostrarLista(listaAislados);
    return 0;
}

void buscarAislados(int** M , Lista& listaAislados){
    for(int i = 0; i < dimensiones; i++){
        for(int j = 0; j < dimensiones - 2; j++){
            if(*(*(M + i) + j + 1) != *(*(M + i) + j) and *(*(M + i) + j + 1) != *(*(M + i) + j + 2)){
                agregarNodo(listaAislados,*(*(M + i) + j + 1));
                // cout<<*(*(M + i) + j + 1)<<endl;
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