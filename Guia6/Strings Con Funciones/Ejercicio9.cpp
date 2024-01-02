#include<iostream>
using namespace std;

int main(){
    string fechaNumeros,fechaTexto = "";
    cout<<"Ingrese una fecha MMDDYYYY: "<<endl; getline(cin,fechaNumeros);
    fechaTexto += fechaNumeros.substr(2,2);
    fechaTexto += " de ";
    string mes = fechaNumeros.substr(0,2);
    if(mes == "01") fechaTexto += "Enero";
    else if(mes == "02") fechaTexto += "Febrero";
    else if(mes == "03") fechaTexto += "Marzo";
    else if(mes == "04") fechaTexto += "Abril";
    else if(mes == "05") fechaTexto += "Mayo";
    else if(mes == "06") fechaTexto += "Junio";
    else if(mes == "07") fechaTexto += "Julio";
    else if(mes == "08") fechaTexto += "Agosto";
    else if(mes == "09") fechaTexto += "Septiembre";
    else if(mes == "10") fechaTexto += "Octumbre";
    else if(mes == "11") fechaTexto += "Noviembre";
    else if(mes == "12") fechaTexto += "Diciembre";
    fechaTexto += " del ";
    fechaTexto += fechaNumeros.substr(4,4);
    
    cout<<"La fecha en texto es: "<<fechaTexto<<endl;
    return 0;
}