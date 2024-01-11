#include<iostream>
#include<cstring>
using namespace std;

void eliminarEspacios(char[]);
void eliminarPosicion(char[],int);
void MayusculasAMinisculas(char[]);
int buscarPosicion(char[],char);
void cortarCadena(char[],int,int);

int main(){
    char nombre[30],correo[20];
    int posicionComa;
    cout<<"Ingrese su apellido seguido de una coma, y su nombre\nEjemplo: Da Silva Catela, Valentin\n";
    cin.getline(nombre,30);
    eliminarEspacios(nombre);
    MayusculasAMinisculas(nombre);
    posicionComa = buscarPosicion(nombre,',');
    correo[0] = nombre[posicionComa + 1];
    correo[1] = '\0';
    cortarCadena(nombre,0,posicionComa-1);
    strcat(correo,nombre);
    strcat(correo,"@frsf.utn.edu.ar");
    cout<<correo<<endl;
    return 0;
}

void cortarCadena(char v[], int inicio, int fin){
    int i = 0;
    while(v[i] != '\0'){
        if(i < inicio or i > fin){ 
            eliminarPosicion(v,i);
            i--;
        }
        i++;
    }
}

void MayusculasAMinisculas(char nombre[]){
    int i = 0;
    while(nombre[i] != '\0'){
        if(nombre[i] >= 'A' and nombre[i] <= 'Z'){
            nombre[i] = nombre[i] - 'A' + 'a';
        }
        i++;
    }
}

int buscarPosicion(char n[], char elemento){
    int i = 0;
    bool encontrado = false;
    while(n[i] != '\0' and !encontrado){
        if(n[i] == elemento){
            encontrado = true;
        }
        i++;
    }
    if(encontrado) return --i; else return -1 ;
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