/* Sean a, b y c tres variables de tipo int cuyos valores actuales son 0, 1 y 2 respectivamente: ¿qué valor
tiene cada variable tras ejecutar esta secuencia de asignaciones?
● a = b++ - c-- ;
  a = 1 - 2 = -1
  b = 2
  c = 1
● a += --b;
  a = a --b
  0 = 0 0
  a = 0, b = 0, c = 2  
● c *= a + b;
  c = c * a + b
  c = c * 1
  a = 0 , b = 1, c = 2
● b = (a > 0) ? ++a : ++c;
  b = ++c
  b = 3
  a = 0 , b = 3 , c = 3.
● a += a = b + c;
  a = a + a = b + c
  a = a + a = 3
  a = 3 + 3
  a = 6 , b = 1 , c = 2
 */

#include<iostream>
using namespace std;

int main(){
    int a = 0, b = 1, c = 2;

    a += a = b + c; // expresion de arriba
    
    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<endl;
    cout<<"C: "<<c<<endl;
    return 0;
}