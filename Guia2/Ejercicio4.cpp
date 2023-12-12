#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int cantMujeres,cantHombres,total;
    cout<<"Cantidad Mujeres: ";cin>>cantMujeres;
    cout<<"Cantidad Hombres: ";cin>>cantHombres;
    total = cantHombres + cantMujeres;
    cout<<"Porcentaje Mujeres: "<<fixed<<setprecision(2)<<cantMujeres*100/(float)total<<"%"<<endl;
    cout<<"Porcentaje Mujeres: "<<fixed<<setprecision(2)<<cantHombres*100/(float)total<<"%"<<endl;
    return 0;
}