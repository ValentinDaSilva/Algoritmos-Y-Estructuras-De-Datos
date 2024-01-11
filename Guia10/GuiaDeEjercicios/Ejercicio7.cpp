#include<iostream>
#include<ctime>
using namespace std;

struct PERSONA { 
    long dni; 
    string nombre = ""; 
    int edad;
    char sexo;
    PERSONA* siguiente;
};
typedef PERSONA* Persona;

struct PILA {
    Persona mujer  = new PERSONA;
    PILA* siguiente;
};
typedef PILA* Pila;

struct COLA {
    Persona persona = NULL;
    COLA* siguiente;
};
typedef COLA* Cola;

void cargarHombres(Persona&,int);
void cargarMujeres(Persona&,int);
void mostrarLista(Persona);
void apilar(Pila& ,Persona);
void eliminarNodo(Persona&, Persona);
void mostrarLista(Pila);
void buscarMujeresDeMenorEdad(Persona,Pila&);
Persona buscarMenorEdad(Persona);
void desapilar(Pila&);
void encolar(Cola&,Cola&,Persona);
void encolar(Cola&,Cola&);
int main(){
    srand(time(NULL));
    Persona hombres = NULL, mujeres = NULL;
    Pila mujeresConMenColagggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbosEdad = NULL;
    Cola frente = nullptr, final = nullptr;
    int cantHombres,cantMujeres;
    cout<<"Cantidad de hombres: "; cin>>cantHombres;
    cout<<"Cantidad de mujeres: "; cin>>cantMujeres;
    cargarHombres(hombres,cantHombres); cargarMujeres(mujeres,cantMujeres);
    mostrarLista(hombres); mostrarLista(mujeres);
    buscarMujeresDeMenorEdad(mujeres,mujeresConMenosEdad);
    cout<<"P";mostrarLista(mujeresConMenosEdad);
    encolar()
    return 0;
}

void encolar(Cola& frente, Cola& final, Persona persona){
    Cola nuevo_elemento = new COLA;
    nuevo_elemento->persona = persona;
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

void mostrarLista(Pila pila){
    if(pila == NULL){
        cout<<"-> NULL"<<endl;
        return;
    }
    cout<<" -> "<<pila->mujer->nombre;
    mostrarLista(pila->siguiente);
}

void buscarMujeresDeMenorEdad(Persona listaMujeres, Pila& pila) {
    int i = 0;
    while(i < 5 and listaMujeres != nullptr) {
        Persona menorEdad = buscarMenorEdad(listaMujeres);
        apilar(pila, menorEdad);
        eliminarNodo(listaMujeres, menorEdad);
        i++;
    }
    // mostrarLista(listaMujeres);
}

Persona buscarMenorEdad(Persona listaPersonas){
    if(listaPersonas->siguiente == NULL) return listaPersonas;
    Persona edadSiguiente = buscarMenorEdad(listaPersonas->siguiente);
    if(listaPersonas->edad < edadSiguiente->edad) return listaPersonas;
    return edadSiguiente;
}

void eliminarNodo(Persona& listaPersonas, Persona personaAEliminar) {
    if (listaPersonas == personaAEliminar) {
        Persona aux = listaPersonas;
        listaPersonas = listaPersonas->siguiente;
        delete aux;
        return;
    }
    eliminarNodo(listaPersonas->siguiente, personaAEliminar);
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

