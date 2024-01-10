#include<iostream>
using namespace std;

int main(){
    int cantMujeres,cantHombres,total;
    cout<<"Cantidad Mujeres: ";cin>>cantMujeres;
    cout<<"Cantidad Hombres: ";cin>>cantHombres;
    total = cantHombres + cantMujeres;
    cout<<"Porcentaje Mujeres: "<<cantMujeres*100/(float)total<<"%"<<endl;
    cout<<"Porcentaje Hombres: "<<cantHombres*100/(float)total<<"%"<<endl;
    return 0;
}