#include <iostream>
#include <fstream>
#include "BuscarEquipo.h"
#include "insertarEquipo.h"
using namespace std;

int main()
{
    int opc;
    do
    {
        cout << "  .:MENU:." <<  endl;
        cout << "1. Ingresar Datos de los equipos." <<endl;
        cout << "2. Buscar."<<endl;
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
        }
        system("cls");
    }
    while(opc!=0);
        
    return 0;
}