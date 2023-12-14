#include<iostream>
using namespace std;

int main(){
    //variables
    int numero, cantPositivos = 0, sumaPositivos = 0;
    float promPositivos;
    cout<<"Ingrese numeros y finalice con CTRL + Z: "<<endl;
    while(cin>>numero){
        if(numero > 0){
            cantPositivos++;
            sumaPositivos+=numero;   
        }
    }
    promPositivos = sumaPositivos / (float)cantPositivos;
    cout<<"Cantidad de positivos: "<<cantPositivos<<endl;
    cout<<"Suma de positivos: "<<sumaPositivos<<endl;
    cout<<"Promedio de positivos: "<<promPositivos<<endl;
    return 0;
}