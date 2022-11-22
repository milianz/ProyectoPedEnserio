#include <iostream>
#include <fstream>
using namespace std;
//haciendo uso de listas;
struct Nodo{
    string equipo;
    string conferencia;
    int victorias, derrotas;
    struct Nodo *sig;
    struct Nodo *ant;

};

struct Nodo *lista=NULL;
void insertarEquipoFichero();
void insertarEquipoLista(string, string, int, int);
bool verificar(string equipo);

bool verificar(string equipo){
    ifstream leer("RegistroEquipos.txt",ios::in);
    string  Equipo, Conferencia;
    int Victorias, Derrotas;
    leer>>Equipo;
    while(!leer.eof()){
        leer>>Victorias;
        leer>>Derrotas;
        leer>>Conferencia;
         if(Equipo == equipo){
            return false;
            }
        leer>>Equipo;
    }
  leer.close();
  return true;
}

void insertarEquipoFichero()
{
    ofstream DBEquipos;
    string  Equipo, Conferencia;
    int Victorias, Derrotas;

    DBEquipos.open("RegistroEquipos.txt",ios::out|ios::app);//creacion del archivo o abrir el archivo
    
    fflush(stdin);
    system("cls");

    cout<<"Ingrese el nombre del equipo: ";
    getline(cin,Equipo);
    if(verificar(Equipo));
    fflush(stdin);
    cout<<"Ingrese El Numero De Victorias: ";
    cin>>Victorias;
    fflush(stdin);
    cout<<"Ingrese La El Numero de Derrrotas: ";
    cin>>Derrotas;
    fflush(stdin);
    cout<<"Ingrese La conferencia del equipo: ";
    getline(cin,Conferencia);

   

    

    insertarEquipoLista(Equipo,Conferencia,Victorias,Derrotas);

    DBEquipos<<Equipo<<"\t\t"<<Victorias<<"\t\t"<<Derrotas<<"\t\t"<<Conferencia<<endl;
    DBEquipos.close();

}


void insertarEquipoLista(string Equipo,string Conferencia,int Victorias,int Derrotas)
{

    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temp=lista;

    if (nuevoNodo != NULL)
    {
        nuevoNodo->equipo = Equipo;
        nuevoNodo->conferencia = Conferencia;
        nuevoNodo->victorias =Victorias;
        nuevoNodo->derrotas = Derrotas;
        nuevoNodo->sig = NULL;
        nuevoNodo->ant = NULL;

        if (lista == NULL)
        {
            lista = nuevoNodo;
        }
        else
        {
            nuevoNodo->sig = lista;
            lista->ant = nuevoNodo;
            lista = nuevoNodo;
        }
    }
    else
    {
        cout<<"No se puden agregar mas equipos.";
    }
}
