#include<iostream>
using namespace std;
/* Un software tiene un precio dependiendo del tipo de servicio, Si es O u H, y dicho precio tambien se calcular diferente dependiendo del servidor */
int main(){
    char tipoServicio, version;
    int cantUsuarios;
    float precio;
    cout<<"Tipo de Servicio O/H: ";cin>>tipoServicio;
    cout<<"Version C/B/P: ";cin>>version;
    cout<<"Cantidad de Usuarios: ";cin>>cantUsuarios;
    switch (tipoServicio)
    {
    case 'O':
        switch (version)
        {
        case 'C':
            precio = 0;
            break;
        case 'B':
            precio = 100;
            if(cantUsuarios > 25)precio = 200;
            break;
        case 'P':
            precio = 200;
            if(cantUsuarios > 50) precio = 500;
            break;
        default:
            break;
        }
        break;
    case 'H':
        switch (version)
        {
        case 'C':
            precio = 0;
            break;
        case 'B':
            (cantUsuarios <= 25)? precio += (cantUsuarios * 1.5): precio += (cantUsuarios * 2); 
            break;
        case 'P':
            precio = 50;
            (cantUsuarios <= 50)? precio += (cantUsuarios * 2.5): precio += (cantUsuarios * 3.5); 
            break;
        break;
        }
    }
    cout<<"Precio Final: $"<<precio<<endl;
    return 0;
}

