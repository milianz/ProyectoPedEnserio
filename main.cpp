#include <iostream>
#include <fstream>
#include "BuscarEquipo.h"
#include "insertarEquipo.h"
using namespace std;

int main(){
int opc;
    cout << "  .:MENU:." <<  endl;
    cout << "1. Ingresar Datos de los equipos." <<endl;
    cout << "2. Buscar."<<endl;
    cout << "0. Salir." <<endl;
    cout << "Opcion: ";
        cin >> opc;
do{ 
    switch (opc)
        {
        case 1:
            insertarEquipoFichero();
            break;

        case 2:
            BuscarEquipo();
            break;
        default:
            cout<<"Esa Opcion no existe";
            break;

        }
    }while(opc!=0);
        
    return 0;
}