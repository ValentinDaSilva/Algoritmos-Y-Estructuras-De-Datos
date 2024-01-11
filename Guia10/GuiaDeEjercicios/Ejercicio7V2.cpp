#include<iostream>
#include<ctime>
using namespace std;

struct PERSONA { 
    long dni; 
    string nombre = ""; 
    int edad;
    char sexo;
    PERSONA* siguiente = NULL;
};
typedef PERSONA* Persona;

struct PILA {
    Persona mujer  = new PERSONA;
    PILA* siguiente = NULL;
};
typedef PILA* Pila;

struct COLA {
    Persona persona = NULL;
    COLA* siguiente = NULL;
};
typedef COLA* Cola;

void cargarHombres(Persona&,int);
void cargarMujeres(Persona&,int);
void mostrarLista(Persona);
void apilar(Pila& ,Persona);
void desapilar(Pila&);
void mostrarLista(Pila);
void eliminarNodo(Persona&,Persona);
void buscarMujeresDeMenorEdad(Persona&,Pila&);
void encolar(Cola&,Cola&,Persona);
void desencolar(Cola&,Cola&);
void mostrarCola(Cola,Cola);
void unirListas(Cola&,Cola&,Persona,Persona);
Persona buscarMenorEdad(Persona);

int main(){
    srand(time(NULL));
    Persona hombres = NULL, mujeres = NULL;
    Pila mujeresConMenosEdad = NULL;
    Cola frente = nullptr, final = nullptr;
    int cantHombres,cantMujeres;
    cout<<"Cantidad de hombres: "; cin>>cantHombres;
    cout<<"Cantidad de mujeres: "; cin>>cantMujeres;
    cargarHombres(hombres,cantHombres); cargarMujeres(mujeres,cantMujeres);
    mostrarLista(hombres); mostrarLista(mujeres);
    buscarMujeresDeMenorEdad(mujeres,mujeresConMenosEdad);
    cout<<"P";mostrarLista(mujeresConMenosEdad);
    unirListas(frente,final,hombres,mujeres);
    mostrarCola(frente,final);
    return 0;
}

void mostrarCola(Cola frente , Cola final){
    if(frente == final){
        cout<<frente->persona->nombre<<" <- NULL"<<endl<<endl;;
        return;
    }
    cout<<frente->persona->nombre<<" <- ";
    desencolar(frente,final);
    mostrarCola(frente,final);
}
void encolar(Cola& frente, Cola& final, Persona persona){
    Cola nuevo_elemento = new COLA;
    nuevo_elemento->persona = persona;
    nuevo_elemento->siguiente = nullptr;
    if(frente == NULL){
        frente = final = nuevo_elemento;
    }else{
        final->siguiente = nuevo_elemento;
        final = nuevo_elemento;
    }
}

void desencolar(Cola& frente, Cola& final){
    if(frente == NULL){
        cout<<"No hay elementos para retirar"<<endl;
        return;
    }
    Cola aux = frente;
    frente = frente->siguiente;
    delete aux;
}

void unirListas(Cola& frente, Cola& final, Persona hombres, Persona mujeres){
    if(hombres != NULL and mujeres == NULL){
        encolar(frente,final,hombres);
        unirListas(frente,final,hombres->siguiente,mujeres);
        return;
    }
    else if(hombres == NULL and mujeres != NULL){
        encolar(frente,final,mujeres);
        unirListas(frente,final,hombres,mujeres->siguiente);
        return;
    }
    else if(hombres == NULL and mujeres == NULL) return;
    if(hombres->nombre < mujeres->nombre){
        encolar(frente,final,hombres);
        unirListas(frente,final,hombres->siguiente,mujeres);
        return;
    }
    else{
        encolar(frente,final,mujeres);
        unirListas(frente,final,hombres,mujeres->siguiente);
        return;
    }
}

Persona buscarMenorEdad(Persona listaPersonas){
    if(listaPersonas->siguiente == NULL) return listaPersonas;
    Persona edadSiguiente = buscarMenorEdad(listaPersonas->siguiente);
    if(listaPersonas->edad < edadSiguiente->edad) return listaPersonas;
    return edadSiguiente;
}

void buscarMujeresDeMenorEdad(Persona& lista, Pila& pila){
    Persona edadMenor = NULL;
    for(int i = 0; i < 5; i++){
        edadMenor = buscarMenorEdad(lista);
        apilar(pila,edadMenor);
        eliminarNodo(lista,edadMenor);
    }
}

