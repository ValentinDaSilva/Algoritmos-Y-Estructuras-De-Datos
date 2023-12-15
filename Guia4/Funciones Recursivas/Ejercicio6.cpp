#include<iostream>
using namespace std;

int producto(int,int);

int main(){
    int n1,n2;
    cout<<"Ingrese dos numeros paramultiplicarlos: ";cin>>n1>>n2;
    cout<<"Resultado = "<<producto(n1,n2)<<endl;
    return 0;
}

int producto(int n1,int n2){
    if(n2 == 1) return n1;
    return n1 + producto(n1,n2-1);
}