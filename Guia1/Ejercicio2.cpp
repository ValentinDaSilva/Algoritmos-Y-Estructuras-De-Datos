#include<iostream>
using namespace std;

int main(){
    int n1,n2,n3;
    cout<<"Ingrese el código de desactivación de la bomba:"<<endl;
    cin>>n1>>n2>>n3;
    cout<<"El código de desactivación real es: "<<n3 + n3%10<<"-"<<n2 + n2%10<<"-"<<n1+n1%10<<endl;
    return 0;
}