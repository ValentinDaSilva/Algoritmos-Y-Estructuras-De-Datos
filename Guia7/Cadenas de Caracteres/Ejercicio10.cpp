#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

void contarVocales(char[],int[],int&);
int cantidadPalabrasConMasDe7Letras(char[]);
void imprimirCantidadDeVocales(int[],char[]);

int main(){
    int cantidades[5] = {0},espaciosEnBlanco = 0;
    char vocales[6] = "aeiou";
    char texto[100];
    cin.getline(texto,100);
    contarVocales(texto,cantidades,espaciosEnBlanco);
    imprimirCantidadDeVocales(cantidades,vocales);
    cout<<"Porcentaje de espacios en blanco: "<<fixed<<setprecision(2)<<espaciosEnBlanco*100.0/(float)(strlen(texto))<<endl;
    cout<<"Cantidad de palabras con mas de 7 letras en el texto: "<<cantidadPalabrasConMasDe7Letras(texto)<<endl;
    cout<<"Precio del telegrama: "<<(espaciosEnBlanco + 1)*5.2;   
    return 0;
}

int cantidadPalabrasConMasDe7Letras(char texto[]){
    int i = 0, 
        cantidad = 0,
        longitud = 0;
    while(texto[i] != '\0'){
        if(texto[i] == ' '){
            if(longitud >= 7 ) cantidad++; 
            longitud = 0;
        }else{
            longitud++;
        }
        i++;
    }
    if(longitud >= 7 ) cantidad++;//para la ultima palabra
    return cantidad;
}

void contarVocales(char texto[],int vocales[],int& espaciosEnBlanco){
    if(texto[0] == '\0') return;
    if(texto[0] == 'a' || texto[0] == 'A' || texto[0] == 'á' || texto[0] == 'Á'){
        vocales[0]++;
    }
    else if(texto[0] == 'e' || texto[0] == 'E' || texto[0] == 'é' || texto[0] == 'É'){
        vocales[1]++;
    }
    else if(texto[0] == 'i' || texto[0] == 'í' || texto[0] == 'I' || texto[0] == 'Í'){
        vocales[2]++;
    }
    else if(texto[0] == 'o' || texto[0] == 'O' || texto[0] == 'Ó' || texto[0] == 'ó'){
        vocales[3]++;
    }
    else if(texto[0] == 'u' || texto[0] == 'U' || texto[0] == 'ú' || texto[0] == 'Ú'){
        vocales[4]++;
    }
    //No se porque no cuenta los acentos pero bue, debe ser algo de que los codigos ascii son en ingles.
    if(texto[0] == ' ') espaciosEnBlanco++;
    return contarVocales(&texto[1],vocales,espaciosEnBlanco);
}

void imprimirCantidadDeVocales(int cantidades[],char vocales[]){
    if(vocales[0] == '\0') return;
    cout<<"cantidades de "<<vocales[0]<<" :"<<cantidades[0]<<endl;
    imprimirCantidadDeVocales(&cantidades[1],&vocales[1]);
}