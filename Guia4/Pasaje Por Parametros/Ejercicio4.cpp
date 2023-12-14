#include<iostream>
using namespace std;

int menor(int,int,int);
int mayor(int,int,int);
int promedio(int,int,int);
int suma(int,int,int);
int main(){
    int n1,n2,n3,opcion;
    cout<<"Ingrese 3 numeros: "<<endl;
    cin>>n1>>n2>>n3;
    cout<<"Ingrese la operacion que desea realizar: "<<endl;
    cout<<"1. Mayor de los 3"<<endl;
    cout<<"2. Menor de los 3"<<endl;
    cout<<"3. Promedio de los numeros"<<endl;
    cout<<"4. Suma de los numeros"<<endl;
    cin>>opcion;
    switch (opcion)
    {
        case 1:menor(n1,n2,n3);break;
        case 2:mayor(n1,n2,n3);break;
        case 3:promedio(n1,n2,n3);break;
        case 4:suma(n1,n2,n3);break;
    }
    return 0;
}

int mayor(int n1,int n2,int n3){
    if(n1 > n2){
        if(n1 > n3) return n1;
        else return n3;
    }
    else if(n2 > n1){
        if(n2 > n3) return n2;
        else return n3;
    }
    return 0;
}

int menor(int n1,int n2,int n3){
    if(n1 < n2){
        if(n1 < n3) return n1;
        else return n3;
    }
    else if(n2 < n1){
        if(n2 < n3) return n2;
        else return n3;
    }
    return 0;
}

int suma(int n1, int n2, int n3){
    return n1 + n2 + n3;
}

int promedio(int n1, int n2, int n3){
    return suma(n1,n2,n3)/3;
}