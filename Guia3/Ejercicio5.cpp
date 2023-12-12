#include<iostream>
using namespace std;

int main(){
    int dia, mes;
    cout<<"Ingrese el dia de nacimiento: ";cin>>dia;
    cout<<"Ahora ingrese el numero de mes: ";cin>>mes;
        switch (mes)
    {
    case 1:(dia >= 21)? cout<<"Acuario"<<endl : cout<<"Capricornio"<<endl;break;
    case 2:(dia >= 20)? cout<<"Pisis"<<endl : cout<<"Acuario"<<endl;break;
    case 3:(dia >= 21)? cout<<"Aries"<<endl : cout<<"Pisis"<<endl;break;
    case 4:(dia >= 21)? cout<<"Tauro"<<endl :cout<<"Aries"<<endl;break;
    case 5:(dia >= 22)? cout<<"Geminis"<<endl : cout<<"Tauro"<<endl;break;
    case 6:(dia >= 22)? cout<<"Cancer"<<endl: cout<<"Geminis"<<endl;break;
    case 7:(dia >= 24)? cout<<"Leo"<<endl: cout<<"Cancer"<<endl;break;
    case 8:(dia >= 24)? cout<<"Virgo"<<endl: cout<<"Leo"<<endl;break;
    case 9:(dia >= 24)? cout<<"Libra"<<endl: cout<<"Virgo"<<endl;break;
    case 10:(dia >= 24)? cout<<"Escorpio"<<endl: cout<<"Libra"<<endl;break;
    case 11:(dia >= 23)? cout<<"Sagitario"<<endl: cout<<"Escorpio"<<endl;break;
    case 12:(dia >= 22)? cout<<"Capricornio"<<endl: cout<<"Sagitario"<<endl;break;
    default:
        break;
    }
    return 0;
}