#include<iostream>
#include<fstream>
using namespace std;

struct USUARIO{
    string username = "";
    string password = "";
    USUARIO* siguiente = NULL;
};
typedef USUARIO* Usuario;

void agregarALaLista(Usuario&,string,string);
void mostrarLista(Usuario);
void guardarEnArchivos(Usuario);
void cargarDatos(Usuario&);

int main(){
    Usuario listaUsuarios = NULL;
    string usuario, contrasenia;
    cargarDatos(listaUsuarios);
    int opcion;
    do{
        cout<<"Que desea hacer: "<<endl;
        cout<<"1. Cargar nuevo usuario"<<endl;
        cout<<"2. Mostrar lista usuarios"<<endl;
        cout<<"3. Guardar y salir"<<endl;
        cin>>opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            cout<<"Ingrese usuario: ";getline(cin,usuario);
            cout<<"Ingrese contraseña: ";getline(cin,contrasenia);
            agregarALaLista(listaUsuarios,usuario,contrasenia);
            break;
        case 2:
            mostrarLista(listaUsuarios);
            break;
        case 3: 
            guardarEnArchivos(listaUsuarios);
        }
    }while(opcion != 3);
    return 0;
}

void cargarDatos(Usuario& usuario){
    // Abre el archivo en modo lectura binaria
    string username, password;
    ifstream archivo("registroUsuarios.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo binario para lectura." << endl;
        return;
    }
    cout<<"LLegue aca"<<endl;
    // while(!archivo.eof()){
        archivo.seekp((200,ios::cur));
        getline(archivo,username);
        archivo.seekg((12,ios::cur));
        getline(archivo,password);
        cout<<username<<" "<<password<<endl;
        // agregarALaLista(usuario,username,password);
    // }

    
    archivo.close();
    
}

void guardarEnArchivos(Usuario usuario){
    ofstream archivoUsuarios, archivoUsuariosBinario;
    archivoUsuarios.open("registroUsuarios.txt", ios::trunc);
    while(usuario != NULL){
        archivoUsuarios << "Usuario: " << usuario->username<<endl;
        archivoUsuarios << "Contraseña: " << usuario->password;
        if(usuario->siguiente != NULL) archivoUsuarios<<endl<<endl;
        usuario = usuario->siguiente;
    }
    archivoUsuarios.close();
}

void mostrarLista(Usuario usuario){
    if(usuario == NULL){
        cout<<endl;
        return;
    }
    cout<<"Usuario: "<<usuario->username<<endl;
    cout<<"Contraseña: "<<usuario->password<<endl;
    cout<<endl;
    mostrarLista(usuario->siguiente);
}

void agregarALaLista(Usuario& usuario,string username,string password){
    Usuario nuevo_usuario = new USUARIO;
    nuevo_usuario->username = username;
    nuevo_usuario->password = password;

    Usuario Aux1 = usuario;
    Usuario Aux2;

    while(Aux1 != NULL and nuevo_usuario->username > Aux1->username){
        Aux2 = Aux1;
        Aux1 = Aux1->siguiente;
    }

    if(Aux1 == usuario) usuario = nuevo_usuario;
    else Aux2->siguiente = nuevo_usuario;

    nuevo_usuario->siguiente = Aux1;
}
