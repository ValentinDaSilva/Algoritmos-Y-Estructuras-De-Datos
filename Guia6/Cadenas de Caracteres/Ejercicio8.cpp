#include<iostream>
using namespace std;

void eliminarNumeros(char[]);
void eliminarPosicion(char[]);

int main(){
    char mensaje[100];
    cout<<"Ingrese el mensaje para eliminarle los numeros: ";cin.getline(mensaje,100);
    eliminarNumeros(mensaje);
    cout<<mensaje<<endl;
    return 0;
}

void eliminarNumeros(char v[]){
    if(v[0] == '\0') return;
    else if(v[0] >= '0' and v[0] <= '9'){
         eliminarPosicion(v);
         eliminarNumeros(&v[0]); 
    }
    else eliminarNumeros(&v[1]);
    
}

void eliminarPosicion(char v[]){
    if(v[1] == '\0') v[0] = '\0';
    else{
        v[0] = v[1];
        eliminarPosicion(&v[1]);
    }
}