#include<iostream>
using namespace std;

void replace(string&,int,int);
int find(string,string);
bool estaCompleta(string,string);

int main(){
    string texto;
    string palabraProhibida;
    int indice = 0;
    cout<<"Ingrese el texto: ";getline(cin,texto);
    cout<<"Ingrese la palabra prohibida: ";getline(cin,palabraProhibida);
    do{
        indice = find(texto,palabraProhibida);
        if(indice != -1){
            replace(texto,indice,indice + palabraProhibida.length());
        }
    }while(indice != -1);
    cout<<texto<<endl;
    return 0;
}

int find(string texto,string palabra){
    for(int i = 0; i < palabra.length(); i++) palabra[i] = tolower(palabra[i]);
    for(int i = 0; i < texto.length(); i++) texto[i] = tolower(texto[i]);
    bool encontrada = false;
    int indice = -1, i = 0;
    while(!encontrada and texto[i]!='\0'){
        if(texto[i] == palabra[0]){
            if(estaCompleta(&texto[i],palabra)){
                encontrada = true;
                indice = i;
            }
        }
        i++;
    }
    return indice;
}

bool estaCompleta(string texto,string palabra){
    if(palabra[0] == '\0') return true;
    if(texto[0] == '\0') return false;
    if(palabra[0] == texto[0]) return estaCompleta(&texto[1],&palabra[1]);
    return false;
}

void replace(string& texto,int indice, int final){
    // cout<<indice<<" "<<longitud<<endl;
    for(int i = indice; i < final; i++){
        texto[i] = 'X';
    }
}