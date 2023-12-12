#include<iostream>
using namespace std;

int main(){
    char metodoPago;
    float monto;
    cout<<"Ingrese el monto a pagar: ";cin>>monto;
    cout<<"Ingrese metodo de pago:"<<endl;
    cout<<"D. Tarjeta de debito"<<endl;
    cout<<"B. Billetera Santa Fe"<<endl;
    cout<<"C. Tarjeta de Credito"<<endl;
    cin>>metodoPago;
    if(metodoPago == 'c' || metodoPago == 'C'){
        int cantCuotas;
        cout<<"Ingrese cantidad de cuotas: (1-3)"<<endl;
        cin>>cantCuotas;
        if(cantCuotas == 3){
            monto = monto*(1+0.1);
        }
    }
    else if(metodoPago == 'd' || metodoPago == 'D'){
        if(monto > 3000){
            monto = monto*(1-0.15);
        }
    }
    else if(metodoPago == 'b' || metodoPago == 'B'){
        monto = monto*(1-0.3);
    }
    cout<<"El monto final es de: "<<monto<<endl;
    return 0;
}