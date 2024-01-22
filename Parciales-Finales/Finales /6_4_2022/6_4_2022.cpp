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
    
    return 0;
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