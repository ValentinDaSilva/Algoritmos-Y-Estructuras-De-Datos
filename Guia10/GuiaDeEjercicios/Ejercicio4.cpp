#include <iostream>
#include <ctime>
using namespace std;

struct Calificacion {
    int ID;
    float calificacion[6];
    Calificacion *siguiente;
};
typedef Calificacion* Alumno;

void agregarElemento(Alumno&,int,float[]);
void mostrarLista(Alumno);

int main(){
    float notas[] = {4.3,6.0,8.2,10.0,5.5,6.0};
    Alumno comisionA = NULL, comisionB = NULL;
    srand(time(NULL));
    agregarElemento(comisionA,rand()%100,notas);
    mostrarLista(comisionA);
    return 0;
}

void agregarElemento(Alumno& Lista, int dato, float notas[]){
    Alumno nuevo_elemento = new Calificacion;
    nuevo_elemento->ID = dato;
    for(int i = 0; i < 6; i++) nuevo_elemento->calificacion[i] = notas[i];
    Alumno aux1 = Lista;
    Alumno aux2;

    while(aux1 != NULL and aux1->ID < nuevo_elemento->ID){
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

void mostrarLista(Alumno lista){
    if(lista == NULL){
        cout<<endl;
        return;
    }
    cout<<lista->ID<<" [";
    for(int i = 0; i < 6; i++) cout<<lista->calificacion[i]<<" "; cout<<"]"<<endl;
    mostrarLista(lista->siguiente);
}




