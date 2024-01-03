#include<iostream>
using namespace std;

const int filas = 10, columnas = 4;
void random(int[][columnas]);
void mostrarMatriz(int[][columnas]);
bool categoriasSinBoleto(int[][columnas]);
void pasajerosPorCategoria(int[][columnas]);
void mostrarPasajesPorCiudad(int[][columnas],string[]);
void localidadesSinPasajes(int[][columnas],string[]);
void localidadConMenosPasajeros(int[][columnas],string[]);
void localidadConMasDe1000Pasajeros(int[][columnas],string[]);

int main(){
    string ciudades[10] = {
        "Buenos Aires",
        "Córdoba",
        "Rosario",
        "Mendoza",
        "La Plata",
        "San Miguel de Tucumán",
        "Mar del Plata",
        "Salta",
        "Santa Fe",
        "San Juan"
    };
    int M[filas][columnas];
    random(M);
    mostrarMatriz(M);
    mostrarPasajesPorCiudad(M,ciudades);
    pasajerosPorCategoria(M);
    localidadesSinPasajes(M,ciudades);
    localidadConMenosPasajeros(M,ciudades);
    localidadConMasDe1000Pasajeros(M,ciudades);
    cout<<"Hay categorias sin boleto? "<<boolalpha<<categoriasSinBoleto(M)<<endl;
    return 0;
}

bool categoriasSinBoleto(int M[][columnas]){
    int pasajesXCategoria = 0;
    bool categoriasSinBoletos = false;
    for(int i = 0; i < columnas; i++){
        for(int j = 0; j < filas; j++){
            pasajesXCategoria += M[j][i];
        }
        if(pasajesXCategoria == 0) categoriasSinBoletos = true;
    }
    return categoriasSinBoletos;
}

void pasajerosPorCategoria(int M[][columnas]){
    int pasajesXCategoria = 0;
    for(int i = 0; i < columnas; i++){
        for(int j = 0; j < filas; j++){
            pasajesXCategoria += M[j][i];
        }
        cout<<"Categoria "<<i+1<<": "<<pasajesXCategoria<<" pasajes"<<endl;
    }
    cout<<endl;
}

void localidadConMenosPasajeros(int M[][columnas], string ciudades[]){
    int pasajes = 0, indice, menor = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            pasajes += M[i][j];
        }
        if(i == 0){
            indice = i;
            menor = pasajes;
        }else{
            if(pasajes < menor){
                indice = i;
                menor = pasajes;
            }
        }
        pasajes = 0;
    }
    cout<<"La localidad con menos pasajes fue: "<<ciudades[indice]<<endl;
    cout<<endl;
}

void localidadConMasDe1000Pasajeros(int M[][columnas], string ciudades[]){
    int pasajes = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            pasajes += M[i][j];
        }
        if(pasajes > 1000) cout<<"La ciudad "<<ciudades[i]<<" tuvo mas de 1000 pasajeros"<<endl;
        pasajes = 0;
    }
    cout<<endl;
}

void localidadesSinPasajes(int M[][columnas], string ciudades[]){
    int pasajes = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            pasajes += M[i][j];
        }
        if(pasajes == 0) cout<<"La localidad "<<ciudades[i]<<" no vendio ningun pasaje"<<endl;
        pasajes = 0;
    }
    cout<<endl;
}

void mostrarPasajesPorCiudad(int M[][columnas], string ciudades[]){
    int pasajes = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            pasajes += M[i][j];
        }
        cout<<"Pasajes en "<<ciudades[i]<<": "<<pasajes<<endl;
        pasajes = 0;
    }
    cout<<endl;
}

void random(int M[][columnas]){
    srand(time(NULL));
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            M[i][j] = rand()%40+10;
        }
    }
}

void mostrarMatriz(int M[][columnas]){
    for(int i = 0; i < filas; i++){
        cout<<"[ ";
        for(int j = 0; j < columnas; j++){
            cout<<M[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}