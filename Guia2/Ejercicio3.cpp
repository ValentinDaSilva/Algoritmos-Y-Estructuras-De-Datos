/* ¿Qué valor se almacena en las variables i (de tipo int) y x (de tipo float) tras ejecutar estas sentencias?
● i = (float) 2; 2
● x = 2.0 / (int) 4.0; 0.5
● x = (float) 1 / 2; 0.5 
● i = 1 / (float) 2; 0
● x = (int) 2.0 / 4; 0
● x = 1 / (float) 2; 0.5
● i = (int) ( 2 / 4); 0
● x = (int) (2.0 / 4); 0
● x = 2 / (float) 4; 0.5
● i = (int) 2.0 / (float) 4; 0 
*/

#include<iostream>
using namespace std;

int main(){
    int i; float x;
    i = (int) 2.0 / (float) 4; 
    cout<<"i: "<<i<<endl;
    cout<<"x: "<<x<<endl;
    return 0;
}