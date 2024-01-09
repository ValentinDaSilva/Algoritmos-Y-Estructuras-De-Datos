#include<iostream>
using namespace std;


struct CALIFICACIONES{
    int ID;
    float calificacion[6];
    CALIFICACIONES* siguiente;
};
typedef CALIFICACIONES* Alumno;

void generarNotas(Alumno);

int main(){
    Alumno comisionA, comisionB;
    generarNotas(comisionA); generarNotas(comisionB);
    
    return 0;
}

void generarNotas(Alumno alumno){
    float flotantes[10] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9};
    for(int i = 0 ; i < 10 ; i++){
        Alumno nuevo_nodo = new CALIFICACIONES;
        nuevo_nodo->ID = i;
        for(int j = 0; j < 6; j++){
            nuevo_nodo->calificacion[i] = (float)(rand()%8+2) + flotantes[rand()%10];
        }
        nuevo_nodo->siguiente = alumno;
        alumno = nuevo_nodo;
    }
}