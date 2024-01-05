#include <iostream>
#include <ctime>

using namespace std;


struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Direccion {
    string calle;
    int numero;
    string ciudad;
    string barrio;
};

struct Empleado {
    string nombre;
    Direccion direccion;
    Fecha fechaNacimiento;
    char sexo; // M = masculino, F = femenino
    double sueldo;
    string categoria;
    Fecha fechaIngreso;
};

string generarNombre() {
    string nombres[] = {"Juan", "María", "Luis", "Ana", "Carlos", "Laura", "Diego", "Lucía", "Pedro", "Valeria"};
    return nombres[rand() % 10];
}

string generarCiudad() {
    string ciudades[] = {"Santa Fe", "Rosario", "Córdoba", "Buenos Aires", "Mendoza", "Salta", "San Juan", "Neuquén", "Tucumán", "La Plata"};
    return ciudades[rand() % 10];
}

string generarBarrio() {
    string barrios[] = {"Centro", "Norte", "Sur", "Este", "Oeste", "Alto", "Bajo", "Viejo", "Nuevo", "San José"};
    return barrios[rand() % 10];
}

string generarCalle(){
    string callesSantaFe[] = {
        "San Martín",
        "Rivadavia",
        "3 de Febrero",
        "Sarmiento",
        "25 de Mayo",
        "Urquiza",
        "Belgrano",
        "Ituzaingó",
        "Castellanos",
        "Suipacha",
        "Salta",
        "Las Heras",
        "San Jerónimo",
        "Alvear",
        "Mendoza",
        "La Rioja",
        "Entre Ríos",
        "Balcarce",
        "Junín",
        "Azcuenaga"
    };
    return callesSantaFe[rand()%20];
}

void generarDatosEmpleado(Empleado& empleado) {
    empleado.nombre = generarNombre();
    empleado.direccion.calle = "Calle " + generarCalle();
    empleado.direccion.numero = rand() % 1000 + 1000;
    empleado.direccion.ciudad = generarCiudad();
    empleado.direccion.barrio = generarBarrio();
    empleado.fechaNacimiento.dia = rand() % 28 + 1;
    empleado.fechaNacimiento.mes = rand() % 12 + 1;
    empleado.fechaNacimiento.anio = 1970 + rand() % 50; // Asumiendo empleados entre 1970 y 2019
    empleado.sexo = (rand() % 2 == 0) ? 'M' : 'F';
    empleado.sueldo = (rand() % (100000 - 10000))+10000; // Sueldo entre 30000 y 39999
    string categorias[] = {"Operario", "Jefe de área", "Gerente"};
    empleado.categoria = categorias[rand() % 3];
    empleado.fechaIngreso.dia = rand() % 28 + 1;
    empleado.fechaIngreso.mes = rand() % 12 + 1;
    empleado.fechaIngreso.anio = 1950 + rand() % 33; // Ingreso entre 1990 y 2023
}

void mostrarEmpleados(Empleado empleados[]){
    cout << "Datos de los empleados:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Empleado " << i + 1 << ":" << endl;
        cout << "Nombre: " << empleados[i].nombre << endl;
        cout << "Dirección: " << empleados[i].direccion.calle << " " << empleados[i].direccion.numero << ", "
             << empleados[i].direccion.ciudad << ", " << empleados[i].direccion.barrio << endl;
        cout << "Fecha de nacimiento: " << empleados[i].fechaNacimiento.dia << "/"
             << empleados[i].fechaNacimiento.mes << "/" << empleados[i].fechaNacimiento.anio << endl;
        cout << "Sexo: " << empleados[i].sexo << endl;
        cout << "Sueldo: " << empleados[i].sueldo << endl;
        cout << "Categoría: " << empleados[i].categoria << endl;
        cout << "Fecha de ingreso: " << empleados[i].fechaIngreso.dia << "/"
             << empleados[i].fechaIngreso.mes << "/" << empleados[i].fechaIngreso.anio << endl;
        cout << endl;
    }
}

void generarEmpleados(Empleado empleados[], int cantidad){
    for (int i = 0; i < cantidad; ++i) {
        generarDatosEmpleado(empleados[i]);
    }
}
void imprimirEl4Empleado(Empleado);
void empleadosConSueldoMayorA(Empleado[],double);
int diferenciaEntreFechas(Fecha,Fecha);
int fechaADias(Fecha);
void merge(Empleado[],int,int,int,int);
void mergeSort(Empleado[],int,int);
void empleadosMenoresDe25(Empleado[],int,Fecha);

int main() {
    srand(time(NULL));
    Empleado empleados[10];
    generarEmpleados(empleados,10);
    mergeSort(empleados,0,9);
    mostrarEmpleados(empleados);
    imprimirEl4Empleado(empleados[3]);
    empleadosConSueldoMayorA(empleados,57500);
    empleadosMenoresDe25(empleados,25, {05,01,2024});
    return 0;
}

