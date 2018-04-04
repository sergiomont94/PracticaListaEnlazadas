#pragma once
typedef struct Nodo {

	int valor;

	Nodo *sig;

	Nodo *ant;

}*nodo;

class UtilidadesListaEnlazada

{

public:

	UtilidadesListaEnlazada();

	~UtilidadesListaEnlazada();

	static void insertarFinal(Nodo *&head, int valor);
	static Nodo *& crearLista(int tamaño);
	static void ordenarLista(Nodo *&head);
	static void guardarLista(Nodo *&head, char *);
	static void printList(Nodo *&head);
};