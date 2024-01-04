#include<iostream>
using namespace std;

struct Persona
{
    string nombre;
    int edad;
    float salario;
    string DNI;
};


int main(){
    Persona Valentin = {"Valentin", 22,1500000,"43.647.177"};
    cout<<Valentin.nombre<<endl;
    return 0;
}