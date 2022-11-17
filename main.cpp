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
//inicilizanso la lista vacia.
struct Nodo *lista=NULL;
//empiezan las funciones.
void insertarEquipoLista(string,string,int,int);
void insertarEquipoFichero();
//void imprimirLista();
int main(){

    insertarEquipoFichero();
    cout<<endl;
    //imprimirLista();
    
    return 0;
}

void insertarEquipoFichero(){

    ofstream DBEquipos;
    string  Equipo, Conferencia;
    int Victorias, Derrotas;
    DBEquipos.open("RegistroEquipos.txt",ios::out|ios::app);//creacion del archivo o abrir el archivo
    
    cout<<"Ingrese el nombre del equipo: ";
    getline(cin,Equipo);
    cout<<"Ingrese La conferencia del equipo: ";
    getline(cin,Conferencia);
    cout<<"Ingrese El Numero De Victorias: ";
    cin>>Victorias;
    cout<<"Ingrese La El Numero de Derrrotas: ";
    cin>>Derrotas;
    insertarEquipoLista(Equipo,Conferencia,Victorias,Derrotas);
    DBEquipos<<Equipo<<"\t\t"<<Victorias<<"\t\t"<<Derrotas<<"\t\t"<<Conferencia<<"."<<endl;
    DBEquipos.close();

}


void insertarEquipoLista(string Equipo,string Conferencia,int Victorias,int Derrotas){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temp=lista;
    if (nuevoNodo != NULL){
        nuevoNodo->equipo = Equipo;
        nuevoNodo->conferencia = Conferencia;
        nuevoNodo->victorias =Victorias;
        nuevoNodo->derrotas = Derrotas;
        nuevoNodo->sig = NULL;
        nuevoNodo->ant = NULL;
        if (lista == NULL){
            lista = nuevoNodo;
        }
        else{
            nuevoNodo->sig = lista;
            lista->ant = nuevoNodo;
            lista = nuevoNodo;
        }
    }
    else{
        cout<<"No se puden agregar mas equipos.";
    }
}