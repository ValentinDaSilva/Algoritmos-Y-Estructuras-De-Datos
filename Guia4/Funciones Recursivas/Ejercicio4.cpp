#include<iostream>
#include<math.h>
using namespace std;

bool esCapicua(int);
int calcularPrimerDigito(int);
int EliminarPrimerDigito(int);

int main(){
    int numero;
    cout<<"Ingresa un numero para verificar si es capicua: ";cin>>numero;
    cout<<boolalpha<<esCapicua(numero)<<endl;
    if(cin>>numero) main();
    return 0;
}

bool esCapicua(int numero){
    if(numero < 10) return true;
    if(numero%10 != calcularPrimerDigito(numero)) return false;
    return esCapicua(EliminarPrimerDigito(numero)/10);
}

int calcularPrimerDigito(int numero){
    if(numero<10) return numero;
    return calcularPrimerDigito(numero/10);
}

int EliminarPrimerDigito(int numero){
    if(numero < 10) return 0;
    return numero%10 + EliminarPrimerDigito(numero/10)*10; 
}