#include<iostream>
using namespace std;

bool division(float,float,float&);

int main(){
    float dividendo, divisor, resultado;
    cout<<"Ingrese dividendo: ";cin>>dividendo;
    cout<<"Ingrese dividor: ";cin>>divisor;
    cout<<boolalpha<<division(dividendo,divisor,resultado)<<endl;
    if(division(dividendo,divisor,resultado)) cout<<resultado<<endl;
    return 0;
}

bool division(float dividendo,float divisor,float& resultado){
    if(divisor == 0) return false;
    resultado = dividendo / divisor;
    return true;
}
