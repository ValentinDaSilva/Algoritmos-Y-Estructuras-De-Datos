

#include<iostream>
using namespace std;
const int cantUsuarios = 100;

struct Usuario{
    string username;
    string password;
}usuario[cantUsuarios];

void baseDeDatosUsuarios();
int usuarioRegistrado(Usuario,int);
void mostrarUsuarios(int);

int main(){
    int TLUsuarios = 10;
    baseDeDatosUsuarios();
    string username,password;
    int opcion;
    do{
        cout<<"Ingrese su nombre de usuario: ";getline(cin,username);
        int indice = usuarioRegistrado({username,"XXX"},TLUsuarios); 
        cout<<indice<<endl;
        if(indice != -1){
            cout<<"Ingrese su contraseña: "; getline(cin,password);
            while(!(usuario[indice].password == password)){
                cout<<"\nContraseña incorrecta, intentelo nuevamente"<<endl;
                cout<<"Si desea abortar la operacion preciones Ctrl+D(Linux) o Ctrol+Z(Windows)"<<endl;
                getline(cin,password);
            }
            if(usuario[indice].password == password) cout<<"Logeado correctamente"<<endl;
            opcion = 1;
        }else{
            cout<<"El usuario no esta registrado, desea hacerlo? \n1.Si \n2.No"<<endl;
            cin>>opcion;
            cin.ignore();
            if(opcion == 1){
                usuario[TLUsuarios].username = username;
                cout<<"Ingrese una contraseña: ";getline(cin,password);
                usuario[TLUsuarios].password = password;
                cout<<"Listo, registrado correctamente."<<endl;
                TLUsuarios++;
                mostrarUsuarios(TLUsuarios);
                cout<<"Ahora debe iniciar sesion: "<<endl;
                opcion = 2;
            }
            else{
                cout<<"1. Salir del programa"<<endl;
                cout<<"2. Volver a intentarlo."<<endl;
                cin>>opcion;
                cin.ignore();
            }
        }
    }while(opcion != 1);
    return 0;
}

void mostrarUsuarios(int TL){
    cout<<"************* Registro ***************"<<endl;
    for(int i = 0; i < TL; i++){
        cout<<"Usuario: "<<usuario[i].username<<endl;
    }
    cout<<endl;
}

void baseDeDatosUsuarios(){
    Usuario usuariosAux[10] = {
        {"juan_perez", "contrasena123"},
        {"laura_gomez", "segura456"},
        {"carlos_1985", "privada*2022"},
        {"ana_marquez22", "clave_secreta"},
        {"javier.lopez", "micontrasena789"},
        {"marta.martinez", "martita1234"},
        {"pedro_rodriguez", "seguramente12"},
        {"elena1978", "elenitapass"},
        {"alexis_rojas", "alexisPass2023"},
        {"sandra.diaz", "contrasena2024"}
    };
    for(int i = 0; i < 10; i++){
        usuario[i] = usuariosAux[i];
    }
}

int usuarioRegistrado(Usuario UsuarioABuscar, int TL){
    int Encontrado = -1;
    int i = 0;
    while(Encontrado == -1 and i < TL){
        if(usuario[i].username == UsuarioABuscar.username) Encontrado = i;
        i++;
    }
    return Encontrado;
}

