#include<iostream>
#include<math.h>
using namespace std;

bool esPalindromo(int);
int UltimaCifra(int);
int eliminarUltimaCifra(int);

int main(){
    int numero;
    cout<<"Ingrese un numero para verificar si es palindromo: ";cin>>numero;
    cout<<boolalpha<<esPalindromo(numero)<<endl;
    return 0;
}

bool esPalindromo(int numero){
    bool esPalindromo = true;
    while(esPalindromo and numero>9){
        if(!(UltimaCifra(numero) == numero%10)){
            esPalindromo = false;
        } 
        numero = eliminarUltimaCifra(numero)/10;
    }
    return esPalindromo;
}

int UltimaCifra(int numero){
    while(numero > 9){
        numero/=10;
    }
    return numero;
}

int eliminarUltimaCifra(int numero){
    int numeroFinal = 0;
    while(numero > 9){
        numeroFinal = numeroFinal * 10 + numero%10; 
        numero/=10;
    }
    return numeroFinal;
}