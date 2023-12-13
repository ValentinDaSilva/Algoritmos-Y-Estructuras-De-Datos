#include<iostream>
using namespace std;

int main(){
    float notaAporbacion, notaParcial1, notaParcial2, promedio;
    cout<<"Ingrese nota de aprobacion: "; cin>>notaAporbacion;
    cout<<"Ingrese nota Parcial 1: "; cin>>notaParcial1;
    cout<<"Ingrese nota Parcial 2: "; cin>>notaParcial2;
    promedio = (notaParcial1 + notaParcial2)/2;
    if(promedio >= notaAporbacion){
        cout<<"El Alumno esta promocionado"<<endl;
    }
    else if(promedio >= (notaAporbacion - 10)){
        cout<<"El Alumno esta en condiciones de recuperar"<<endl;
    }
    else cout<<"El alumno desaprobo el curso"<<endl;
    return 0;
}