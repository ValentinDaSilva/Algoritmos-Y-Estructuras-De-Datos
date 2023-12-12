#include<iostream>
using namespace std;

int main(){
    int a , b;
    float porcentaje;
    cout<<"Ingrese la cantidad de preguntas: ";cin>>a;
    cout<<"Ingrese la cantidad de respuestas correctas: ";cin>>b;
    porcentaje = b * 100 / (float) a;
    if(porcentaje >= 90){
        cout<<"Nivel máximo"<<endl;
    }
    else if(porcentaje >= 75){
        cout<<"Nivel medio"<<endl;
    }
    else if(porcentaje >= 50){
        cout<<"Nivel regular"<<endl;
    }
    else{
        cout<<"Fuera de nivel"<<endl;
    }
    return 0;
}