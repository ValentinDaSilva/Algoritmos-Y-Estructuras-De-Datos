#include<iostream>
using namespace std;

bool registrar(char[]);
bool esLetraONumero(char);

int main(){
    char usuario[9];
    cout<<"Ingrese su nombre de usuario: "<<endl;
    cin.getline(usuario,8);
    if(registrar(usuario)) cout<<"Usuario Correcto"<<endl;
    else cout<<"Usuario Incorrecto, Intentelo de nuevo"<<endl;
    return 0;
}

bool registrar(char v[]){
    bool usuarioCorrecto = true;
    if(!((v[0] >= 'A' and v[0] <= 'Z') or (v[0] >= 'a' and v[0] <= 'z'))) usuarioCorrecto = false;
    int i = 1;
    while(v[i] != '\0' and usuarioCorrecto){
        if(!(esLetraONumero(v[i]))) usuarioCorrecto = false;
        i++;
    }
    return usuarioCorrecto;
}

bool esLetraONumero(char caracter){
    if((caracter >= 'A' and caracter <= 'Z') or (caracter >= 'a' and caracter <= 'z')) return true;
    else if(caracter >= '1' and caracter <= '9') return true;
    else return false;
}