#pragma once

#ifndef EJEMPLOLISTAENLAZADA_H
#define EJEMPLOLISTAENLAZADA_H

struct Nodo
{
	int valor;
	Nodo *sig;
	Nodo *ant;

	Nodo() {
		valor = -1;
		sig = 0;
		ant = 0;
	}

}nodo;



class Lista_Enlazada {

public:
	Lista_Enlazada() {

		primero = 0;
		ultimo = 0;
	}

	Nodo *primero;
	Nodo *ultimo;

	void agregar_final(Nodo *);
	void agregar_nodo(Nodo ** lista, int valor);
	void agregar_inicio(Nodo * nuevo);
	void insertar(Nodo *lista, int valor);
};




#endif // !EJEMPLOLISTAENLAZADA_H
