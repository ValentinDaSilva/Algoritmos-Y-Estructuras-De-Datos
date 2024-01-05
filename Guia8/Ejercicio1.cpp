#include<iostream>
using namespace std;

struct punto
{
    double x;
    double y;
};

struct linea
{
    punto puntoInicio;
    punto puntoFinal;
};

struct Fecha
{
    int dia,mes,anio;
};

struct DatosPersonales {
    string nombre;
    string apellido;
    Fecha fechaNacimiento;
    string direccion;
    long int telefono;
};

struct DatosEstudiante
{
    DatosPersonales DatosPersonales;
    long int legajo;
    string carrera;
};

struct listaEstudiantes
{
    DatosEstudiante estudiante[100];
};

struct DatosEmpleado
{
    DatosPersonales DatosPersonales;
    int idEmpleado;
    string puesto;
    double salario;
};

struct Naipe
{
    string Palo;
    int valor;
};

struct Mazo
{
    Naipe carta[27];
};

struct Libro{
    string Titulo;
    string Autor;
    string genero;
    int anioPublicacion;
};

struct InventarioLibros
{
    Libro libro[100];
};



int main(){
    
    return 0;
}