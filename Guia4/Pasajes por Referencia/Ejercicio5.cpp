#include<iostream>
using namespace std;

int accion(float,float,float,float&,float&);

int main(){
    float n1,n2,n3,menor = 0 , mayor = 0;
    cin>>n1>>n2>>n3;
    cout<<accion(n1,n2,n3,menor,mayor)<<endl;
    cout<<"El mayor es: "<<mayor<<endl;
    cout<<"El menor es: "<<menor<<endl;
    return 0;
}

int accion(float n1, float n2, float n3,float& menor, float& mayor){
    if(n1 == n2 and n2 == n3){
        cout<<"No hay un numero mayor ni menor"<<endl;
        return -1;
    }
    if(n1 >= n2) mayor = n1;
    else mayor = n2;
    if(mayor <= n3) mayor = n3;
    if(n1 <= n2) menor = n1;
    else menor = n2;
    if(menor >= n3) menor = n3;
    if(n1 == n2 or n1 == n3 or n2 == n3) return 0;
    else return 1;
}