#include<iostream>
#include<iomanip>
using namespace std;

const int sucursales = 4, articulos = 25;
void mostrarMatriz(int[][articulos]);
void cargar(int[][articulos]);
void cantidadVendidaPorArticulo(int[][articulos]);
int ventasSucursal3(int[][articulos]);
int analisisArticulo8(int[][articulos]);

int main(){
    int M[sucursales][articulos] = {0};
    cargar(M);
    mostrarMatriz(M);
    cantidadVendidaPorArticulo(M);
    cout<<"Total unidades vendidas por la sucursal 3: "<<ventasSucursal3(M)<<endl;
    cout<<"Cantidad vendida por la sucursal 1 del aritculo 6: "<<M[1][5]<<endl;
    cout<<"La sucursal que vendio mas unidades del articulo 8 fue la: "<<analisisArticulo8(M)<<endl;
    return 0;
}

int analisisArticulo8(int M[][articulos]){
    int indice, mayor, monto;
    for(int i = 0; i < sucursales; i++){
        monto = M[i][7];
        if(i == 0 or monto > mayor) {
            indice = i + 1;
            mayor = monto;
        }
    }
    return indice;
}

int ventasSucursal3(int M[][articulos]){
    int total = 0;
    for(int i = 0; i < articulos; i++){
        total += M[2][i];
    }
    return total;
}

void cantidadVendidaPorArticulo(int M[][articulos]){
    int cantidadVendida = 0;
    for(int i = 0; i < articulos; i++){
        for(int j = 0; j < sucursales; j++){
            cantidadVendida += M[j][i];
        }
        cout<<"Producto "<<i+1<<": "<<cantidadVendida<<" unidades."<<endl;
        cantidadVendida = 0;
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
