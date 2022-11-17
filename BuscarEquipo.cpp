#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Nodo
{
    string nombre, conferencia;
    int win, lose;
    Nodo *siguiente;
};

Nodo *lista = NULL;

//Prototipos de las funciones.
void BuscarEquipo();
void Menu();

//Inicio main.
int main()
{
    Menu();
    return 0;
}
//Fin main.

//Menu de opciones.
void Menu()
{
    int opc;
    do
    {
        cout << "\n\t.:Menu:." << endl;
        cout << "1. Buscar equipo." << endl;
        cout << "0. Salir." << endl;
        cout << "\nOpcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            BuscarEquipo();
            break;
        
        default:
            break;
        }
        
    }
    while (opc != 0);
}


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
        cout << "El Equipo " << nombreBuscar << " no ha sido encontrado." << endl;
    }

}