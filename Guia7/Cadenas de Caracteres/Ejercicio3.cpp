#include<iostream>
using namespace std;

bool esPalindromo(char[],int);
int longitud(char[]);
void eliminarEspacios(char[]);
void eliminarPosicion(char[],int);

int main(){
    char frase[100];
    cout<<"Ingrese una frase (tiene que tener menso de 99 caracacteres)"<<endl;
    cin.getline(frase,99);
    eliminarEspacios(frase);
    if(esPalindromo(frase, longitud(frase))){
        cout<<"La frase es palindromo"<<endl;
    }else{
        cout<<"No es palindromo"<<endl;
    }
    return 0;
}

bool esPalindromo(char v[],int longitud){
    if( longitud < 2 ) return true;
    if( v[0] == v[longitud-1] ) return esPalindromo(&v[1], longitud-2);
    return false;
}

int longitud(char v[]){
    if(v[0] == '\0') return 0;
    else return 1 + longitud(&v[1]);
}

void eliminarPosicion(char nombre[],int posicion){
    while(nombre[posicion] != '\0'){
        if(nombre[posicion+1] == '\0') nombre[posicion] = '\0';
        else{    
            nombre[posicion] = nombre[posicion + 1];
            posicion++;
        }
    }
}

void eliminarEspacios(char nombre[]){
    // char espacio = ' ';
    int i = 0;
    while(nombre[i] != '\0'){
        if(nombre[i] == ' '){
            eliminarPosicion(nombre,i);
        }
        i++;
    }
}