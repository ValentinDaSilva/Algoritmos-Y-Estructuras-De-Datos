#include<iostream>
#include<math.h>
using namespace std;

int sumatoria(int,int,int);
int producto(int,int,int);
int mayorPotencia(int,int);

int main(){
    int a,b,c;
    cout<<"Ingrese 3 numeros"<<endl;    
    cin>>a>>b>>c;
    if( c > 0 ) cout<<sumatoria(a,b,c)<<endl;
    else if( c < 0) cout<<producto(a,b,c)<<endl;
    else cout<<mayorPotencia(a,b)<<endl;
    return 0;
}

int sumatoria(int a,int b, int c){
    int sumatoria = 0;
    for(int i = a; i <= b; i+=c){
        sumatoria+=i;
    }
    return sumatoria;
}

int producto(int a,int b, int c){
    int producto = 1;
    for(int i = b; i >= a; i += c){
        producto*=i;
    }
    return producto;
}

int mayorPotencia(int a,int b){
    int producto;
    (pow(a,b) > pow(b,a))? producto = pow(a,b) : producto = pow(b,a);
    return producto;
}