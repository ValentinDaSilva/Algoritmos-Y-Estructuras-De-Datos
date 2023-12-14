#include<iostream>
using namespace std;

void cuadrado(int,char);
void triangulo(int,char);
void trianguloInvertido(int,char);


int main(){
    int numero, opcion;
    char caracter;
    cout<<"Ingrese un numero: ";cin>>numero;
    cout<<"Ingrese un caracter: ";cin>>caracter;
    cout<<"Que quiere dibujar?:\n1.Cuadrado\n2.Triangulo\n3.Triangilo Invertido"<<endl;
    cin>>opcion;
    switch (opcion)
    {
    case 1: cuadrado(numero,caracter);break;
    case 2: triangulo(numero,caracter);break;
    case 3: trianguloInvertido(numero,caracter);break;
    default:
        cout<<"Opcion Incorrecta vuelva a intentarlo"<<endl;
        break;
    }
    cout<<"Desea realizar otra operacion? \n1.Si\n2.No"<<endl;cin>>opcion;
    if(opcion == 1) main(); 
    return 0;
}

void cuadrado(int numero,char caracter){
    for(int i = 0 ; i < numero; i++){
        for(int i = 0 ; i < numero; i++){
            cout<<caracter;
        }
        cout<<endl;
    }
}

void trianguloInvertido(int numero,char caracter){
    for(int i = numero ; i > 0; i--){
        for(int j = 0; j < i; j++){
            cout<<caracter;
        }
        cout<<endl;
    }
}

void triangulo(int numero,char caracter){
    for(int i = 1; i <= numero; i++){
        for(int j = 0; j < i ; j++){
            cout<<caracter;
        }
        cout<<endl;
    }
}
