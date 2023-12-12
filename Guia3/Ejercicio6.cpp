#include<iostream>
using namespace std;

int main(){
    
    int numero;
    bool Alternante=false;
    cin>>numero;
    if(numero>999 and numero<10000){
        //Tengo que ver si su ultimo digo es par o impar
        //Si es par
        if(numero%10%2 == 0 and numero/10%10%2 != 0){
            if(numero/100%10%2 == 0 and numero/1000%2!=0){
                Alternante=true;
            }
        }
        else if(numero%10%2 != 0 and numero/10%10%2 == 0){
            if(numero/100%10%2 != 0 and numero/1000%2==0){
                Alternante=true;
            }
        }
    }
    (Alternante)? cout<<"Es Alternante"<<endl: cout<<"No es alternante"<<endl;
    
    return 0;
}