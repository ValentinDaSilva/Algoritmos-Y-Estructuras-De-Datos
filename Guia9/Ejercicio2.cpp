#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    float numeros[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    const int SIZE = 5;
    float* pnum = numeros;
    cout<<"[ ";
    for(int i = 0 ; i < SIZE; i++){
        if(i!=0)cout<<setw(5)<<numeros[i];
        else cout<<numeros[i];
    }
    cout<<" ]"<<endl;

    cout<<"[ ";
    for(int i = 0 ; i < SIZE; i++){
        if(i!=0)cout<<setw(5)<<*(pnum + i);
        else cout<<*(pnum + i);
    }
    cout<<" ]"<<endl;

    pnum = &numeros[3];
    cout<<*(pnum - 2)<<endl;
    return 0;
}

