#include<iostream>
using namespace std;
/* calcular perimetro especifico de un triangulo,  */
int main(){
    int tipoTriangulo;
    float perimetro, lado1, lado2, lado3;
    cout<<"Ingrese el tipo de triangulo: "<<endl;
    cout<<"1. Triangulo Isoceles"<<endl;
    cout<<"2. Triangulo Equilatero"<<endl;
    cout<<"3. Triangulo Escaleno"<<endl;
    cin>>tipoTriangulo;
    switch (tipoTriangulo)
    {
    case 1: 
        cout<<"El Lado 1: ";cin>>lado1;
        cout<<"El Lado 2: ";cin>>lado2;
        perimetro = 2 * lado1 + lado2; 
        break;
    case 2: 
        cout<<"El Lado: ";cin>>lado1;
        perimetro = lado1 * 3; 
        break;
    case 3:         
        cout<<"Lado 1: "; cin>>lado1;
        cout<<"Lado 2: "; cin>>lado2;
        cout<<"Lado 3: "; cin>>lado3;
        perimetro = lado1 + lado2 + lado3; 
        break;
    default:
        cout<<"No es un tipo de triangulo valido para el programa"<<endl;
        break;
    }
    cout<<"El Perimetro de tu recutangulo es de:"<<perimetro<<endl;
    return 0;
}