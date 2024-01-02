#include<iostream>
using namespace std;

int main(){
    string texto;
    int indice;
    cout<<"Ingrese el texto: ";getline(cin,texto);
    do{
        indice = texto.find('#');
        if(indice < texto.length()){
            texto.replace(indice,1,"\n");
            if(islower(texto[indice + 1])) texto[indice + 1] = toupper(texto[indice + 1]);
        }
    }while(indice < texto.length());

    for(int i = 0; i < texto.length(); i++){
        if(texto[i] == '.' and texto[i+1] != ' '){
            texto = texto.substr(0,i + 1) + ' ' + texto.substr(i+1);
        }
        if(texto[i] == '.' and islower(texto[i+2])){
            texto[i+2] = toupper(texto[i+2]);   
        }
    }
    cout<<texto<<endl;
    return 0;
}
