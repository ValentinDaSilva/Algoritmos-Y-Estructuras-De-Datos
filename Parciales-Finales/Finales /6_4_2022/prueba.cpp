#include<iostream>
using namespace std;

int main(){
    int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<*((*M) + 1)<<endl;
    return 0;
}