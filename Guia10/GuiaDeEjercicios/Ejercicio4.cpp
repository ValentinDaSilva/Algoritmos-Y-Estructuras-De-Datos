#include<iostream>
#include<iomanip>
using namespace std;
int cantAlumnos = 20;

struct INTEGRACION{
    int ID;
    float promedio;
    INTEGRACION* siguiente;
};
typedef INTEGRACION* PIntegracion;

struct CALIFICACIONES{
    int ID;
    float calificacion[6];
    CALIFICACIONES* siguiente;
};
typedef CALIFICACIONES* Alumno;

void generarNotas(Alumno&);
PIntegracion integrar(Alumno,Alumno);
float promedio(float[],int);
void mostrarLista(Alumno&);
void mostrarIngreacion(PIntegracion);
void insertarOrdenado(PIntegracion&,int,float);

int main(){
    Alumno comisionA, comisionB;
    generarNotas(comisionA); generarNotas(comisionB);

    return 0;
}
float promedio(float v[], int TL){
    if(TL == 1) return v[0];
    return (v[0] + promedio(&v[1],TL-1) * (TL-1)) / (float) TL;
}

PIntegracion integrar(Alumno comisionA,Alumno comisionB){
    PIntegracion final = new INTEGRACION;
    while(comisionA != NULL){
        float promedioAlumno = promedio(comisionA->calificacion,6);
        insertarOrdenado(final,comisionA->ID,promedioAlumno);
        comisionA = comisionA->siguiente;
    }
    return final;
}

void insertarOrdenado(PIntegracion& Lista, int ID, float promedio){
    PIntegracion nuevo_elemento = new INTEGRACION;
    nuevo_elemento->ID = ID;
    nuevo_elemento->promedio = promedio;

    PIntegracion aux1 = Lista;
    PIntegracion aux2;

    while(aux1 != NULL and aux1->promedio < promedio){
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

void generarNotas(Alumno& alumno){
    float flotantes[9] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    for(int i = 0 ; i < 10 ; i++, cantAlumnos--){
        Alumno nuevo_nodo = new CALIFICACIONES;
        nuevo_nodo->ID = cantAlumnos;
        for(int j = 0; j < 6; j++){
            nuevo_nodo->calificacion[j] = (float)(rand()%8+2) + flotantes[rand()%9];
        }
        nuevo_nodo->siguiente = alumno;
        alumno = nuevo_nodo;
    }
}