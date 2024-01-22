#include<iostream>
using namespace std;

struct LINEA{
    int numero = 0;
    string texto = "";
    LINEA* siguiente = NULL;
};
typedef LINEA* Linea;

struct CODIGOFUENTE {
    Linea lineas = new LINEA;
};

struct ENTREGA {
    int IDEstrudiante = 0;
    CODIGOFUENTE CodigoFuente;
};

struct COMISION{
    char nombre = ' ';
    ENTREGA Entregas[250];
    int cantEstudiantes = 0;
};

void cargarDatos(COMISION&,COMISION&,COMISION&);
int** codigosDuplicados(COMISION,COMISION,COMISION);
bool EntregasIguales(CODIGOFUENTE,CODIGOFUENTE);
void compararConComision(COMISION,COMISION,int**,int&);
int** cantidadPalabrasClave(COMISION,string[],int);
int cantPalabraPorLinea(Linea,string);
void mostrarMatriz(int**,int,int);
void merge(Linea,int,int,int,int);
void mergeSort(Linea,int,int);
Linea ordenarCodigoFuente(CODIGOFUENTE);
int cantLineas(CODIGOFUENTE);
Linea pruebaDeOrdenar();

int main(){
    COMISION A,B,C;
    A.cantEstudiantes = 2;
    B.cantEstudiantes = 3;
    C.cantEstudiantes = 3;
    cargarDatos(A,B,C);
    int** duplicados = codigosDuplicados(A,B,C);
    cout<<"Parejas de codigos iguales:"<<endl;
    int i = 0;
    while(duplicados[i][0] != -1){
        cout<<"[ "<<duplicados[i][0]<<" "<<duplicados[i][1]<<" ]"<<endl;
        i++;
    }
    cout<<"Matriz de cantidad de palabras clave: "<<endl;
    string palabrasClave[] = {"kaka","using namespace","using"};
    int cantPalabrasClave = 3;
    mostrarMatriz(cantidadPalabrasClave(C,palabrasClave,3),cantPalabrasClave,C.cantEstudiantes);
    cout<<"\nCodigo Ordenado: "<<endl;
    pruebaDeOrdenar();
    return 0;
}

Linea ordenarCodigoFuente(CODIGOFUENTE codigo){
    int tamanio = cantLineas(codigo);
    Linea vectorLineas = new LINEA [tamanio];
    int i = 0;
    while(i < tamanio){
        vectorLineas[i] = *codigo.lineas;
        codigo.lineas = codigo.lineas->siguiente;
        i++;
    }
    mergeSort(vectorLineas,0,tamanio-1);
    return vectorLineas;
}

int cantLineas(CODIGOFUENTE codigo){
    if(codigo.lineas == NULL) return 0;
    return 1 + tamanioLista(codigo.lineas->siguiente);
}

int tamanioLista(Linea lista){
    if(lista == NULL) return 0;
    return 1 + tamanioLista(lista->siguiente);
}

void mergeSort(Linea v,int inicio,int final){
    if(final - inicio == 0) return;
    else{
        int med = (final + inicio)/2;
        mergeSort(v,inicio,med);
        mergeSort(v,med+1,final);
        merge(v,inicio,med,med+1,final);
    }
}

void merge(Linea v,int inicio1, int final1,int inicio2,int final2){
    int i = inicio1, j = inicio2, k = 0, TL = final2 - inicio1 + 1 ;
    Linea aux = new LINEA [TL];
    while(i <= final1 and j <= final2){
        if(v[i].numero < v[j].numero) aux[k++] = v[i++];
        else   aux[k++] = v[j++];
    }
    while( i <= final1 ) aux[k++] = v[i++];
    while( j <= final2 ) aux[k++] = v[j++];

    for(int k = 0 ; k < TL; k++){
        v[inicio1+k] = aux[k];
    }
}

