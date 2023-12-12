#include<iostream>
using namespace std;

int main(){
    int numDia,numMes;
    cout<<"Ingrese el numero de dia"<<endl;cin>>numDia;
    cout<<"Ingrese numero de mes"<<endl;cin>>numMes;
    switch (numDia)
    {
    case 1:cout<<"Dia Lunes"<<endl;break;
    case 2:cout<<"Dia Martes"<<endl;break;
    case 3:cout<<"Dia Miercoles"<<endl;break;
    case 4:cout<<"Dia Jueves"<<endl;break;
    case 5:cout<<"Dia Viernes"<<endl;break;
    case 6:cout<<"Dia Sabado"<<endl;break;
    case 7:cout<<"Dia Domingo"<<endl;break;
    default:
        cout<<"Ese numero de dia no es correcto"<<endl;break;
    }
    switch (numMes)
    {
    case 1:cout<<"Mes Enero"<<endl;break;
    case 2:cout<<"Mes Febrero"<<endl;break;
    case 3:cout<<"Mes Marzo"<<endl;break;
    case 4:cout<<"Mes Abril"<<endl;break;
    case 5:cout<<"Mes Mayo"<<endl;break;
    case 6:cout<<"Mes Junio"<<endl;break;
    case 7:cout<<"Mes Julio"<<endl;break;
    case 8:cout<<"Mes Agosto"<<endl;break;
    case 9:cout<<"Mes Septiembre"<<endl;break;
    case 10:cout<<"Mes Octubre"<<endl;break;
    case 11:cout<<"Mes Noviembre"<<endl;;
    case 12:cout<<"Mes Diciembre"<<endl;break;
    default:
        break;
    }
    return 0;
}