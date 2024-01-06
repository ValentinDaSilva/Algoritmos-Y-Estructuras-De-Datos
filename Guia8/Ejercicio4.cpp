#include<iostream>
#include<iomanip>
using namespace std;


struct Ciudadano
{
    int edad;
    char voto; // R o A
}ciudadano[100];

void cargarDatos(int&);
void intencionDeVoto(int);
void mostrarUsuarios(int);

int main(){
    int cantPersonas = 0;
    cargarDatos(cantPersonas);
    // mostrarUsuarios(cantPersonas);
    intencionDeVoto(cantPersonas);
    return 0;
}

void mostrarUsuarios(int TL){
    cout<<"************* Registro ***************"<<endl;
    for(int i = 0; i < TL; i++){
        cout<<"Edad: "<<ciudadano[i].edad<<endl;
        cout<<"Voto: "<<ciudadano[i].voto<<endl;
    }
    cout<<endl;
}

void intencionDeVoto(int TL){
    int R[3] = {0}, A[3] = {0};
    for(int i = 0 ; i < TL; i++){
        if(ciudadano[i].edad >= 18 and ciudadano[i].edad <= 40){
            if(ciudadano[i].voto == 'R') R[0]++;
            if(ciudadano[i].voto == 'A') A[0]++;
        }
        else if(ciudadano[i].edad > 40 and ciudadano[i].edad <= 60){
            if(ciudadano[i].voto == 'R') R[1]++;
            if(ciudadano[i].voto == 'A') A[1]++;            
        }
        else{
            if(ciudadano[i].voto == 'R') R[2]++;
            if(ciudadano[i].voto == 'A') A[2]++;
        }
    }
    for(int i = 0; i < 3; i++) cout<<R[i]<<" ";
    cout<<endl;
    for(int i = 0; i < 3; i++) cout<<A[i]<<" ";
    int totalG1 = R[0] + A[0];
    int totalG2 = R[1] + A[1];
    int totalG3 = R[2] + A[2];
    cout<<"Edad 18-40, Intencion de voto: R = "<<fixed<<setprecision(2)<<R[0]*100/(float)totalG1<<"%"<<" A = "<<A[0]*100/(float)totalG1<<"%"<<endl;
    cout<<"Edad 41-60, Intencion de voto: R = "<<fixed<<setprecision(2)<<R[1]*100/(float)totalG2<<"%"<<" A = "<<A[1]*100/(float)totalG2<<"%"<<endl;
    cout<<"Edad 61+, Intencion de voto: R = "<<fixed<<setprecision(2)<<R[2]*100/(float)totalG3<<"%"<<" A = "<<A[2]*100/(float)totalG3<<"%"<<endl;
}

void cargarDatos(int& cantPersonas){
    int i = 0;
    int edad; char voto;
    do{
        cout<<"Ingrese su edad: ";cin>>edad;
        cout<<"Ingrese su intencion de voto (R/A): ";cin>>voto;
        if(edad != 0){
            ciudadano[i].edad = edad;
            ciudadano[i].voto = voto;
            cantPersonas++;
            i++;
        }
    }while(edad != 0);
}