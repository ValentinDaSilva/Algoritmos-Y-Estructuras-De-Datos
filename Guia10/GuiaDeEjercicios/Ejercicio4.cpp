#include <iostream>
#include <ctime>
using namespace std;
int cantAlumnos;

struct Calificacion {
    int ID;
    float calificacion[6];
    Calificacion *siguiente;
};
typedef Calificacion* Alumno;

void agregarElemento(Alumno&,int,float[]);
void mostrarLista(Alumno);
void cargarDatos(Alumno&);

int main(){
    Alumno comisionA = NULL, comisionB = NULL;
    srand(time(NULL));
    cout<<"Ingrese la cantidad de alumnos para generar datos aleatoriamente: "; cin>>cantAlumnos;
    cargarDatos(comisionA);
    mostrarLista(comisionA);
    return 0;
}

void cargarDatos(Alumno& lista){
    float v[6];
    for(int i = 0; i < cantAlumnos; i++){
        for(int j = 0 ; j < 6; j++) v[j] = (float)(rand()%10+1);
        agregarElemento(lista,i,v);
    }
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




