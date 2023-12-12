/* ¿Qué valor se almacena en las variables i (de tipo int) y x (de tipo float) tras ejecutar cada una de estas
sentencias?
● i = 2; 2
● i = 2 / 4; 0
● x = 2.0 / 4.0; 0.5
● x = 2 / 4; 0
● i = 2.0 / 4; 0
● x = 2.0 / 4;  0.5
*/

#include<iostream>
using namespace std;

int main(){
    int i = 9999; float x = 9999;
    x = 2.0 / 4;
    cin>>i;
    cout<<"i: "<<i<<endl;
    cout<<"x: "<<x<<endl;
    return 0;
}