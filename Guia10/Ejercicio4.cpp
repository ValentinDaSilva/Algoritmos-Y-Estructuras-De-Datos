#include<iostream>
using namespace std;
typedef int* PInt;

PInt prueba();

int main(){
    int* v;
    v = prueba();
    for(int i = 0 ; i < 10; i++) cout<<v[i]<<" ";
    cout<<endl;
    return 0;
    
}

PInt prueba(){
    PInt v = new int[10];
    for(int i = 0 ; i < 10; i++) v[i] = i + 1;
    return v;
}