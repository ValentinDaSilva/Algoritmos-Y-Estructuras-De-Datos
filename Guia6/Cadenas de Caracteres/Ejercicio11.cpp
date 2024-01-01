#include<iostream>
#include<cstring>
using namespace std;

void analizarTexto(char[]);
void desplazarDerecha(char[],int);

int main(){
    char texto[100];
    cin.getline(texto,100);
    analizarTexto(texto);
    cout<<texto<<endl;
    return 0;
}

void analizarTexto(char texto[]){
    // cout<<texto[0]<<" ";
    if(texto[0] == '\0') return;
    
    if(texto[0] == '#'){
        texto[0] = '\n';
        if(texto[1] >= 'a' and texto[1] <= 'z') texto[1] = texto[1] - 'a' + 'A';
    }
    
    if(texto[0] == '.' and texto[1] != ' '){
        if(texto[1] >= 'a' and texto[1] <= 'z') texto[1] = texto[1] - 'a' + 'A';
        desplazarDerecha(texto,(strlen(texto)));
        texto[1] = ' '; 
    }
    analizarTexto(&texto[1]);
}

void desplazarDerecha(char texto[],int TL){
    if(TL == strlen(texto)) texto[TL+1] = '\0';
    if(TL == 0) return;
    texto[TL] = texto[TL-1];    
    desplazarDerecha(texto,--TL);
}