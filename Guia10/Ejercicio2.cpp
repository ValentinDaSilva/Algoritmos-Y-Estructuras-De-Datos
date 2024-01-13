#include<iostream>
#include<fstream>
using namespace std;

void aplicarClave(string&,int);

int main(){
    ifstream original("original.txt",ios::app);
    if(original.fail()) cout<<"No se pudo abrir el archivo."<<endl;
    else{
        string aux, cadena = "";
        while(original.good()){
            getline(original,aux);
            cadena += aux; 
        }
        original.close();
        cout<<"Ingrese la clave: "<<endl;
        int clave;
        cin >> clave;
        aplicarClave(cadena,clave);
        ofstream enclave("enclave.txt",ios::trunc);
        enclave << cadena;
    }
    return 0;
}

void aplicarClave(string& cadena,int clave){
    for(int i = 0 ; i < cadena.length(); i++){
        cadena[i] += clave;
    }
}