void eliminarNodo(Persona& listaPersonas,Persona NodoAEliminar){
    if(listaPersonas == NULL) return;
    if(listaPersonas == NodoAEliminar){
        Persona aux = listaPersonas;
        listaPersonas = listaPersonas->siguiente;
        delete aux;
        return;
    }
    eliminarNodo(listaPersonas->siguiente,NodoAEliminar);
}

void mostrarLista(Pila pila){
    if(pila == NULL){
        cout<<"-> NULL"<<endl;
        return;
    }
    cout<<" -> "<<pila->mujer->nombre;
    mostrarLista(pila->siguiente);
}

void apilar(Pila& pila , Persona persona){
    Pila nuevo_elemento = new PILA;
    nuevo_elemento->mujer->nombre = persona->nombre;
    nuevo_elemento->mujer->edad = persona->edad;
    nuevo_elemento->mujer->dni = persona->dni;
    nuevo_elemento->siguiente = pila;
    pila = nuevo_elemento;
}

void desapilar(Pila& pila){
    Pila aux = pila;
    pila = pila->siguiente;
    delete aux;
}

void cargarHombres(Persona& persona,int cantHombres){
        string nombresHombres[] = {
            "Juan", "Carlos", "Pedro", "Diego", "Luis", "Javier", "Miguel", "Fernando", "Pablo", "José",
            "Andrés", "Alejandro", "Daniel", "Santiago", "Emilio", "Antonio", "Raúl", "Roberto", "Héctor", "Ricardo"
        };
        string apellidos[] = {
            "González", "Rodríguez", "Gómez", "Fernández", "López", "Díaz", "Martínez", "Pérez", "García", "Sanchez",
            "Romero", "Suarez", "Castro", "Dominguez", "Ramos", "Alvarez", "Torres", "Jiménez", "Vázquez", "Acosta"
        };
        for(int i = 0 ; i < cantHombres; i++){
            Persona nueva_persona = new PERSONA;
            nueva_persona->dni = rand()%70000000 + 3000000;
            nueva_persona->nombre = apellidos[rand()%20] + " " + nombresHombres[rand()%20];
            nueva_persona->edad = rand()%50 + 18;
            nueva_persona->siguiente = NULL;   
            nueva_persona->sexo = 'H';
            Persona aux1 = persona;
            Persona aux2;

            while( aux1 != NULL and nueva_persona->nombre > aux1->nombre ){
                aux2 = aux1;
                aux1 = aux1->siguiente;
            }
            
            if(aux1 == persona) persona = nueva_persona;
            else aux2->siguiente = nueva_persona;

            nueva_persona->siguiente = aux1;
        }
}

void cargarMujeres(Persona& persona,int cantMujeres){
        string nombresMujeres[] = {
            "María", "Laura", "Ana", "Sofía", "Elena", "Valentina", "Lucía", "Isabel", "Camila", "Gabriela",
            "Paula", "Florencia", "Luisa", "Antonella", "Catalina", "Rosa", "Carolina", "Juana", "Micaela", "Verónica"
        };
        string apellidos[] = {
            "González", "Rodríguez", "Gómez", "Fernández", "López", "Díaz", "Martínez", "Pérez", "García", "Sanchez",
            "Romero", "Suarez", "Castro", "Dominguez", "Ramos", "Alvarez", "Torres", "Jiménez", "Vázquez", "Acosta"
        };
        for(int i = 0 ; i < cantMujeres; i++){
            Persona nueva_persona = new PERSONA;
            nueva_persona->dni = rand()%70000000 + 3000000;
            nueva_persona->nombre = apellidos[rand()%20] + " " + nombresMujeres[rand()%20];
            nueva_persona->edad = rand()%50 + 18;
            nueva_persona->siguiente = NULL;   
            nueva_persona->sexo = 'M';
            Persona aux1 = persona;
            Persona aux2;

            while( aux1 != NULL and nueva_persona->nombre > aux1->nombre ){
                aux2 = aux1;
                aux1 = aux1->siguiente;
            }
            
            if(aux1 == persona) persona = nueva_persona;
            else aux2->siguiente = nueva_persona;

            nueva_persona->siguiente = aux1;
        }
}

void mostrarLista(Persona persona){
    if(persona == NULL){
        cout<<endl;
        return;
    }
    cout<<"Apellido y Nombre: "<<persona->nombre<<endl;
    cout<<"Edad: "<<persona->edad<<endl;
    cout<<"DNI: "<<persona->dni<<endl;
    cout<<endl;
    mostrarLista(persona->siguiente);
}