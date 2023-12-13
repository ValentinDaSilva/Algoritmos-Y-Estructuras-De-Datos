#include<iostream>
using namespace std;
/* Mayores de 25 sale 35, categoria 1 40% de descuento, categoria 2 30% de descuento, 3 15% */
/* Para los de 25 sale 20, categoria 1 60% de descuento, categoria 2 40%, categoria 3 20% */
/* menores de 25 no acceden */
int main(){
    int edad, categoria;
    float cantidad;
    if(edad > 25){
        cantidad = 35;
        switch (categoria)
        {
            case 1: cantidad = cantidad*(1 + 0.4);break;
            case 2: cantidad = cantidad*(1 + 0.3);break;
            case 3: cantidad = cantidad*(1 + 0.15);break;
            cout<<"Precio Final = "<<cantidad<<endl;
        }
    }
    else if(edad == 25){
        cantidad = 20;
        switch (categoria)
        {
            case 1: cantidad = cantidad*(1 + 0.6);break;
            case 2: cantidad = cantidad*(1 + 0.4);break;
            case 3: cantidad = cantidad*(1 + 0.2);break;
        }
        cout<<"Precio Final = "<<cantidad<<endl;
    }
    else {
        cout<<"No Puede Acceder"<<endl;
    }
    return 0;
}