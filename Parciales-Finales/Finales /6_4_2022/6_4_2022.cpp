#include<iostream>
using namespace std;

struct LINEA{
    int numero = 0;
    string texto = "";
};
typedef LINEA* Linea;

struct CODIGOFUENTE {
    Linea lineas = new LINEA;
};

struct ENTREGA {
    int IDEstrudiante = 0;
    CODIGOFUENTE CodigoFuente;
};

struct COMISION{
    char nombre = ' ';
    ENTREGA Entregas[250];
    int cantEstudiantes = 0;
};

int main(){
    COMISION A,B,C;
    A.cantEstudiantes = 125;
    B.cantEstudiantes = 145;
    C.cantEstudiantes = 198;

    return 0;
}