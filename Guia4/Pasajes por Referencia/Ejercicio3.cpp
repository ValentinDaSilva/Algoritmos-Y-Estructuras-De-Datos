#include<iostream>
using namespace std;

void Mover(float&, float&, char, float);

int main(){
    float PosX,PosY,magnitud;
    char direccion;
    cout<<"Ingrese PosX: ";cin>>PosX;
    cout<<"Ingrese PosY: ";cin>>PosY;
    cout<<"Ingrese Direccion a Mover A-H: ";cin>>direccion;
    cout<<"Ingrese magnitud del movimiento: ";cin>>magnitud;
    Mover(PosX,PosY,direccion,magnitud);
    cout<<"PosX: "<<PosX<<endl;
    cout<<"PosY: "<<PosY<<endl;
    return 0;
}

void Mover(float& PosX, float& PosY, char direccion, float magnitud){
    switch (direccion)
    {
    case 'A':
        PosX = PosX + magnitud;
        break;
    case 'B':
        PosX = PosX + magnitud;
        PosY = PosY + magnitud;
        ;break;
    case 'C':
        PosY = PosY + magnitud;
        ;break;
    case 'D':
        PosX = PosX + magnitud;
        PosY = PosY - magnitud;
        ;break;
    case 'E':
        PosY = PosY - magnitud;
        ;break;
    case 'F':
        PosX = PosX - magnitud;
        PosY = PosX - magnitud;
        ;break;
    case 'G':
        PosX = PosX - magnitud;
        ;break;
    case 'H':
        PosX = PosX - magnitud;
        PosY = PosY + magnitud;
        ;break;
    }
}