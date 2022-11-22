#include <iostream>
#include <fstream>
#include "BuscarEquipo.h"
#include "insertarEquipo.h"
#include "ElimarEquipo.h"
using namespace std;

int main()
{
    system("cls");
    int opc;
    do
    {
        cout << "  .:MENU:." <<  endl;
        cout << "1. Ingresar Datos de los equipos." <<endl;
        cout << "2. Buscar."<<endl;
        cout << "3. Eliminar Equipo.\n";
        cout << "0. Salir." <<endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc)
        {
            case 1:
                insertarEquipoFichero();

                cout<<"\n";
                system("pause");
                break;

            case 2:
                BuscarEquipo();

                cout<<"\n";
                system("pause");
                break;
            case 3:
                EliminarEquipo();

                cout<<"\n";
                system("pause");
                break;
            case 0:

                break;
            default:
                cout<<"esa opcion no existe.";
                system("pause");
                break;
        }
        system("cls");
    }
    while(opc!=0);
        
    return 0;
}