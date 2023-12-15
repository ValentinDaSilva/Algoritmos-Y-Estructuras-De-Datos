#include<iostream>
using namespace std;

bool esAnioBiciesto(int anio){
    return ((anio%100)%4 == 0);
}

bool fechaValida(int dia, int mes, int anio){
    int cantDias;
    if(mes > 12 or dia > 31) return false;
    if(mes<8){
        if(mes%2!=0) cantDias = 31;
        else cantDias = 30;
    }
    else{
        if(mes%2==0) cantDias = 31;
        else cantDias = 30;
    }
    if(mes == 2){
        if(esAnioBiciesto(anio)) cantDias = 29;
        else cantDias = 28;
    }
    if(dia > cantDias) return false;
    else  return true;
}

void diaSiguiente(int& dia, int&mes, int&anio){
    if(!fechaValida(dia,mes,anio)){
        dia = 0;
        mes = 0;
        anio = 0;
        return;
    }
    if(dia == 31 and mes == 12){
        dia = 1;
        mes = 1;
        anio = anio + 1;
        return;
    }
    dia = dia + 1;
    if(fechaValida(dia,mes,anio)) return;
    else{
        dia = 1;
        mes = mes + 1;
    }
}

int main(){
    int dia, mes , anio;
    cin>>dia>>mes>>anio;
    diaSiguiente(dia,mes,anio);
    cout<<dia<<" "<<mes<<" "<<anio<<endl;
    // cout<<fechaValida(dia,mes,anio)<<endl;
    // main();
    return 0;
}