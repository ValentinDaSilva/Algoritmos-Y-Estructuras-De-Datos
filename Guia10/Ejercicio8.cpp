#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
const int cantCaracteres = 10, cantLineas = 10, cantPaginas = 10;

struct Linea {
    char caracteres[cantCaracteres + 1] = " ";
};

struct Pagina{
    Linea linea[cantLineas];
};

struct Texto{
    Pagina pagina[cantPaginas];
};

void cargarTexto(Texto&,string);
void guardarTexto(Texto&);
void modificarLinea(Texto&,int,int);
void mostrarPagina(Texto,int);
void mostrarCuaderno(Texto);

int main(){
    string texto;
    Texto cuaderno;
    int opcion;
    int pagina;
    cout<<"Que desea hacer?"<<endl;
    cout<<"1. Agregar texto al cuaderno"<<endl;
    cout<<"2. Modificar una linea especifica"<<endl;
    cout<<"3. Mostrar una pagina en especifico"<<endl;
    cout<<"4. Mostrar el cuaderno completo"<<endl;
    cout<<"5. Salir"<<endl;
    cin>>opcion;
    cin.ignore();
    switch (opcion)
    {
    case 1:
        cout<<"Ingrese el texto: ";getline(cin,texto);
        cargarTexto(cuaderno,texto);
        break;
    case 2:
        int linea;
        cout<<"Que Pagina desea modificar?"<<endl; cin>>pagina;
        cout<<"Que linea desea modificar?"<<endl; cin>>linea; cin.ignore();
        modificarLinea(cuaderno,pagina,linea);
    default:
        cout<<"Que Pagina desea modificar?"<<endl; cin>>pagina;
        mostrarPagina(cuaderno,pagina);
        break;
    }
    return 0;
}

void cargarTexto(Texto& cuaderno, string texto){
    ifstream archivo("texto.dat",ios::app|ios::binary);
    archivo.read((char*)&cuaderno,sizeof(Texto));
    //todo lo que esta antes del for es para posicionar el puntero en la posicion donde se quedo escribiendo cuando agarras un struct ya empezado
    int p = 0 , l = 0, c = 0;
    while(strcmp(cuaderno.pagina[p].linea[l].caracteres, " ")){
        l++;
        if(l == cantLineas){
            l = 0;
            p++;
        }
    }
    if(l!=0) l--;
    c = 10;
    while(cuaderno.pagina[p].linea[l].caracteres[c-1] == '\0'){  
        c--;
    }
    if(c == 10){
        l++;
        c = 0;
    }
    cout<<p<<" "<<l<<" "<<c<<endl;
    int cantidadLeida = 0;
    char* textoCString = new char[texto.length()+1];
    strcpy(textoCString,texto.c_str());
    for(int i = p; i < cantPaginas and cantidadLeida < strlen(textoCString); i++){
        int j;
        if(i == p) j = l;
        else j = 0;
        for(; j < cantLineas and cantidadLeida < strlen(textoCString);){    
            for(int k = c ; k < cantCaracteres; k++, cantidadLeida++){
                cuaderno.pagina[i].linea[j].caracteres[k] = textoCString[cantidadLeida];
                if(k+1 == 10) j++;
            }
        }
    }
    mostrarCuaderno(cuaderno);
}

void guardarTexto(Texto& cuaderno){
    ofstream archivo("texto.dat",ios::trunc|ios::binary);
    archivo.write((char*)&cuaderno,sizeof(Texto));
}

void modificarLinea(Texto& cuaderno, int pagina, int linea){
    cout<<"Ingrese la nueva linea"<<endl;
    string texto;
    getline(cin,texto);
    while(texto.length() > cantCaracteres){
        cout<<"Debe tener menos de "<<cantCaracteres<<" cada linea"<<endl;
        getline(cin,texto);
    }
    char* lineaChar = new char[texto.length()];
    strcpy(lineaChar,texto.c_str());
    strcpy(cuaderno.pagina[pagina].linea[linea].caracteres,lineaChar);
}

void mostrarPagina(Texto cuaderno, int pagina){
    cout<<"Pagina "<<pagina<<":"<<endl;
    for(int j = 0; j < cantLineas; j++){    
        cout<<cuaderno.pagina[pagina].linea[j].caracteres<<endl;
    }
}

void mostrarCuaderno(Texto cuaderno){
    for(int i = 0; i < cantPaginas; i++){
        cout<<"Pagina "<<i<<":"<<endl;
        for(int j = 0; j < cantLineas; j++){    
            cout<<cuaderno.pagina[i].linea[j].caracteres<<endl;
        }
        cout<<endl;
    }
}