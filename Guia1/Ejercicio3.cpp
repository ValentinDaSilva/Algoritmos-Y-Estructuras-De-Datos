#include<iostream>
using namespace std;

int main(){
    int a , b, aux;
    cin>>a>>b;
    aux = a;
    a = b;
    b = aux;
    cout<<"A = "<<a<<endl;
    cout<<"B = "<<b<<endl;
    return 0;
}