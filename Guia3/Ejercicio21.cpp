#include<iostream>
#define pp1 2.98
#define pp2 4.5
#define pp3 9.98
#define pp4 4.49
#define pp5 6.87

using namespace std;
int main(){
    int producto, cantVendida, productoMasVendidoPorDia;
    float totalFacturado = 0, gananciaTotalDia = 0, precioTotalPorProducto, productoMasVendidoPorDiaPrecio = -1;
    for(int i = 0; i < 2 ; i++){
        cout<<"---- Semana "<<i+1<<" ----"<<endl;
        for(int j = 0; j < 5; j++){
            cout<<"Producto: ";cin>>producto;
            cout<<"Cantidad Vendida: ";cin>>cantVendida;
            switch (producto)
            {
                case 1: precioTotalPorProducto = cantVendida * pp1;break;
                case 2: precioTotalPorProducto = cantVendida * pp2;break;
                case 3: precioTotalPorProducto = cantVendida * pp3;break;
                case 4: precioTotalPorProducto = cantVendida * pp4;break;
                case 5: precioTotalPorProducto = cantVendida * pp5;break;
            }
            if(precioTotalPorProducto > productoMasVendidoPorDiaPrecio){
                productoMasVendidoPorDia = producto;
                productoMasVendidoPorDiaPrecio = precioTotalPorProducto; 
                
            }
            gananciaTotalDia+=precioTotalPorProducto;
        }
        cout<<"El producto que mas ganancias dio fue: "<<productoMasVendidoPorDia<<endl;
        cout<<"Ganancia total del dia: $"<<gananciaTotalDia<<endl;
        totalFacturado+=gananciaTotalDia;
        gananciaTotalDia = 0;
    }
    cout<<"Total Facturado : $"<<totalFacturado<<endl;
    
    return 0;
}