#include<iostream>
using namespace std;

void masmas(int&);
void menosmenos(int&);

int main(){
    int numero;
    cin>>numero;
    masmas(numero);
    cout<<numero<<endl;
    menosmenos(numero);
    menosmenos(numero);//resto lo que sumo
    cout<<numero<<endl;
    return 0;
}


void masmas(int& numero) { numero += 1 ;}
void menosmenos(int& numero) { numero -= 1;}