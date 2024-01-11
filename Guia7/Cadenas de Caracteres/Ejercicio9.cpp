#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int fecha;
    cout<<"Ingrese fecha en MMDDYYYY: ";cin>>fecha;
    int dia = (fecha/100000)%10*10+(fecha/10000)%10;
    int mes = (fecha/10000000)%10*10+(fecha/1000000)%10;
    int anio = fecha%10000;
    char diaChar[3];
    char mesChar[10];
    char anioChar[5] = "1970";
    diaChar[0] = (dia/10) + '0';
    diaChar[1] = (dia%10) + '0';
    anioChar[0] = anio/1000 + '0';
    anioChar[1] = anio/100%10 + '0';
    anioChar[2] = anio/10%10 + '0';
    anioChar[3] = anio%10 + '0';
    switch(mes){
        case 1: strcpy(mesChar, "Enero");break;
        case 2: strcpy(mesChar, "Febrero");break;
        case 3: strcpy(mesChar, "Marzo");break;
        case 4: strcpy(mesChar, "Abril");break;
        case 5: strcpy(mesChar, "Mayo");break;
        case 6: strcpy(mesChar, "Junio");break;
        case 7: strcpy(mesChar, "Julio");break;
        case 8: strcpy(mesChar, "Agosto");break;
        case 9: strcpy(mesChar, "Septiembre");break;
        case 10: strcpy(mesChar, "Octubre");break;
        case 11: strcpy(mesChar, "Noviembre");break;
        case 12: strcpy(mesChar, "Diciembre");break;
    }
    cout<<diaChar<<endl;
    cout<<mesChar<<endl;
    cout<<anioChar<<endl;
    char cadena[22] = "";
    strcat(cadena,diaChar);
    strcat(cadena," de ");
    strcat(cadena,mesChar);
    strcat(cadena," del ");
    strcat(cadena,anioChar);
    cout<<cadena<<endl;
    return 0;
}