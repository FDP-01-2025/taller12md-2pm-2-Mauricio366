#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    string carnet;
    int edad;
};

// Función para agregar estudiante (CREATE)
void agregarEstudiante() {
    Estudiante e;
    cout << "Nombre (sin espacios): ";
    cin >> e.nombre;
    cout << "Carnet: ";
    cin >> e.carnet;
    cout << "Edad: ";
    cin >> e.edad;

    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
        archivo.close();
        cout << "Estudiante agregado correctamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para mostrar estudiantes (READ)
void mostrarEstudiantes() {
    ifstream archivo("estudiantes.txt");
    Estudiante e;

    if (archivo.is_open()) {
        cout << "\n--- Lista de Estudiantes ---\n";
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            cout << "Nombre: " << e.nombre 
                 << ", Carnet: " << e.carnet
                 << ", Edad: " << e.edad << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// -----------------------------
// 👇 TU TAREA: Completa esta función (UPDATE)
void modificarEstudiante() {
//usando la estructura Estudiante, se crea un nuevo para la nueva informacion
Estudiante nuevo;

cout<<"Nuevo nombre (sin espacios) \n";
cin >> nuevo.nombre;
cout<<"Nuevo carnet \n";
cin >> nuevo.carnet;
cout<<"Nueva edad \n";
cin >> nuevo.edad;
//se llama al archivo original y se crea uno nuevo para la informacion
ifstream archivo("estudiantes.txt");

ofstream archivon("temp.txt", ios::app);


//se comprueba que los archivos esten abiertos

if(archivo.is_open() && archivon.is_open()){
//se muestra la nueva informacion, se cierran los archivos y se cambia la bool a verdadero

    archivon << nuevo.nombre << " " << nuevo.carnet << " " << nuevo.edad << endl;
    archivon.close();
    cout<<"Estudiante actualizado correctamente \n";

    bool modificado = true;
    archivo.close();
//se se muestra que ocurrio algun error, cierra archivos y vuelve bool a false
}else {

    cout << "Error al abrir el archivo.\n";
    bool modificado= false;
    archivon.close();
    archivo.close();
  

}
//dependiendo del valor que el if le de a bool, se actualizara todo o no
if(bool modificado = true){

remove ("estudiantes.txt");
rename ("temp.txt","estudiantes.txt");

}else{

cout<<"ocurrio un error"<<endl;
}


}
// -----------------------------

// Función para eliminar estudiante (DELETE)
void eliminarEstudiante() {
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool eliminado = false;

    cout << "Ingrese carnet a eliminar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            if (e.carnet == buscado) {
                eliminado = true;               // No se copia: se “borra”
            } else {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (eliminado)
            cout << "Estudiante eliminado correctamente.\n";
        else
            cout << "Carnet no encontrado.\n";
    } else {
        cout << "Error abriendo los archivos.\n";
    }
}

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\n=== CRUD de Estudiantes ===\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: modificarEstudiante(); break;  // 👉 Completa aquí
            case 4: eliminarEstudiante(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    return 0;
}