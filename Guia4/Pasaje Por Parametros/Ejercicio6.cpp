#include<iostream>
#include<math.h>
using namespace std;

int cifrar(int);
int main(){
    int numero;
    cout<<"Ingrese el numero para ser cifrado: ";cin>>numero;
    cout<<cifrar(numero)<<endl;
    return 0;
}

int cifrar(int numero){
    int i=0, numeroFinal = 0;
    while(numero > 0){
        numeroFinal += (((numero%10)+7)%10)*pow(10,i);
        numero/=10;
        i++;
    }

    //hasta aca para hacerlo de n digitos,ahora pide que sea especifico para 4
    numeroFinal = (numeroFinal/1000)*10+(numeroFinal/100%10)*1+(numeroFinal/10%10)*1000+(numeroFinal%10)*100;
    return numeroFinal;
}