#include<iostream>
using namespace std;
const int cantAutos = 300, cantAlquileres = 1000;

struct Automovil
{
    int codigo;
    short int categoria;
    double precioAlquiler;
    bool alquilado = false;
    double ingresosGenerados = 0;
}autos[cantAutos]; //Ordenado por codigo

struct AlquilerMesAnterior
{
    int codigoAuto;
    int numeroCliente;
    int diasAlquilado;
    double kilometrosRecorridos;
}alquileres[cantAlquileres];

struct Cliente{
    int numeroCliente;
    double gastos = 0;
};

void listarClientes(Cliente[],int&);
void mostrarGastosPorCliente(Cliente[],int);
bool estaEnElVector(Cliente[],int,int);
void autosNoAlquilados();
void alquilerPorCategoria(Cliente[],int);
int buscarMayor(int categoria[],int TL);
void AutoQueMasGenero();

int main(){
    Cliente listadoClientes[cantAlquileres] = {0};
    int TLClientes = 0;
    listarClientes(listadoClientes,TLClientes);
    mostrarGastosPorCliente(listadoClientes,TLClientes);
    autosNoAlquilados();
    alquilerPorCategoria(listadoClientes,TLClientes);
    AutoQueMasGenero();
    return 0;
}

void AutoQueMasGenero(){
    int indice, mayor;
    for(int i = 0; i < cantAutos; i++){
        if(i == 0 or mayor > autos[i].ingresosGenerados){
            mayor = autos[i].ingresosGenerados;
            indice = i;
        }
    }
    cout<<"El auto que genero mas dinero fue el que tiene codigo: "<<autos[indice].codigo<<endl;
}

void autosNoAlquilados(){
    for(int i = 0; i < cantAutos;i++){
        if(!autos[i].alquilado) cout<<"El auto con codigo "<<autos[i].codigo<<" no fue alquilado";
    }
}

void alquilerPorCategoria(Cliente cliente[],int TL){
    int categoria[6] = {0};
    for(int i = 0; i < TL; i++){
        for(int j = 0; i < cantAlquileres; i++){
            if(alquileres[j].numeroCliente == cliente[i].numeroCliente){
                int indiceAuto = buscarCodigoAuto(alquileres[i].codigoAuto);
                categoria[autos[indiceAuto].categoria - 1]++;
            }
        }
    }
    cout<<"La categoria mas vendida fue la: "<<buscarMayor(categoria,6)<<endl;
}

int buscarMayor(int categoria[],int TL){
    int mayor, indice;
    for(int i = 0; i < TL; i++){
        if(i == 0 or mayor > categoria[i]){
            mayor = categoria[i];
            indice = i;
        }
    }
    return indice + 1;
}

void mostrarGastosPorCliente(Cliente cliente[],int TL){
    int vecesAlquilado[TL] = {0};
    for(int i = 0; i < TL; i++){
        for(int j = 0; i < cantAlquileres; i++){
            if(alquileres[j].numeroCliente == cliente[i].numeroCliente){
                int indiceAuto = buscarCodigoAuto(alquileres[i].codigoAuto);
                cliente[i].gastos += autos[indiceAuto].precioAlquiler*alquileres[j].kilometrosRecorridos;
                autos[indiceAuto].ingresosGenerados = autos[indiceAuto].precioAlquiler*alquileres[j].kilometrosRecorridos;
                vecesAlquilado[i]++;
            }
        }
        if(cliente[i].gastos > 1500) cout<<"El cliente "<<cliente[i].numeroCliente<<" gasto: $"<<cliente[i].gastos<<endl;
    }
    cout<<endl;
    for(int i = 0 ; i < TL; i++){
        if(vecesAlquilado[i] > 2){
            cout<<"El Cliente "<<cliente[i].numeroCliente<<" alquilo mas de dos veces."<<endl;
        }
    }
}

int buscarCodigoAuto(int codigo){
    bool encontrado = false;
    int i = 0, indiceAuto = -1;
    while(!encontrado and i < cantAutos){
        if(autos[i].codigo == codigo) indiceAuto = i;
        i++;
    }
    if(encontrado) autos[indiceAuto].alquilado = true;
    return indiceAuto;
}

void listarClientes(Cliente v[],int& TL){
    for(int i = 0; i < cantAlquileres; i++){
        if(estaEnElVector(v,TL,alquileres[i].numeroCliente)){
            v[TL].numeroCliente = alquileres[i].numeroCliente;
            TL++;
        }
    }    
}

bool estaEnElVector(Cliente v[],int TL,int elemento){
    if(TL == 0) return false;
    if(v[0].numeroCliente == elemento) return true;
    return estaEnElVector(v,--TL,elemento);
}