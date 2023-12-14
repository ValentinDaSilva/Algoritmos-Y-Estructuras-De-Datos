#include<iostream>
using namespace std;

int devolverOrdinal(char);

int main(){
    char letraMinuscula;
    cin>>letraMinuscula;
    cout<<devolverOrdinal(letraMinuscula)<<endl;
    if(cin>>letraMinuscula) main();
    return 0;
}

int devolverOrdinal(char letra){
    int ordinal;
    ordinal = letra - 'a' + 1;
    if(ordinal < 1 or ordinal > 26){
        ordinal = 0;         
    }
    return ordinal;
}