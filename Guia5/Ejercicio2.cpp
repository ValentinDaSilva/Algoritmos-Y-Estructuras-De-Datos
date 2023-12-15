#include<iostream>
using namespace std;

void mostrarVector(int[],int);

int main(){
    int v[] = {1,2,3,4,5}, TL = 5;
    void mostrarVector(int[],int);
    return 0;
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}
