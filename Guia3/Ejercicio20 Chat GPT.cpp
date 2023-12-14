#include <iostream>
using namespace std;

// Función para verificar si un número es "curioso"
bool esCurioso(int num) {
    int resultado = num * num; // Calcula el cuadrado del número
    
    // Comprueba si el resultado termina con el número original
    while (num > 0) {
        if (num % 10 != resultado % 10) {
            return false;
        }
        num /= 10;
        resultado /= 10;
    }
    
    return true;
}

// Función para encontrar los primeros N números curiosos
void numerosCuriosos(int N) {
    int contador = 0;
    int num = 1;
    
    while (contador < N) {
        if (esCurioso(num)) {
            cout << num << " ";
            contador++;
        }
        num++;
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Ingrese la cantidad de números curiosos que desea encontrar: ";
    cin >> N;
    
    cout << "Los primeros " << N << " números curiosos son: ";
    numerosCuriosos(N);
    
    return 0;
}
