#include<iostream>
using namespace std;

void codificar(char[],int);

int main(){
    char texto[100];
    int desplazamiento;
    cout<<"Ingresa el texto a codigificar: ";cin.getline(texto,100);
    cout<<"Ingrese el desplazamiento: ";cin>>desplazamiento;
    codificar(texto,desplazamiento);
    cout<<texto<<endl;
    return 0;
}

void codificar(char texto[], int desplazamiento){
    if(texto[0] == '\0') return;
    if((texto[0] > 'A' and texto[0] < 'Z')){
        texto[0] = texto[0] + desplazamiento;
        if(!(texto[0] > 'A' and texto[0] < 'Z')){
            texto[0] = texto[0] - 'Z' + 'A';
        }
    }
    if((texto[0] > 'a' and texto[0] < 'a')){
        texto[0] = texto[0] + desplazamiento;
        if(!(texto[0] > 'a' and texto[0] < 'z')){
            texto[0] = texto[0] - 'z' + 'a';
        }
    }
    codificar(&texto[1],desplazamiento);
}