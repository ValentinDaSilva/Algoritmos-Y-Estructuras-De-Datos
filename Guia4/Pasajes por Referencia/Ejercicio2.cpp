#include<iostream>
using namespace std;

void chrtoupper(char & );

int main(){
    char caracter;
    cin>>caracter;
    chrtoupper(caracter);
    cout<<caracter<<endl;
    if(cin>>caracter) main();
    return 0;
}

void chrtoupper(char & c){
    if(c >= 'a' and c <= 'z') c = c + ('A' - 'a');
}