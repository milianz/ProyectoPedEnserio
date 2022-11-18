#include <iostream>
#include <fstream>

using namespace std;

//Prototipos de las funciones.
void BuscarEquipo();
//Funcion para bucar un equipo en un fichero
void BuscarEquipo()
{
    system("cls");

    //Declaracion de la variable de tipo "archivo"
    ifstream archivo;
    archivo.open("RegistroEquipos.txt",  ios::in);

    //Declaracion de variables normales.
    int win, lose;
    string nombre, nombreBuscar, connferencia;
    bool equipoEncontrado = false;

    //Limpiar el buffer.
    fflush(stdin);

    //Pedir datos al usuario.
    cout << "\nDigite el nombre del equipo: ";
    getline(cin, nombreBuscar);
    archivo >> nombre;

    cout<<"\n"<<"EQUIPO"<<"\t\t"<<"W"<<"\t"<<"L"<<"\t"<<"CONFERENCIA"<<endl;

    //Buscando el equipo en el fichero...
    while (!archivo.eof() && !equipoEncontrado)
    {
        archivo >> win;
        archivo >> lose;
        archivo >> connferencia;

        if(nombre == nombreBuscar)
        {
            cout<<nombre<<"\t\t"<<win<<"\t"<<lose<<"\t"<<connferencia<<endl;
            equipoEncontrado = true;
        }

        archivo >> nombre;
    }

    archivo.close();
    
    //Si el equipo no ha sido encontrado...
    if(!equipoEncontrado)
    {
        system("cls");
        cout << "El Equipo " << "["<<nombreBuscar<<"]" << " no ha sido encontrado." << endl;
    }

}