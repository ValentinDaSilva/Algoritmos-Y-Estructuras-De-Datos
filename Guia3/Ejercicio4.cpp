#include<iostream>
using namespace std;

int main(){
    int numero;
    cout<<"Ingrese un numero para verificar si es capicupa: "<<endl;
    cin>>numero;
    if(numero%10 == numero/100 and numero/1000 == 0) cout<<"Es Capicua"<<endl;
    else cout<<"No es capicua"<<endl;
    return 0;
}