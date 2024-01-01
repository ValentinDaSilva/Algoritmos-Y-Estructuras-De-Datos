#include<iostream>
using namespace std;

int main(){
    string usuario;
    cout<<"Ingrese su nombre de usuario: "<<endl;
    getline(cin,usuario);
    while(usuario.length() > 8){
        cout<<"El usuario debe tener menos de 8 caracteres! "<<endl;
        getline(cin,usuario);
    }
    while(!isalpha(usuario[0])){
        cout<<"El primer caracter debe ser una letra! "<<endl;
        getline(cin,usuario);
    }
    int i = 0;
    while(usuario[i] != '\0'){
        if(!isalnum(usuario[i])){
            cout<<"Deben ser todas los caracteres numeros o letras"<<endl;
            getline(cin,usuario);
            i = -1;
        }
        i++;
    }
    cout<<"Usuario Registrado Correctamente"<<endl;
    return 0;
}