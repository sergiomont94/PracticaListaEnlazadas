#pragma once

#ifndef EMPLEADO_H
#define EMPLEADO_H

struct empleado {
	int codigo;//4 bytes
	char nombre[30];//30 bytes
	char puesto[15];//15 bytes
	int codigo_jefe;//4 bytes
	bool activo;
};// sizeof = 54 bytes

void registrarEmpleados();
void consultarEmpleados();
empleado *buscarEmpleado(int pos);
void imprimirSubordinados(char* jefe);






#endif // !EMPLEADO_H

