#include <iostream>

using namespace std;

struct ParIndiceSuma {
    int indice;
    int suma;
};

struct NodoMatriz {
    int dato;
    NodoMatriz* siguiente;
};

struct Fila {
    NodoMatriz* inicio;
};

void insertarElemento(Fila& fila, int elemento) {
    NodoMatriz* nuevoNodo = new NodoMatriz;
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = nullptr;

    if (fila.inicio == nullptr) {
        fila.inicio = nuevoNodo;
    } else {
        NodoMatriz* temp = fila.inicio;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

struct Matriz {
    Fila* filas;
    int tamano;

    Matriz(int n) {
        tamano = n;
        filas = new Fila[n];
        for (int i = 0; i < n; ++i) {
            filas[i].inicio = nullptr;
        }
    }
};

void leerMatriz(Matriz& matriz) {
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < matriz.tamano; ++i) {
        for (int j = 0; j < matriz.tamano; ++j) {
            int elemento;
            cin >> elemento;
            insertarElemento(matriz.filas[i], elemento);
        }
    }
}

bool esAislado(const Matriz& matriz, int i, int j) {
    int n = matriz.tamano;
    if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
        return false;
    }
    NodoMatriz* actual = matriz.filas[i].inicio;
    for (int k = 0; k < j; ++k) {
        actual = actual->siguiente;
    }
    return (actual->dato != actual->siguiente->dato && actual->dato != actual->siguiente->siguiente->dato);
}

void obtenerAislados(const Matriz& matriz) {
    cout << "Lista de elementos aislados: ";
    int n = matriz.tamano;
    for (int i = 0; i < n; ++i) {
        NodoMatriz* actual = matriz.filas[i].inicio;
        for (int j = 0; j < n; ++j) {
            if (esAislado(matriz, i, j)) {
                cout << actual->dato << " → ";
            }
            actual = actual->siguiente;
        }
    }
    cout << "NULL" << endl;
}

void apilar(ParIndiceSuma*& pila, int& tope, ParIndiceSuma par) {
    pila[++tope] = par;
}

ParIndiceSuma desapilar(ParIndiceSuma*& pila, int& tope) {
    if (tope > -1) {
        return pila[tope--];
    } else {
        cout << "La pila está vacía" << endl;
        return {-1, -1}; // Valor de retorno por defecto si la pila está vacía
    }
}

bool estaVacia(int tope) {
    return (tope == -1);
}

void construirPila(const Matriz& matriz) {
    int n = matriz.tamano;
    ParIndiceSuma* pila = new ParIndiceSuma[n];
    int tope = -1;
    
    cout << "Pila: ";
    for (int i = 0; i < n; ++i) {
        int suma = 0;
        NodoMatriz* actual = matriz.filas[i].inicio;
        for (int j = 0; j < n; ++j) {
            suma += actual->dato;
            actual = actual->siguiente;
        }
        apilar(pila, tope, {i + 1, suma});
    }

    // Mostrar la pila ordenada (usando un enfoque simple)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            ParIndiceSuma& actual = pila[j];
            ParIndiceSuma& siguiente = pila[j + 1];
            if (actual.suma > siguiente.suma) {
                ParIndiceSuma temp = actual;
                actual = siguiente;
                siguiente = temp;
            }
        }
    }

    // Mostrar la pila ordenada
    for (int i = 0; i < n; ++i) {
        ParIndiceSuma par = desapilar(pila, tope);
        cout << "(" << par.indice << "," << par.suma << ") → ";
    }
    cout << "NULL" << endl;

    delete[] pila;
}
//0 1 2 1 1 1 0 1 2 3 4 1 4 4 7 0
int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    Matriz M(n);
    leerMatriz(M);

    obtenerAislados(M);
    construirPila(M);

    return 0;
}
