#include<iostream>
using namespace std;

bool esPolindroma(string);

int main(){
    string texto;
    cout<<"Ingrese una frase para ver si es polindroma: ";getline(cin,texto);
    cout<<boolalpha<<esPolindroma(texto)<<endl;
    return 0;
}

bool esPolindroma(string texto){
    if(texto.length() < 2) return true;
    //los dos siguientes para no tener en cuenta los espacios en blanco
    else if(texto[0] == ' ') return esPolindroma(&texto[1]);
    else if(texto[texto.length() -1] == ' ') {
        texto.resize(texto.length() -1);
        return esPolindroma(texto);
    }
    if(texto[0] == texto[texto.length() -1]){
        texto.resize(texto.length() -1);
        return esPolindroma(&texto[1]);
    }
    return false;
}