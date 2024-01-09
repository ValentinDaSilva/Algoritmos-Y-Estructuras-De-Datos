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

void cargarDatosComision(Alumno&);

int main(){
    Alumno comisionA, comisionB;
    srand(time(NULL));
    return 0;
}

void cargarDatosComision(Alumno& alumno){
    Alumno nuevo_alumno;
    
    for(int i = 0 ; i < cantAlumnos; i++){
        nuevo_alumno = new CALIFICACIONES;
        nuevo_alumno->ID = i;
        for(int j = 0; j < 6; j++){
            nuevo_alumno->calificacion[j] == (float)(rand()%10);
        }
        Alumno aux1 = alumno;
        Alumno aux2;
        while(aux1 != NULL and nuevo_alumno->ID > aux1->ID){
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if(aux1 = alumno){
            nuevo_alumno->siguiente = aux1;
        }else{
            aux2->siguiente = nuevo_alumno;
            nuevo_alumno->siguiente = aux1;
        }
        alumno = nuevo_alumno;
    }
    

}






