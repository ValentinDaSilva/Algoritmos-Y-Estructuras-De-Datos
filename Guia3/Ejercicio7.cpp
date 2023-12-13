#include<iostream>
using namespace std;

int main(){
    char modelo;
    int motor;
    cout<<"Ingrese el modelo: ";cin>>modelo;
    cout<<"Ingrese el motor: ";cin>>motor;
    switch (modelo)
    {
    case 'P':(motor == 16)? cout<<"Tapizado de Cuero y Llantas de aleación"<<endl:cout<<"Tapizado de Cuero, Llantas de aleación y Turbocompresor."<<endl;
    case 'M':(motor == 16)? cout<<"Levanta vidrios eléctrico y Espejos Retráctiles."<<endl:cout<<"Levanta vidrios eléctrico, Espejos Retráctiles y Luz de Cortesía"<<endl;
    case 'B':cout<<" Tipo de motor 16 y tipo de motor 20: Dirección asistida, ABS y Airbags"<<endl;
    return 0;
}