#include<iostream>
#include<time.h>
#include<cstring>
#include<fstream>
using namespace std;
int cantRegistrados = 0;

struct Usuario{
    char username[11];
    char password[37];
    tm time;
};

void mostrarUsuarios(Usuario*);
void registroUsuarios();
Usuario* cargarUsuarios();
void guardarEnArchivo(Usuario);


int main(){
    Usuario* usuarios = NULL;
    int opcion;
    cout<<"Que desea hacer?"<<endl;
    cout<<"1. Ver usuarios existentes"<<endl;
    cout<<"2. Crear un nuevo usuario"<<endl;
    cin>>opcion;
    cin.ignore();
    switch (opcion)
    {
    case 1:
        usuarios = cargarUsuarios();
        mostrarUsuarios(usuarios);
        break;
    case 2:
        registroUsuarios();
        break;
    }
    return 0;
}

void mostrarUsuarios(Usuario* usuario){
    if(usuario != NULL){
        for(int i = 0 ; i < cantRegistrados; i++){
            cout<<"Usuario: "<<usuario[i].username<<endl;
            cout<<"Contraseña: "<<usuario[i].password<<endl;
            cout<<"Ultimo Ingreso: ";
            cout<<usuario[i].time.tm_mday<<"/"<<(usuario[i].time.tm_mon)+1<<"/"<<usuario[i].time.tm_year + 1900<<" ";
            cout<<usuario[i].time.tm_hour<<":"<<usuario[i].time.tm_min<<":"<<usuario[i].time.tm_sec<<endl;
        }
    }
}

void registroUsuarios(){
    Usuario usuario;
    string auxiliar;
    cout<<"**********Registro de usuarios**********"<<endl;
    do{
        cout<<"Ingrese el usuario: ";getline(cin,auxiliar);
        while(auxiliar.length() > 10){
            cout<<"El usuario debe tener menos de 11 caracteres"<<endl;
            getline(cin,auxiliar);
        }
        strcpy(usuario.username,auxiliar.c_str());
        if(auxiliar != "0"){
            cout<<"Ingrese la contraña: ";getline(cin,auxiliar);
            while(auxiliar.length() > 36){
                cout<<"La contraseña debe tener menos de 37 caracteres"<<endl;
                getline(cin,auxiliar);
            }
            strcpy(usuario.password,auxiliar.c_str()); 
            time_t ahora;
            time(&ahora);
            usuario.time = *localtime(&ahora);
            cout<<usuario.time.tm_hour<<endl;
            guardarEnArchivo(usuario);
        }
    }while(auxiliar != "0");
}

Usuario* cargarUsuarios(){
    ifstream archivoBinario("Usuarios.dat",ios::binary);
    archivoBinario.seekg(0,ios::end);
    cantRegistrados = archivoBinario.tellg() / sizeof(Usuario);
    archivoBinario.seekg(0,ios::beg);
    if(cantRegistrados > 0){
        Usuario* vectorUsuarios = new Usuario[cantRegistrados];
        archivoBinario.read((char*)vectorUsuarios,sizeof(Usuario)*cantRegistrados);
        return vectorUsuarios;
    }
    return NULL;
}

void guardarEnArchivo(Usuario usuario){
    ofstream archivoBinario("Usuarios.dat", ios::binary | ios::app);
    if(archivoBinario.fail()) cout<<"Error al abrir el archivo"<<endl;
    else {
        archivoBinario.write((char*)&usuario,sizeof(Usuario));
        archivoBinario.close();
    }
}