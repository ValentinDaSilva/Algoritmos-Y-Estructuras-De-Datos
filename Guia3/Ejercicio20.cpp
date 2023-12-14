#include<iostream>
using namespace std;

int main(){
    int numero = 1, cantidad, contador = 0, multiplicacion;
    cout<<"Ingresa la cantidad de numeros curiosos que desea encontrar:";cin>>cantidad;
    while(contador < cantidad ){
        multiplicacion = numero * numero;
        //Tengo que hacer una funcion para determinar si es curioso
        bool esCurioso = true;
        int aux = numero;
        while(esCurioso and aux > 0){
            if(aux%10 == multiplicacion%10){
                aux/=10;
                multiplicacion/=10;
            }else{
                esCurioso = false;
            }
        }
        if(esCurioso){
             contador++; 
             cout<<numero<<" ";
        }
        numero++;
    }
    
    return 0;
}