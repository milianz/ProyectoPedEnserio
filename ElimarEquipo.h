#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void EliminarEquipo()
{
    system("cls");

    //Declaracion de la variable de tipo "archivo"
    ifstream archivo;
    archivo.open("RegistroEquipos.txt",  ios::in);

    //Crear un fichero temporal.
    ofstream archivoTemporal("RegistroTemporal.txt", ios::out);

    //Declaracion de variables normales.
    int win, lose;
    string equipo, equipoEliminar, conferencia;
    //Limpiar el buffer.
    fflush(stdin);
    cout << "Ingrese el equipo que desea eliminar: ";
    getline(cin, equipoEliminar);

    archivo>>equipo;

    while (!archivo.eof())
    {
        archivo >> win;
        archivo >> lose;
        archivo >> conferencia;

        if(equipo == equipoEliminar)
        {
            cout << "El equipo [" << equipoEliminar << "] ha sido eliminado." << endl; 
        }
        else
        {
            //Pasar toda la informacion al fichero temporal sin el registro encontrado.
            archivoTemporal << equipo << "\t\t" <<win<< "\t\t" << lose << "\t\t " << conferencia <<endl;
        }

        archivo >> equipo;
    }
    
    //Cerrar ficheros.
    archivo.close();
    archivoTemporal.close();

    //Eliminar el archvio de texto "orginal".
    remove("RegistroEquipos.txt");

    //Renombrar el registr temporal para convertirlo en el nuevo archivo de texto "original".
    rename("RegistroTemporal.txt", "RegistroEquipos.txt");
}