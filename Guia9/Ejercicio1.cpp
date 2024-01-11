#include <iostream>
using namespace std;

int main() {
    float num1 = 3.1415926, num2 = 0.12345;
    float *pnum;  // (a) Declarar un puntero a float llamado pnum.

    pnum = &num1;  // (b) Asignar la dirección de la variable num1 a pnum.

    cout << "Valor apuntado por pnum: " << *pnum << endl;  // (c) Imprimir el valor de la variable apuntada por pnum.

    num2 = *pnum;  // (d) Asignar el valor de la variable apuntada por pnum a la variable num2.

    cout << "Valor de num2: " << num2 << endl;  // (e) Imprimir el valor de num2.

    cout << "Dirección de num2: " << &num2 << endl;  // Dirección de memoria de num2.
    cout << "Dirección almacenada en pnum: " << pnum << endl;  // Dirección almacenada en pnum.

    if (&num2 == pnum) {
        cout << "Las direcciones son iguales." << endl;
    } else {
        cout << "Las direcciones no son iguales." << endl;
    }

    return 0;
}
