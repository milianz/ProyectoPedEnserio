#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Nodo
{
    int puntos1 = 0, puntos2 = 0;

    string equipo1, equipo2, 
    conferencia1, conferencia2, 
    fechapartido;

    Nodo *siguiente, *anterior;
};

Nodo *lista = NULL;

//Prototipo de las funciones.
void InsertarPartidoFichero();
void AgregarPartido();


//Inicio main
int main()
{
    InsertarPartidoFichero();

    return 0;
}
//Fin main

//Funcion para agregar un partido al archivo.
void InsertarPartidoFichero()
{
    int puntos1 = 0, puntos2 = 0;
    string equipo1, equipo2, 
    conferencia1, conferencia2, 
    fechaPartido, lugarPartido,
    
    aux;

    ofstream archivoPartidos;
    archivoPartidos.open("Partidos.txt", ios::out|ios::app);

    fflush(stdin);
    system("cls");

    cout << "\n[EQUIPO LOCAL]"  << endl;

    cout<<"\nIngrese el equipo local: ";
    getline(cin, equipo1);

    cout<<"Conferencia: ";
    getline(cin,conferencia1);

    cout<<"Numero de victorias: ";
    cin>> puntos1;

    system("pause");
    system("cls");

    cout << "\n[EQUIPO VISITANTE]"  << endl;

    cout<<"\nIngrese el equipo visitante: ";
    cin >> equipo2;

    cout<<"Conferencia: ";
    cin>>conferencia2;

    cout<<"Numero de victorias: ";
    cin>> puntos2;

    system("pause");
    system("cls");

    cout << "\n[INFORMACION PARTIDO]"<<endl;
    cout << "\nFecha del partido: ";
    cin >> fechaPartido;
    cout << "Lugar del partido: ";
    cin >> lugarPartido;

    archivoPartidos<<"\n\n| "<<equipo1<<"\t\t\t\t\t\t"<<equipo2; 
    archivoPartidos<<"\n| "<<conferencia1<<"\t\t\t [VS] \t\t"<<conferencia2;
    archivoPartidos<<"\n| "<<"Victorias: "<<puntos1<<"\t\t\t\t"<<"Victorias: "<<puntos2;
    archivoPartidos<<"\n|";
    archivoPartidos<<"\n| Fecha: "<<fechaPartido<<"\t\tLugar: "<<lugarPartido;
    archivoPartidos<<"\n-------------------------------------------------------------";
}