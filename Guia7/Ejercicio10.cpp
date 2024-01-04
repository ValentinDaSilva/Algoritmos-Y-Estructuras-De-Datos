#include<iostream>
#include<iomanip>
using namespace std;

const int sucursales = 4, articulos = 5;
void mostrarMatriz(int[][articulos]);
void cargar(int[][articulos]);
void recaudacionPorSucursal(int[][articulos],int[],int[]);
int recaudacionDeLaEmpresa(int[]);
int sucursalQueMasRecaudo(int[]);

int main(){
    int M[sucursales][articulos] = {0}, precios[articulos];
    int recaudacion[sucursales] = {0};
    cargar(M);
    cargarPrecios(precios);
    mostrarMatriz(M);
    cout<<"************Recaudacion de cada sucursal****************"<<endl;
    for(int i = 0; i < sucursales; i++){
        cout<<"Sucursal "<<i+1<<" : $"<<recaudacion[i]<<endl;
    }
    cout<<endl;
    cout<<"Recaudacion total de la empresa: "<<recaudacionDeLaEmpresa(recaudacion,sucursales)<<endl<<endl;
    cout<<"La sucursal que mas recaudo fue la numero: "<<sucursalQueMasRecaudo(recaudacion)<<endl;
    return 0;
}

int sucursalQueMasRecaudo(int recaudacion[]){
    int indice, mayor;
    for(int i = 0; i < sucursales; i++){
        if(i == 0 or recaudacion[i] > mayor){
            indice = i;
            mayor = recaudacion [i];
        }
    }
    return indice + 1;
}

int recaudacionDeLaEmpresa(int recaudacion[],int TL){
    if(TL == 0) return 0;
    return recaudacion[0] + recaudacionDeLaEmpresa(&recaudacion[1],--TL);
}


void recaudacionPorSucursal(int M[][articulos], int precios[],int recaudacionSucursal[]){
    int recaudacion = 0;
    for(int i = 0; i < sucursales; i++){
        for(int j = 0; j < articulos; j++){
            recaudacion += (M[i][j])*precios[j];
        }
        recaudacionSucursal[i] = recaudacion;
        recaudacion = 0;
    }
}

void cargarPrecios(int precios[]){
    for(int i = 0; i < articulos; i++){
        cout<<"Precio producto "<<i+1<<": ";cin>>precios[i];
    }
}

void cargar(int M[][articulos]){
    int codigoSucursal, codigoProducto, cantidadVendida;
    do{
        cout<<"Ingrese codigo sucursal, codigo producto, cantidad vendida: ";
        cin>>codigoSucursal>>codigoProducto>>cantidadVendida;
        if(M[codigoSucursal-1][codigoProducto-1] == 0 and codigoSucursal != 0) M[codigoSucursal-1][codigoProducto-1] = cantidadVendida;
        else if(codigoSucursal != 0) M[codigoSucursal-1][codigoProducto-1] += cantidadVendida;
    }while(codigoSucursal != 0);
}

void mostrarMatriz(int M[][articulos]){
    for(int i = 0; i < sucursales; i++){
        cout<<"[ ";
        for(int j = 0; j < articulos; j++){
            cout<<setw(2)<<M[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl;
}
