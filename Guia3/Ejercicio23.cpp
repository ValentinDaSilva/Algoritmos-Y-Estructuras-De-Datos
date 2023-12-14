#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int edad, cantGoles = 0, cantJugadores = 0, cantMayores25 = 0,cantDefensoresMasDe3Goles = 0;
    int maximoDeGoles = 0, cantAtacantesSinGoles = 0,golesGrupo1 = 0,golesGrupo2 = 0,golesGrupo3 = 0;
    char posicion;
    do{ 
        cout<<"Edad: ";cin>>edad;
        cout<<"Posicion: ";cin>>posicion;
        cout<<"Goles anotados: ";cin>>cantGoles;
        if(posicion != '0') cantJugadores++;
        if(edad > 25) cantMayores25++;
        if(posicion == 'D' and cantGoles > 3) cantDefensoresMasDe3Goles++;
        if(cantGoles > maximoDeGoles) maximoDeGoles = cantGoles;
        if(posicion == 'A' and cantGoles == 0) cantAtacantesSinGoles++;
        if(edad>15 and edad<23)golesGrupo1+=cantGoles;
        else if(edad>22 and edad<30)golesGrupo2+=cantGoles;
        else if(edad>29 and edad<37)golesGrupo3+=cantGoles;
    }while(edad != 0 or posicion != '0' or cantGoles != 0);
    cout<<"Porc.de jugadores mayores de 25 años: %"<<(cantMayores25*100.0/cantJugadores)<<endl;
    cout<<"Cant. de defensores con más de 3 goles: "<<cantDefensoresMasDe3Goles<<endl;
    cout<<"Cant. de goles del goleador del grupo: "<<maximoDeGoles<<endl;
    cout<<"Cant. de atacantes sin goles hechos: "<<cantAtacantesSinGoles<<endl;
    cout<<"Cant. de goles según grupos etarios:"<<endl;
    cout<<setw(10)<<"16-22 anios: "<<golesGrupo1<<endl;
    cout<<setw(10)<<"23-29 anios: "<<golesGrupo2<<endl;
    cout<<setw(10)<<"30-36 anios: "<<golesGrupo3<<endl;
    // cout<<"Cantidad Jugadores: "<<cantJugadores<<endl;
    return 0;
}