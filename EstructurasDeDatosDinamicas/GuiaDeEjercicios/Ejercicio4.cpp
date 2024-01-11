#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int cantAlumnos, cantidad;

struct Integrar
{
    int ID;
    float promedio;
    Integrar* siguiente;
};
typedef Integrar* PIntegrar;

struct Calificacion {
    int ID;
    float calificacion[6];
    Calificacion *siguiente;
};
typedef Calificacion* Alumno;

void agregarElemento(Alumno&,int,float[]);
void mostrarLista(Alumno);
void cargarDatos(Alumno&);
float promedio(float[],int);
PIntegrar integrar(Alumno,Alumno);
void mostrarListaIntegrada(PIntegrar);
void agregarAIntegrar(PIntegrar&,int,float);

int main(){
    Alumno comisionA = NULL, comisionB = NULL;
    PIntegrar listaFinal = NULL;
    srand(time(NULL));
    cout<<"Ingrese la cantidad de alumnos para generar datos aleatoriamente: "; cin>>cantAlumnos;  cantidad = cantAlumnos;cantAlumnos*=2;

    cargarDatos(comisionA); cargarDatos(comisionB);
    mostrarLista(comisionB); mostrarLista(comisionA);
    listaFinal = integrar(comisionA,comisionB);
    mostrarListaIntegrada(listaFinal);
    return 0;
}

void cargarDatos(Alumno& lista){
    float v[6];
    for(int i = 0; i < cantidad; i++, cantAlumnos--){
        for(int j = 0 ; j < 6; j++) v[j] = (float)(rand()%10+1);
        agregarElemento(lista,cantAlumnos,v);
    }
}

void agregarAIntegrar(PIntegrar& Lista, int dato, float promedio){
    PIntegrar nuevo_elemento = new Integrar;
    nuevo_elemento->ID = dato;
    nuevo_elemento->promedio = promedio;

    PIntegrar aux1 = Lista;
    PIntegrar aux2;

    while(aux1 != NULL and nuevo_elemento->promedio < aux1->promedio){
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

void mostrarListaIntegrada(PIntegrar lista){
    if(lista == NULL){
        cout<<endl;
        return;
    }
    cout<<lista->ID<<" promedio: "<<fixed<<setprecision(2)<<lista->promedio<<endl;
    mostrarListaIntegrada(lista->siguiente);
}

PIntegrar integrar(Alumno comisionA, Alumno comisionB){
    PIntegrar listaFinal = NULL;
    while(comisionA != NULL){
        agregarAIntegrar(listaFinal,comisionA->ID,promedio(comisionA->calificacion,6));
        comisionA = comisionA->siguiente;
    }
    while(comisionB != NULL){
        agregarAIntegrar(listaFinal,comisionB->ID,promedio(comisionB->calificacion,6));
        comisionB = comisionB->siguiente;
    }
    return listaFinal;
}

float promedio(float v[],int TL){
    if(TL == 1) return v[0];
    return (v[0] + (promedio(&v[1],TL-1)*(TL-1))) / TL; 
}




