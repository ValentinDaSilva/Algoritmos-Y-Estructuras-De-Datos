#include<iostream>
#include<cstring>
using namespace std;

bool estaEnElVector(char[],char);
bool paralbraAnagrama(char[],char[]);

int main(){
    char palabra1[15],palabra2[15];
    cout<<"Palabra 1: ";cin.getline(palabra1,15);
    cout<<"Palabra 2: ";cin.getline(palabra2,15);
    if(strlen(palabra1) == strlen(palabra2) and paralbraAnagrama(palabra1,palabra2)) cout<<"Son anagramas"<<endl;
    else cout<<"No son anagramas"<<endl;
    return 0;   
}

bool paralbraAnagrama(char v1[],char v2[]){
    if(v1[0] == '\0') return true;
    if(estaEnElVector(v2,v1[0])) return paralbraAnagrama(&v1[1],v2);
    return false;
}

bool estaEnElVector(char v[],char caracter){
    if(v[0] == '\0') return false;
    if(v[0] == caracter) return true;
    return estaEnElVector(&v[1], caracter);
}