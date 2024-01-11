#include<iostream>
using namespace std;

void mostrarVector(int* [],int);
void random(int[],int);

int main(){
    int TL = 10, v[TL];
    int *ptr[TL];
    random(v,TL);
    for (int i = 0; i < 10; ++i) {
        ptr[i] = &v[i];
    }
    mostrarVector(ptr,TL);
    return 0;
}
void random(int v[], int TL){
    srand(time(NULL));
    for(int i = 0; i < TL; i++){
        v[i] = rand()%50;
    }
}

void mostrarVector(int* v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<*(v[i])<<" ";
    }
    cout<<"]"<<endl;
}