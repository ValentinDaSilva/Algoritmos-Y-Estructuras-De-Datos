#include<iostream>
#include<math.h>
using namespace std;

bool esPalindromo(int);
int invertirNumero(int);

int main(){
    int numero;
    cout<<"Ingrese un numero para verificar si es palindromo: ";cin>>numero;
    cout<<boolalpha<<esPalindromo(numero)<<endl;
    if(cin>>numero) main();
    return 0;
}

bool esPalindromo(int numero){
    bool esPalindromo = true;
    int numeroInvertido = invertirNumero(numero);
    while(numero > 0 and esPalindromo){
        if(!(numero%10 == numeroInvertido%10)) esPalindromo = false; 
        numero/=10;
        numeroInvertido/=10;
    }
    return esPalindromo;
}

int invertirNumero(int numero){
    int numeroFinal = 0;
    while(numero > 0){
        numeroFinal = numeroFinal * 10 + numero%10;
        numero/=10;
    }
    return numeroFinal;
}