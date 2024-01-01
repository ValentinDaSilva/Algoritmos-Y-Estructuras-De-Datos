#include<iostream>
using namespace std;

void pasarAMiniscula(string&);

int main(){
    string palabra1,palabra2;
    bool anagramas = true;
    int indice, i = 0;
    cout<<"Palabra 1: ";getline(cin,palabra1);
    cout<<"Palabra 2: ";getline(cin,palabra2);
    pasarAMiniscula(palabra1);
    pasarAMiniscula(palabra2);
    if(palabra1.length() != palabra2.length()) anagramas = false;

    while(anagramas and i != '\0'){
        indice = palabra2.find(palabra1[i]);
        if(indice < 0 or indice > palabra1.length()) anagramas = false;
        i++;
    }
    cout<<"Son anagramas: "<<boolalpha<<anagramas;
    return 0;
}

void pasarAMiniscula(string& p){
    int i = 0;
    while(i != '\0'){
        if(isupper(p[i])) p[i] = tolower(p[i]);
        i++;
    }
}