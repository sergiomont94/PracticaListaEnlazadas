#include "EjemploArchivoBinario.h"
#include <fstream>
#include <iostream>
// ifstream leer,seekg
//ofstream escribir,seekp


using namespace std;

void registrarEmpleados() {
	ofstream archivoOut("empleados.dat", ios::out | ios::binary | ios::app);

	if (!archivoOut)
	{
		cout << "Error al intentar abrir archivo empleados.dat ";
		return;
	}

	archivoOut.seekp(0, ios::end);//ubicarse al final del archivo

	cout << "\n\n = = = Registro de Empleados = = =\n\n";

	int opc = 0;

	do
	{
		empleado nuevo;
		cout << "Ingrese codigo: " << endl;
		cin >> nuevo.codigo;

		cout << "Ingrese nombre: " << endl;
		cin >> nuevo.nombre;

		cout << "Ingrese puesto: " << endl;
		cin >> nuevo.puesto;

		cout << "Ingrese codigo Jefe (-1 si no tiene): " << endl;
		cin >> nuevo.codigo_jefe;

		nuevo.activo = true; // o podemos poner 1

		archivoOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(empleado));

		cout << "Registro guardado!\n\n";

		cout << "Desea agregar nuevo registro? (-1 para salir): ";
		cin >> opc;

	} while (opc != -1);
	archivoOut.close();

}

void consultarEmpleados() {
	ifstream archivoIn("empleados.dat", ios::in | ios::binary);

	if (!archivoIn)
	{
		cout << "Error al intentar abrir el arhicvo empleados.dat";
		return;
	}

	archivoIn.seekg(0, ios::beg);

	cout << "\n\n = = = Consulta De Empleados = = =\n\n";

	empleado actual;

	//leemos el primer registro
	archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(empleado));

	while (!archivoIn.eof())
	{
		if (actual.activo)
		{
			cout << "Codigo: " << actual.codigo << "\nNombre: " << actual.nombre << "\nPuesto: " << actual.puesto << "\nJefe: " << actual.codigo_jefe << endl;
			cout << "----------------------------------------------" << endl;
		}

		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(empleado));
	}

	archivoIn.close();
}

empleado *buscarEmpleado(int pos) {
	ifstream archivoBus("empleados.dat", ios::in, ios::binary);

	if (!archivoBus)
	{
		cout << "Error al intentar abrir archivo empleados.dat";
		return NULL;
	}

	empleado nuevo;

	archivoBus.seekg(0, ios::end);
	int byte_totales = archivoBus.tellg();
	int cant = byte_totales / sizeof(empleado);

	archivoBus.seekg((pos - 1) * sizeof(empleado), ios::beg);

	archivoBus.read(reinterpret_cast<char*>(&nuevo), sizeof(empleado));

	empleado *nuevo_reg = new empleado;
	nuevo_reg->codigo = nuevo.codigo;
	strcpy_s(nuevo_reg->nombre, nuevo.nombre);
	strcpy_s(nuevo_reg->puesto, nuevo.puesto);
	nuevo_reg->codigo_jefe = nuevo.codigo_jefe;

	return nuevo_reg;



	//cout << "Codigo: " << nuevo.codigo << "\nNombre: " << nuevo.nombre << "\nPuesto: " << nuevo.puesto << "\nJefe: " << nuevo.codigo_jefe << endl;
}




/////////////////// MAIN



#include <iostream>
#include <conio.h>
#include "EjemploArchivoBinario.h"
using namespace std;

int main() {

	//registrarEmpleados();
	//consultarEmpleados();
	buscarEmpleado(2);

	cout << "Codigo: " << buscarEmpleado(2)->codigo << "\nNombre: " << buscarEmpleado(2)->nombre << "\nPuesto: " << buscarEmpleado(2)->puesto << "\nJefe: " << buscarEmpleado(2)->codigo_jefe << endl;

	_getch();
}