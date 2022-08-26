#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
struct alumno
{
    int codigo;
    string nombre;
    float promedio;
};
int menu()
{
    int op;
    cout << "Menu Manejo de documentos\n";
    cout << "1. Crear documento guardar Datos\n";
    cout << "2. Leer documento ver Datos\n";
    cout << "3. Buscar un Registro:\n";
    cout << "4. Eliminar Registro:\n";
    cout << "5. Salir\n";
    cout << "Digite una opcion: ";
    cin >> op;
    return op;
}
void llena_alumnos(alumno al, int n)
{
    string documento;
    ofstream arch;
    cout << "Ingrese el nombre del documento: ";
    cin.ignore();
    getline(cin, documento);
    arch.open(documento.c_str(), ios::out);
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        al.codigo = i;
        cout << "Nombre Alumno Numero " << i << " ";
        getline(cin, al.nombre);
        cout << "Nota Promedio: ";
        cin >> al.promedio;
        cin.ignore();
        arch << al.codigo << "\t" << al.nombre << "\t" << al.promedio << endl;
    }
    arch.close();
}
void leer_documento()
{
    string documento, linea;
    ifstream arch;
    cout << "Ingrese el nombre del documento: ";
    cin.ignore();
    getline(cin, documento);
    arch.open(documento.c_str(), ios::out);
    if (arch.fail())
    {
        cout << "No encuentra el documento\n";
        return;
    }
    while (!arch.eof())
    {
        getline(arch, linea);
        cout << linea << endl;
    }
    arch.close();
}

void buscar()
{
    string documento, linea, cod;
    ifstream arch;
    cout << "Ingrese el nombre del documento: ";
    cin.ignore();
    getline(cin, documento);
    arch.open(documento.c_str(), ios::out);
    cout << "Digite el codigo del alumno a buscar: ";
    cin >> cod;

    if (arch.fail())
    {
        cout << "No encuentra el documento\n";
        return;
    }
    while (!arch.eof())
    {
        getline(arch, linea);
        if (linea.substr(0, 1) == cod)
        {
            cout << linea << endl;
        }
        else
        {
            cout << "El registro no hallado\n";
        }
    }
}

void eliminar()
{
    string documento, linea, cod;
    ifstream arch;
    ofstream aux;
    aux.open ("auxiliar.txt", ios::out);
    cout << "Ingrese el nombre del documento: ";
    cin.ignore();
    getline(cin, documento);
    arch.open(documento.c_str(), ios::out);
    cout << "Digite el codigo del alumno a buscar: ";
    cin >> cod;
    if (arch.fail())
    {
        cout << "No encuentra el documento\n";
        return;
    }
    while (!arch.eof())
    {
        getline(arch, linea);
        if (linea.substr(0, 1) == cod)
        {
            cout << "\nEl documento se elimino" << endl;
            getch();
        }
        else
        { 
            aux << linea << endl;
        }
    }
    remove("documento");
    rename ( "auxiliar.txt", "documento.txt" );


}
main()
{
    system ("cls \n");
    int na, opmenu;
    alumno al;
    do
    {
        opmenu = menu();
        switch (opmenu)
        {
        case 1:
            cout << "Cuantos alumnos tiene el curso: ";
            cin >> na;
            llena_alumnos(al, na);
            break;
        case 2:
            leer_documento();
            break;
        case 3:
            buscar();
            break;
        case 4:
            eliminar();
            break;
        default:
            cout << "Opción no valida ";
            break;
        }

    } while (opmenu != 5);
}