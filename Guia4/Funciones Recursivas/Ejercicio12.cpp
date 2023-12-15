#include<iostream>
using namespace std;

void explociones(int,int);


int main(){
    //Cuando n es mayor que b , explota
    int n, b;
    cin>>n>>b;
    explociones(n,b);
    return 0;
}

void explociones(int n, int b){
    if(b >= n){
        cout<<n<<" ";
    }else{
        int n1 = (n / b);
        int n2 = (n - n1);
        explociones(n1,b);
        explociones(n2,b);
    }
}