void mostrarMatriz(int** Matriz, int F,int C){
    for(int i = 0 ; i < F ; i++){
        cout<<"[ ";
        for(int j = 0; j < C ; j++){
            cout<<Matriz[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
}

int cantPalabraPorLinea(Linea linea, string palabra){
    int i = 0, contador = 0;
    string aux = "";
    while(linea->texto[i + palabra.length()] != '\0'){
        aux = linea->texto.substr(i,palabra.length());
        if(aux == palabra) contador++;
        i++;
    }
    return contador;
}

int** cantidadPalabrasClave(COMISION Comision, string palabras[],int TL){
    int Matriz[TL][Comision.cantEstudiantes] = {0};
    for(int i = 0 ; i < TL; i++){
        for(int j = 0; j < Comision.cantEstudiantes ; j++){
            Matriz[i][j] = 0;
        }
    }
    for(int i = 0 ; i < TL; i++){
        for(int j = 0; j < Comision.cantEstudiantes ; j++){
            while(Comision.Entregas[j].CodigoFuente.lineas != NULL){
                Matriz[i][j] += cantPalabraPorLinea(Comision.Entregas[j].CodigoFuente.lineas,palabras[i]);
                Comision.Entregas[j].CodigoFuente.lineas = Comision.Entregas[j].CodigoFuente.lineas->siguiente;
            }
        }
    }
    int** M = new int * [TL];
    for(int i = 0 ; i < Comision.cantEstudiantes; i++) M[i] = Matriz[i];
    return M;
}

void cargarDatos(COMISION& A,COMISION& B,COMISION& C){
    A.nombre = 'A';
    B.nombre = 'B';
    C.nombre = 'C';
    Linea linea0 = new LINEA;
    Linea linea1 = new LINEA;
    Linea linea2 = new LINEA;
    Linea linea3 = new LINEA;
    Linea linea4 = new LINEA;
    Linea linea5 = new LINEA;
    linea0->numero = 0;
    linea0->texto = "using namespace std;";
    linea0->siguiente = linea1;
    linea1->numero = 1;
    linea1->texto = "int main() {";
    linea1->siguiente = linea2;
    linea2->numero = 2;
    linea2->texto = "int a = 5, b = 3;";
    linea2->siguiente = linea3;
    linea3->numero = 3;
    linea3->texto = "cout << \"Suma: \" << a + b << endl;";
    linea3->siguiente = linea4;
    linea4->numero = 4;
    linea4->texto = "return 0;";
    linea4->siguiente = linea5;
    linea5->numero = 5;
    linea5->texto = "}";
    linea5->siguiente = NULL;
    A.Entregas[0].CodigoFuente.lineas = linea0;
    A.Entregas[0].IDEstrudiante = 0;

    linea0 = new LINEA;
    linea1 = new LINEA;
    linea2 = new LINEA;
    linea3 = new LINEA;
    linea4 = new LINEA;
    linea5 = new LINEA;
    linea0->numero = 0;
    linea0->texto = "using namespace std;";
    linea0->siguiente = linea1;
    linea1->numero = 1;
    linea1->texto = "int main() {";
    linea1->siguiente = linea2;
    linea2->numero = 2;
    linea2->texto = "int x = 10;";
    linea2->siguiente = linea3;
    linea3->numero = 3;
    linea3->texto = "if (x > 5) {";
    linea3->siguiente = linea4;
    linea4->numero = 4;
    linea4->texto = "cout << \"x es mayor que 5\" << endl;";
    linea4->siguiente = linea5;
    linea5->numero = 5;
    linea5->texto = "} return 0; }";
    linea5->siguiente = NULL;
    A.Entregas[1].CodigoFuente.lineas = linea0;
    A.Entregas[1].IDEstrudiante = 1;

    linea0 = new LINEA;
    linea1 = new LINEA;
    linea2 = new LINEA;
    linea3 = new LINEA;
    linea4 = new LINEA;
    linea5 = new LINEA;
    linea0->numero = 0;
    linea0->texto = "using namespace std;";
    linea0->siguiente = linea1;
    linea1->numero = 1;
    linea1->texto = "int main() {";
    linea1->siguiente = linea2;
    linea2->numero = 2;
    linea2->texto = "int i = 0;";
    linea2->siguiente = linea3;
    linea3->numero = 3;
    linea3->texto = "while (i < 5) {";
    linea3->siguiente = linea4;
    linea4->numero = 4;
    linea4->texto = "cout << i << \" \"; i++;";
    linea4->siguiente = linea5;
    linea5->numero = 5;
    linea5->texto = "} return 0; }";
    linea5->siguiente = NULL;
    B.Entregas[0].CodigoFuente.lineas = linea0;
    B.Entregas[0].IDEstrudiante = 2;

    linea0 = new LINEA;
    linea1 = new LINEA;
    linea2 = new LINEA;
    linea3 = new LINEA;
    linea4 = new LINEA;
    linea5 = new LINEA;
    linea0->numero = 0;
    linea0->texto = "using namespace std;";
    linea0->siguiente = linea1;
    linea1->numero = 1;
    linea1->texto = "int main() {";
    linea1->siguiente = linea2;
    linea2->numero = 2;
    linea2->texto = "int numeros[] = {1, 2, 3, 4, 5};";
    linea2->siguiente = linea3;
    linea3->numero = 3;
    linea3->texto = "cout << \"Primer elemento: \" << numeros[0] << endl;";
    linea3->siguiente = linea4;
    linea4->numero = 4;
    linea4->texto = "return 0;";
    linea4->siguiente = linea5;
    linea5->numero = 5;
    linea5->texto = "}";
    linea5->siguiente = NULL;
    B.Entregas[1].CodigoFuente.lineas = linea0;
    B.Entregas[1].IDEstrudiante = 3;

    linea0 = new LINEA;
    linea1 = new LINEA;
    linea2 = new LINEA;
    linea3 = new LINEA;
    linea4 = new LINEA;
    linea5 = new LINEA;
    linea0->numero = 0;
    linea0->texto = "using namespace std;";
    linea0->siguiente = linea1;
    linea1->numero = 1;
    linea1->texto = "void saludar() {";
    linea1->siguiente = linea2;
    linea2->numero = 2;
    linea2->texto = "cout << \"Hola, ¿cómo estás?\" << endl;";
    linea2->siguiente = linea3;
    linea3->numero = 3;
    linea3->texto = "}";
    linea3->siguiente = linea4;
    linea4->numero = 4;
    linea4->texto = "int main() { saludar(); return 0; }";
    linea4->siguiente = NULL;
    C.Entregas[0].CodigoFuente.lineas = linea0;
    C.Entregas[0].IDEstrudiante = 4;

    linea0 = new LINEA;
    linea1 = new LINEA;
    linea2 = new LINEA;
    linea3 = new LINEA;
    linea4 = new LINEA;
    linea5 = new LINEA;
    linea0->numero = 0;
    linea0->texto = "using namespace std;";
    linea0->siguiente = linea1;
    linea1->numero = 1;
    linea1->texto = "int main() {";
    linea1->siguiente = linea2;
    linea2->numero = 2;
    linea2->texto = "for (int i = 0; i < 5; i++) {";
    linea2->siguiente = linea3;
    linea3->numero = 3;
    linea3->texto = "cout << i << \" \";";
    linea3->siguiente = linea4;
    linea4->numero = 4;
    linea4->texto = "}";
    linea4->siguiente = linea5;
    linea5->numero = 5;
    linea5->texto = "return 0; }";
    linea5->siguiente = NULL;
    C.Entregas[1].CodigoFuente.lineas = linea0;
    C.Entregas[1].IDEstrudiante = 5;

    B.Entregas[2].CodigoFuente.lineas = A.Entregas[0].CodigoFuente.lineas;
    B.Entregas[2].IDEstrudiante = 6;
    C.Entregas[2].CodigoFuente.lineas = B.Entregas[0].CodigoFuente.lineas;
    C.Entregas[2].IDEstrudiante = 7;
}

int** codigosDuplicados(COMISION A,COMISION B,COMISION C){
    int cantTotal = A.cantEstudiantes + B.cantEstudiantes + C.cantEstudiantes;
    int** duplicados = new int * [cantTotal];
    for(int i = 0; i < cantTotal; i++){
        duplicados[i] = new int;
        duplicados[i][0] = -1;
    }
    int TLDuplicados = 0;
    compararConComision(A,A,duplicados,TLDuplicados);
    compararConComision(A,B,duplicados,TLDuplicados);
    compararConComision(A,C,duplicados,TLDuplicados);
    compararConComision(C,B,duplicados,TLDuplicados);
    return duplicados;
}

void compararConComision(COMISION Comision1, COMISION Comision2, int** Duplicados, int& TL){
    for(int i = 0; i < Comision1.cantEstudiantes; i++){
        for(int j = 0 ; j < Comision2.cantEstudiantes; j++){
            if( Comision1.nombre != Comision2.nombre or (Comision1.nombre == Comision2.nombre and i != j ) ){
                if(EntregasIguales(Comision1.Entregas[i].CodigoFuente,Comision2.Entregas[j].CodigoFuente)){
                    int* v = new int[2];
                    v[0] = Comision1.Entregas[i].IDEstrudiante;
                    v[1] = Comision2.Entregas[j].IDEstrudiante;
                    Duplicados[TL] = v;
                    TL++;
                }
            }
        }
    }
}

bool EntregasIguales(CODIGOFUENTE Codigo1, CODIGOFUENTE Codigo2){
    bool sonIguales = true;
    while(sonIguales and Codigo1.lineas != NULL and Codigo2.lineas != NULL){
        if(Codigo1.lineas->texto == Codigo2.lineas->texto){
            Codigo1.lineas = Codigo1.lineas->siguiente;
            Codigo2.lineas = Codigo2.lineas->siguiente;
        }else{
            sonIguales = false;
        }
    }
    if((Codigo1.lineas != NULL and Codigo2.lineas == NULL) or Codigo1.lineas == NULL and Codigo2.lineas != NULL) return false; 
    return sonIguales;
}

Linea pruebaDeOrdenar(){
    Linea linea0,linea1,linea2,linea3,linea4,linea5;
    linea0 = new LINEA;
    linea1 = new LINEA;
    linea2 = new LINEA;
    linea3 = new LINEA;
    linea4 = new LINEA;
    linea5 = new LINEA;
    linea0->numero = 2;
    linea0->texto = "int x = 10;";
    linea0->siguiente = linea1;
    linea1->numero = 1;
    linea1->texto = "int main() {";
    linea1->siguiente = linea2;
    linea2->numero = 0;
    linea2->texto = "using namespace std;";
    linea2->siguiente = linea3;
    linea3->numero = 4;
    linea3->texto = "cout << \"x es mayor que 5\" << endl;";
    linea3->siguiente = linea4;
    linea4->numero = 3;
    linea4->texto = "if (x > 5) {";
    linea4->siguiente = linea5;
    linea5->numero = 5;
    linea5->texto = "} return 0; }";
    linea5->siguiente = NULL;
    CODIGOFUENTE codigo = {linea0};
    Linea vector = ordenarCodigoFuente(codigo);
    for(int i = 0 ; i < 6; i++) cout<<vector[i].texto<<endl;
    cout<<endl;
    return vector;
}