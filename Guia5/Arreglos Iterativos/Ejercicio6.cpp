#include<iostream>
using namespace std;

int existeLaLetra(char[],int,char);

int main(){
    int TL = 0, cantidades[27]= {0};
    char letra, letras[27];
    while(cin>>letra){
        if(existeLaLetra(letras,TL,letra) == -1){
            letras[TL] = letra;
            cantidades[TL]++;
            TL++;
        }else{
            cantidades[existeLaLetra(letras,TL,letra)]++;
        }
    }
    for(int i = 0; i < TL; i++){
        if(cantidades[i] == 1) cout<<"Letra "<<letras[i]<<": "<<cantidades[i]<<" vez"<<endl;
        else cout<<"Letra "<<letras[i]<<": "<<cantidades[i]<<" veces"<<endl;
    }
    return 0;
}

int existeLaLetra(char v[],int TL, char letra){
    int i = 0;
    bool encontrada = false;
    while(i < TL and !encontrada){
        if(v[i] == letra) encontrada = true;
        i++;
    }
    if(encontrada) return i-1;
    else return -1;
}