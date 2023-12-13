#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int a, b, c;
    float resultado1, resultado2;
    cout<<"a: ";cin>>a;
    cout<<"b: ";cin>>b;
    cout<<"c: ";cin>>c;
    if(((pow(b,2)-4*a*c) >= 0) and a > 0){
        resultado1 = (-b + sqrt(pow(b,2)-4*a*c))/(2*a);
        resultado2 = (-b - sqrt(pow(b,2)-4*a*c))/(2*a);
        cout<<"Raiz 1: "<<resultado1<<endl;
        cout<<"Raiz 2: "<<resultado2<<endl;
    }
    else {
        cout<<"No existe raices reales"<<endl;
    }
    return 0;
}