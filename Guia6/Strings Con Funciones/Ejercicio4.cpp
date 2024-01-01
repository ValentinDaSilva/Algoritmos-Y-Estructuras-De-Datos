#include<iostream>
using namespace std;

int main(){
    string palabra1, palabra2;
    getline(cin,palabra1);
    getline(cin,palabra2);
    if(palabra1.length() < palabra2.length()){
        cout<<palabra1<<palabra2<<palabra1<<endl;
    }else{
        cout<<palabra2<<palabra1<<palabra2<<endl;
    }
    return 0;
}
