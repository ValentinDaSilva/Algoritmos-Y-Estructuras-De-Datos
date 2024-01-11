#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char cadena1[20],cadena2[20];
    cout<<"Cadena 1: ";cin.getline(cadena1,19);
    cout<<"Cadena 2: ";cin.getline(cadena2,19);
    int long1 = strlen(cadena1), long2 = strlen(cadena2);
    if(long1 > long2){
        char aux[20] = {'\0'};
        strcat(aux,cadena2);
        strcat(cadena2,cadena1);
        strcat(cadena2,aux);
        cout<<cadena2<<endl;
    }else{
        char aux[20] =  {'\0'};
        strcat(aux,cadena1);
        strcat(cadena1,cadena2);
        strcat(cadena1,aux);
        cout<<cadena1<<endl;
    }
    return 0;
}