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
    cout << "Menu Manejo de Archivos\n";
    cout << "1. Crear Archivo guardar Datos\n";
    cout << "2. Leer Archivo ver Datos\n";
    cout << "3. Buscar un Registro:\n";
    cout << "4. Eliminar Registro:\n";
    cout << "5. Salir\n";
    cout << "Digite una opcion: ";
    cin >> op;
    return op;
}
void llena_alumnos(alumno al, int n)
{
    string archivo;
    ofstream arch;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin, archivo);
    arch.open(archivo.c_str(), ios::out);
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        al.codigo = i;
        cout << "Nombre Alumno No " << i << " ";
        getline(cin, al.nombre);
        cout << "Nota Promedio: ";
        cin >> al.promedio;
        cin.ignore();
        arch << al.codigo << "\t" << al.nombre << "\t" << al.promedio << endl;
    }
    arch.close();
}
void leer_archivo()
{
    string archivo, linea;
    ifstream arch;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin, archivo);
    arch.open(archivo.c_str(), ios::out);
    if (arch.fail())
    {
        cout << "No encuentra el archivo\n";
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
    string archivo, linea, nom, codigo, nombre, nota;
    ifstream arch;
    int opcmenu;
    bool bandera = false;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin, archivo);
    arch.open(archivo.c_str(), ios::out);
    cout << "Ingrese el nombre del alumno a buscar: ";
    cin >> nom;
        if (arch.fail())
        {
            cout << "No encuentra el archivo\n";
            return;
        }
        while (!arch.eof())
        {

            arch >> codigo >> nombre >> nota;
            if (nombre == nom)
            {
                bandera = true;
                cout << codigo << "\t" << nombre << "\t" << nota << endl;
                break;
            }
        }

        if(bandera == false)
        {
            cout<<"Registro no encontrado\n";
            
        }
    
    else
    {
        cout << "\nIngreso de opcion no valido!\n";
    }

}
void eliminar_registro()
{
    string archivo, linea, cod, codigo, nombre, nota;
    ifstream arch;
    ofstream auxiliar;
    bool encontrado = false;
    char *archencontrado;
    cout << "Ingrese el nombre del archivo: ";
    cin.ignore();
    getline(cin, archivo);
    arch.open(archivo.c_str(), ios::out);
    auxiliar.open("auxiliar.txt", ios::out);
    archencontrado = const_cast<char *>(archivo.c_str());
    cout << "Digite el codigo del alumno a eliminar: ";
    cin >> cod;

    if (arch.fail())
    {
        cout << "No encuentra el archivo\n";
        return;
    }
    while (!arch.eof())
    {
        arch >> codigo >> nombre >> nota;
        if (codigo == cod)
        {
            encontrado = true;
            cout << "\n Se elimino el registro ";
            cout << codigo << "\t" << nombre << "\t" << nota << endl;
            codigo = "";
            nombre = "";
            nota = "";
            auxiliar << codigo << "" << nombre << "" << nota;
        }
        else
        {
            auxiliar << codigo << " " << nombre << " " << nota << "\n";
        }
    }
    if (encontrado == false)
    {
        cout << "\n\nNo se encontro al alumno con el codigo: " << cod << "\n\n";
    }
    arch.close();
    auxiliar.close();
    remove(archencontrado);
    rename("auxiliar.txt", archencontrado);
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
            leer_archivo();
            break;
        case 3:
            buscar();
            break;
        case 4:
            eliminar_registro();
            break;
        case 5:
            cout << "Saliendo del sistema ";
            break;
        default:
            cout << "Opción no valida ";
            break;
        }

    } while (opmenu != 5);
}
