#include<iostream>
#include<iomanip>
using namespace std;

const int filas = 5, columnas = 5;
void mostrarMatriz(int[][columnas]);
void random(int[][columnas]);
bool esPendiente(int[][columnas],int);
bool esAislado(int[][columnas],int);
int cantNodosAislados(int[][columnas]);
bool tieneNodosPendiente(int[][columnas]);
bool grafoCompleto(int[][columnas]);

int main(){
    int MatrizAdyacencia[filas][columnas] = {{0,1,1,1,0},{1,0,0,0,0},{1,0,0,1,0},{1,0,1,0,0},{0,0,0,0,0}};
    int nodo;
    mostrarMatriz(MatrizAdyacencia);
    cout<<"Ingrese un nodo del 1 al "<<filas<<" para ver si es pendiente: ";cin>>nodo;
    cout<<boolalpha<<esPendiente(MatrizAdyacencia,nodo-1)<<endl;
    cout<<"Ingrese un nodo para ver si es aislado: ";cin>>nodo;
    cout<<boolalpha<<esAislado(MatrizAdyacencia,nodo-1)<<endl;
    cout<<"El grafo tiene nodos pendiente?: "<<boolalpha<<tieneNodosPendiente(MatrizAdyacencia)<<endl;
    cout<<"Cantida de nodos aislados: "<<cantNodosAislados(MatrizAdyacencia)<<endl;
    cout<<"El grafo es completo: "<<grafoCompleto(MatrizAdyacencia)<<endl;
    return 0;
}

bool grafoCompleto(int M[][columnas]){
    bool esCompleto = true;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(M[i][j] == 0) esCompleto = false;
        }
    }
    return esCompleto;
}

int cantNodosAislados(int M[][columnas]){
    int contador = 0;
    for(int i = 0; i < filas; i++){
        if(esAislado(M,i)) contador++;
    }
    return contador;
}

bool tieneNodosPendiente(int M[][columnas]){
    bool TieneNodosPendiente = false;
    int i = 0;
    while(!TieneNodosPendiente and i < filas){
        if(esPendiente(M,i)) TieneNodosPendiente = true;
        i++;
    }
    return TieneNodosPendiente;
}

bool esPendiente(int M[][columnas], int nodo){
    int contador = 0;
    bool EsPendiente = false;
    for(int i = 0; i < filas; i++){
        if(M[nodo][i] == 1) contador++;
    }
    if(contador == 1) EsPendiente = true; 
    return EsPendiente;
}

bool esAislado(int M[][columnas], int nodo){
    bool EsAislado = true;
    for(int i = 0; i < filas; i++){
        if(M[nodo][i] != 0) EsAislado = false;
    }
    return EsAislado;
}

void random(int M[][columnas]){
    srand(time(NULL));
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            M[i][j] = rand()%40+10;
        }
    }
}

void mostrarMatriz(int M[][columnas]){
    for(int i = 0; i < filas; i++){
        cout<<"[ ";
        for(int j = 0; j < columnas; j++){
            cout<<setw(2)<<M[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
}