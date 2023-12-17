#include<iostream>
using namespace std;

void tomarLetras(char[],int[],int&);
int estaEnElVector(char[],int, char);
void mostrarCantidadRepetidos(char[],int[],int);

int main(){
    char letras[27];
    int cantidades[27] = {0}, TL = 0;
    tomarLetras(letras,cantidades,TL);
    mostrarCantidadRepetidos(letras,cantidades,TL);
    return 0;
}

void mostrarCantidadRepetidos(char letras[],int cantidades[], int TL){
    if(TL == 0) return;
    if(cantidades[0] == 1) cout<<"Letra "<<letras[0]<<": "<<cantidades[0]<<" vez"<<endl;
    else cout<<"Letra "<<letras[0]<<": "<<cantidades[0]<<" veces"<<endl;
    mostrarCantidadRepetidos(&letras[1],&cantidades[1],TL-1);
}

void tomarLetras(char letras[],int cantidades[],int& TL){
    char letra;
    if(cin>>letra){
        if(estaEnElVector(letras,TL,letra) > TL){
            letras[TL] =  letra;
            cantidades[TL]++;
            TL++;
            tomarLetras(letras,cantidades,TL);
        }
        else {
            cantidades[estaEnElVector(letras,TL,letra)]++;
            tomarLetras(letras,cantidades,TL);
        }
    }else return;
}

int estaEnElVector(char v[],int TL, char letra){
    if(TL == 0) return 1;
    else{
        if(v[0] == letra) return 0;
        else return 1 + estaEnElVector(&v[1],TL-1,letra);
    }
}