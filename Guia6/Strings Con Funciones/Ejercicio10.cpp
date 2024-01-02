#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    string telegrama;
    cout<<"Ingrese el telegrama para contar:"<<endl;getline(cin,telegrama);
    cout<<"1. La cantidad de veces que aparece cada vocal"<<endl;
    cout<<"2. El porcentaje de espacios en blanco"<<endl;
    cout<<"3. La cantidad de palabras con mas de 7 letras"<<endl;
    cout<<"4. Costo del telegrama ($5,2 por palabra)"<<endl;
    //Analisis del texto
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    int i = 0, cantVocales[5] = {0}, espaciosEnBlanco = 0, lognitudPalabra = 0, cantPalabrasMas7 = 0;
    while(telegrama[i] != '\0'){
        //Contar Vocales
        if(telegrama[i] == 'a' || telegrama[i] == 'á' || telegrama[i] == 'A' || telegrama[i] == 'Á') cantVocales[0]++;
        if(telegrama[i] == 'e' || telegrama[i] == 'é' || telegrama[i] == 'E' || telegrama[i] == 'É') cantVocales[1]++;
        if(telegrama[i] == 'i' || telegrama[i] == 'í' || telegrama[i] == 'I' || telegrama[i] == 'Í') cantVocales[2]++;
        if(telegrama[i] == 'o' || telegrama[i] == 'ó' || telegrama[i] == 'O' || telegrama[i] == 'Ó') cantVocales[3]++;
        if(telegrama[i] == 'u' || telegrama[i] == 'ú' || telegrama[i] == 'U' || telegrama[i] == 'Ú') cantVocales[4]++;
        //Contar Espacios en Blanco
        lognitudPalabra++;
        if(telegrama[i] == ' '){
            if(lognitudPalabra > 7) cantPalabrasMas7++;
            lognitudPalabra = 0;
            espaciosEnBlanco++;
        }
        i++;
    }
    //Esto para verificar la longitud de la ultima palabra
    if(lognitudPalabra > 7) cantPalabrasMas7++;
    for(int i = 0; i < 5; i++){
        cout<<"La vocal "<<vocales[i]<<" aparece: "<<cantVocales[i]<<endl;
    }
    cout<<endl;
    cout<<"Porcentaje de espacios en blanco: "<<fixed<<setprecision(2)<<espaciosEnBlanco*100/(float)telegrama.length()<<endl;
    cout<<"Palabras con mas de 7 letras: "<<cantPalabrasMas7<<endl;
    cout<<"Costo del telegrama: $"<<fixed<<setprecision(2)<<(espaciosEnBlanco + 1)*5.2<<endl;
    return 0;
}