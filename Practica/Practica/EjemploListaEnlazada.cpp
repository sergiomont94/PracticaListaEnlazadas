#include "EjemploListaEnlazada.h"


void Lista_Enlazada::agregar_final(Nodo * nuevo) {
	if (primero == 0)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		ultimo->sig = nuevo;
		nuevo->ant = ultimo;
		ultimo = nuevo;
	}
}

void Lista_Enlazada::agregar_nodo(Nodo **lista, int valor) {
	Nodo * nuevo = new Nodo;
	nuevo->valor = valor;

	if (*lista == 0)
	{
		*lista = nuevo;
	}
	else
	{
		Nodo *actual = *lista;
		Nodo *anterior = 0;
	}

	while (actual != 0)
	{
		anterior = actual;
		actual = actual->sig;
	}

	anterior->sig = nuevo;
	nuevo->ant = anterior;


}

void Lista_Enlazada::agregar_inicio(Nodo *nuevo) {
	if (primero ==0)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		nuevo->sig = primero;
		primero->ant = nuevo;
		primero = nuevo;
	}
}

void Lista_Enlazada::insertar(Nodo *nuevo, int valor) {
	if (primero == 0)
	{
		primero = nuevo;
		ultimo = nuevo;
	}

	int posicion_actual = 0;

	Nodo *actual = primero;
	Nodo *anterior = 0;

	while (actual != 0)
	{
		posicion_actual++;
		anterior = actual;
		actual = actual->sig;
	}

	if (posicion_actual == posicion )
	{
		break;
	}

	if (anterior == primero && anterior == ultimo)
	{
		nuevo->sig = primero;
		primero->ant = nuevo;
		primero = nuevo;
		ultimo = primero->sig;
	}
	else if (anterior==primero)
	{
		nuevo->sig = primero;
		primero->ant = nuevo;
		primero = nuevo;
	}
	else if (anterior == ultimo)
	{
		nuevo->sig = ultimo;
		ultimo->ant = nuevo;
		anterior->ant->sig = nuevo;
		nuevo->ant = anterior->ant;
	}
	else
	{
		nuevo->sig = anterior;
		anterior->ant->sig = nuevo;
		nuevo->ant = anterior->ant;
		anterior->ant = nuevo;
	}
}