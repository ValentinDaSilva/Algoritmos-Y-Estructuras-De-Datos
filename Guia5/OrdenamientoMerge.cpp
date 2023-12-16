#include<iostream>
using namespace std;

void mostrarVector(int[],int);
void merge(int[],int[],int,int);

int main(){
    int TL1 = 5 ,TL2 = 7 ,v1[TL1]={1, 3, 5, 5, 6, 7},v2[TL2] = {2, 2, 3, 5, 6, 7, 9 , 9};
    merge(v1,v2,TL1,TL2);
    return 0;
}

void merge(int v1[],int v2[], int TL1, int TL2){
    int i = 0, j = 0, k = 0;
    int v3[TL1+TL2];
    while(i < TL1 or j < TL2){
        if(v1[i] < v2[j]){
            v3[k++] = v1[i++];
        }else {
            v3[k++] = v2[j++];
        }
    }
    while(i < TL1){
        v3[k++] = v1[i++];
    }
    while(j < TL2){
        v3[k++] = v2[j++];
    }
    mostrarVector(v3,(TL1+TL2));
}

void mostrarVector(int v[],int TL){
    cout<<"[ ";
    for(int i = 0; i < TL; i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}