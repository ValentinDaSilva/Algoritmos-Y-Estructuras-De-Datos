#include<iostream>
#include<math.h>
using namespace std;
const int cantPartidas = 150, dimension = 10;
struct JUGADOR {
    string nombre = "";
    int cantIntentos = 0;
};

struct TABLERO { 
  char Matriz[dimension][dimension];
};
typedef TABLERO* Tablero;

struct PARTIDA{
    TABLERO tablero;
    JUGADOR jugador1;
    JUGADOR jugador2;
    int N;
}Partida[cantPartidas];

int partidasGanadas(PARTIDA[],int);
bool hayGanador(PARTIDA);

int main(){
    
    return 0;
}

int partidasGanadas(PARTIDA partidas[],int TL){
    if(TL == 0) return 0;
    if(hayGanador(partidas[0])) return 1 + partidasGanadas(&partidas[1],--TL);
    return partidasGanadas(&partidas[1],--TL);
}

bool intentosAgotados(PARTIDA partida){
    int contadorLetras = 0, contadorNumeros = 0;
    for(int i = 0 ; i < sqrt(partida.N) ; i++){
        for(int j = 0 ; j < sqrt(partida.N) ; j++){
            if(variableLetra(partida.tablero.Matriz[i][j])) contadorLetras++;
            else contadorNumeros++;
        }
    }
    if(contadorLetras == partida.N/2 and contadorNumeros == partida.N/2) return true;
    return false;
}

/* Forma del profesor
bool intentosAgotados(PARTIDA partida){
    return (partida.jugador1.cantIntentos == n*n/2 and partida.jugador2.cantIntentos == n*n / 2);
}
 */

void limpiarTablero(PARTIDA partida , int numeroJugador){
    for(int i = 0; i < sqrt(partida.N); i++){
        cout<<"[ ";
        for(int j = 0; j < sqrt(partida.N); j++){
            char valor = partida.tablero.Matriz[i][j];
            if(numeroJugador == 1 and !variableLetra(valor)) cout<<"- ";
            else if(numeroJugador == 2 and variableLetra(valor)) cout<<"- ";
            else cout<<valor;
            
        }
        cout<<"]"<<endl;
    }
}

string jugadorMasivo(PARTIDA partidas[],int TLPartidas){
    string* nombres = new string [TLPartidas*2];
    int TLNombres = 0;
    string nombre;
    for(int i = 0; i < TLPartidas; i++){
        nombres[TLNombres] = partidas[i].jugador1.nombre;
        TLNombres++;
        nombres[TLNombres] = partidas[i].jugador1.nombre;
        TLNombres++;
    }
    int* cantidad = new int [TLNombres];
    for(int i = 0; i < TLNombres; i++){
        cantidad[i] = cantidadDeVecesNombre(nombres,TLNombres, nombres[i]);
    }
    int posicionMayor = buscarPosicionMayor(cantidad,TLNombres);
    nombre = nombres[posicionMayor];
    delete[] nombres;
    delete[] cantidad;
    return nombre;
}

int buscarPosicionMayor(int cantidad[], int TL){
    int posicion, valor;
    for(int i = 0 ; i < TL; i++){
        if(i == 0 or cantidad[i] > valor) {
            posicion = i;
            valor = cantidad[i];
        }
        
    }
    return posicion;
}

int cantidadDeVecesNombre(string nombres[],int TL,string nombre){
    if(TL == 0) return 0;
    if(nombres[0] == nombre) return 1 + cantidadDeVecesNombre(&nombres[1],--TL,nombre);
    return cantidadDeVecesNombre(&nombres[1],--TL,nombre);
}

bool hayGanador(PARTIDA partida){
    bool encontrado = false;
    int i = 0;
    while(!encontrado and i < sqrt(partida.N) ){
        int j = 0;
        bool esLetra = false, esNumero = false;
        encontrado = true;
        while(!encontrado and j < sqrt(partida.N) ){
            if(j == 0){
                esLetra = variableLetra(partida.tablero.Matriz[i][j]);
                esNumero = !esLetra;
            }else{
                if(esLetra and !variableLetra(partida.tablero.Matriz[i][j])) encontrado = false;
                else if(esNumero and variableLetra(partida.tablero.Matriz[j][i])) encontrado =  false;
            }
            j++;
        }
        i++;
    }
    if(!encontrado){
        int i = 0;
        while(!encontrado and i < sqrt(partida.N) ){
            int j = 0;
            bool esLetra = false, esNumero = false;
            encontrado = true;
            while(!encontrado and j < sqrt(partida.N) ){
                if(j == 0){
                    esLetra = variableLetra(partida.tablero.Matriz[j][i]);
                    esNumero = !esLetra;
                }else{
                    if(esLetra and !variableLetra(partida.tablero.Matriz[j][i])) encontrado = false;
                    else if(esNumero and variableLetra(partida.tablero.Matriz[j][i])) encontrado =  false;
                }
                j++;
            }
            i++;
        } 
    }
    if(!encontrado){
        bool esLetra = variableLetra(partida.tablero.Matriz[0][0]);
        bool esNumero = !esLetra;
        bool encontrado = true;
        int i = 0;
        while(i < sqrt(partida.N) and encontrado){
            if(esLetra and !variableLetra(partida.tablero.Matriz[i][i])) encontrado = false;
            if(esNumero and variableLetra(partida.tablero.Matriz[i][i])) encontrado = false;
            i++;
        }
    }
    if(!encontrado){
        int i = sqrt(partida.N) - 1, j = i;
        bool esLetra = variableLetra(partida.tablero.Matriz[j][i]);
        bool esNumero = !esLetra;
        bool encontrado = true;
        while(i >= 0 and j >= 0 and encontrado){
            if(esLetra and !variableLetra(partida.tablero.Matriz[i][j])) encontrado = false;
            if(esNumero and variableLetra(partida.tablero.Matriz[i][j])) encontrado = false;
            i--;j--;
        }
    }
    return encontrado;
}

bool variableLetra(char caracter){
    return (caracter > 'A' and caracter < 'Z');
}