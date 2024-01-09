#include<iostream>
using namespace std;

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
    float promedioAlumno = promedio(comisionA->calificacion,6);
    PIntegracion final = new INTEGRACION;

    while(comisionA != nullptr){
        PIntegracion nuevo_nodo = new INTEGRACION;
        nuevo_nodo->ID = comisionA->ID;
        nuevo_nodo->promedio = promedioAlumno;

        PIntegracion aux1 = final;
        PIntegracion aux2;

        while(aux1 != nullptr and nuevo_nodo->promedio > final->promedio){
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if(aux1 == final) {
            final = nuevo_nodo;
        }else{
            aux2->siguiente = nuevo_nodo;
        }
        nuevo_nodo->siguiente = aux1;
        comisionA = comisionA->siguiente;
    }
    while(comisionB != nullptr){
        PIntegracion nuevo_nodo = new INTEGRACION;
        nuevo_nodo->ID = comisionA->ID;
        nuevo_nodo->promedio = promedioAlumno;

        PIntegracion aux1 = final;
        PIntegracion aux2;

        while(aux1 != nullptr and nuevo_nodo->promedio > final->promedio){
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if(aux1 == final) {
            final = nuevo_nodo;
        }else{
            aux2->siguiente = nuevo_nodo;
        }
        nuevo_nodo->siguiente = aux1;
        comisionB = comisionB->siguiente;
    }

    return final;
}

void generarNotas(Alumno& alumno){
    float flotantes[10] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    for(int i = 0 ; i < 10 ; i++){
        Alumno nuevo_nodo = new CALIFICACIONES;
        nuevo_nodo->ID = i;
        for(int j = 0; j < 6; j++){
            nuevo_nodo->calificacion[j] = (float)(rand()%8+2) + flotantes[rand()%10];
        }
        nuevo_nodo->siguiente = alumno;
        alumno = nuevo_nodo;
    }
}