void mergeSort(Empleado v[], int inicio, int final){
    if( final - inicio == 0 ) return ;
    else{
        int med = (final + inicio) / 2;
        mergeSort(v,inicio,med);
        mergeSort(v,med+1,final);
        merge(v,inicio,med,med+1,final);
    }
}

void merge(Empleado v[], int inicio1, int final1, int inicio2,int final2){
    int i = inicio1, j = inicio2, k = 0;
    Empleado v2[final2-inicio1+1];
    while(i <= final1 and j <= final2){
        if(v[i].nombre < v[j].nombre) v2[k++] = v[i++];
        else v2[k++] = v[j++];
    }
    while(i <= final1) v2[k++] = v[i++];
    while(j <= final2) v2[k++] = v[j++];
    for(int i = 0; i < final2-inicio1+1;i++){
        v[inicio1+i] = v2[i];
    }
}

void empleadosMenoresDe25(Empleado empleados[], int edad, Fecha fechaActual){
    int diferencia, diferenciaCon25Anios;
    Fecha AniosAntes25 = {fechaActual.dia,fechaActual.mes,fechaActual.anio-25}; 
    for(int i = 0 ; i < 10; i++){
        diferencia = diferenciaEntreFechas(empleados[i].fechaNacimiento,fechaActual);
        diferenciaCon25Anios = diferenciaEntreFechas(AniosAntes25,fechaActual);
        if(diferenciaCon25Anios > diferencia){
            cout<<"El empleado "<<empleados[i].nombre<<" tiene menos de 25"<<endl;
        }
    }
    cout<<endl;
}

void empleadosConSueldoMayorA(Empleado empleados[],double sueldo){
    for(int i = 0 ; i < 10; i++){
        if(empleados[i].sueldo >= sueldo) cout<<"El empleado "<<empleados[i].nombre<<" cobra mas de $"<<sueldo<<endl; 
    }
    cout<<endl;
}

void imprimirEl4Empleado(Empleado empleado){
    cout<<"Empleado 4:"<<endl;
    cout<<"Nombre: "<<empleado.nombre<<endl;
    cout<<"Direccion: "<<empleado.direccion.calle<<" "<<empleado.direccion.numero<<", "<<empleado.direccion.ciudad<<endl;
    cout<<"Fecha Nacimiento: "<<empleado.fechaNacimiento.dia<<"/"<<empleado.fechaNacimiento.mes<<"/"<<empleado.fechaNacimiento.anio<<endl;
    cout<<"Sexo: "<<empleado.sexo<<endl;
    cout<<"Sueldo: $"<<empleado.sueldo<<endl;
    cout<<"Categoria: "<<empleado.categoria<<endl;
    cout<<"Fecha ingreso: "<<empleado.fechaIngreso.dia<<"/"<<empleado.fechaIngreso.mes<<"/"<<empleado.fechaIngreso.anio<<endl;
    cout<<endl<<endl;
}

void empleadosConMasDe5Anios(Empleado empleados[],Fecha fechaActual){
    int diferencia, diferenciaCon5Anios;
    Fecha AniosAntes5 = {fechaActual.dia,fechaActual.mes,fechaActual.anio-5}; 
    for(int i = 0; i < 10; i++){
        diferencia = diferenciaEntreFechas(empleados[i].fechaIngreso,fechaActual);
        diferenciaCon5Anios = diferenciaEntreFechas(AniosAntes5,fechaActual);
        if(diferenciaCon5Anios < diferencia){
            empleados[i].sueldo *= (1 + 0.15); 
        }
    }
}

int fechaADias(Fecha fecha){
    int dias = 0;
    for(int i = 1980; i < fecha.anio; i++){
        if((i%4 == 0 and i%100 != 0) or (i%400 == 0)){
            dias += 366;
        }else{
            dias += 365;
        }
    }
    for(int i = 1; i < fecha.mes; i++){
        if(i <= 7 and i%2!= 0) dias+=31;
        else if(i <= 7 and i%2== 0) dias+=30;
        else if(i >= 8 and i != 2 and i%2!= 0) dias+=30;
        else if(i >= 8 and i != 2 and i%2== 0) dias+=31;
        else if((fecha.anio%4 == 0 and fecha.anio%100 != 0) or (fecha.anio%400 == 0)){
            dias += 29;
        }else dias += 28;
    }
    dias += fecha.dia;
    return dias;
}

int diferenciaEntreFechas(Fecha fechaIngreso, Fecha fechaActual){
    return (fechaADias(fechaActual) - fechaADias(fechaIngreso));
}