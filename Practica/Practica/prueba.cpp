#include "prueba.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



UtilidadesListaEnlazada::UtilidadesListaEnlazada()

{

}

UtilidadesListaEnlazada::~UtilidadesListaEnlazada()

{

}



void UtilidadesListaEnlazada::insertarFinal(Nodo *& head, int valor)

{

	nodo newNode = new Nodo();
	newNode->sig = 0;
	newNode->ant = 0;
	newNode->valor = valor;
	
	if (head == 0) {
		head = newNode;
		return;
	}
	nodo tmp = head, anterior = 0;

	while (tmp->sig) {
		anterior = tmp;
		tmp = tmp->sig;
	}

	tmp->ant = anterior;
	tmp->sig = newNode;

}



Nodo *& UtilidadesListaEnlazada::crearLista(int tamaño)

{
	nodo head = 0;
	for (int i = 0; i < tamaño; i++)

	{
		UtilidadesListaEnlazada::insertarFinal(head, rand() % tamaño + 1);
	}

	return head;

}

void UtilidadesListaEnlazada::ordenarLista(Nodo *& head)

{
	nodo tmp = head;
	nodo tmpOrdenado = 0;
	vector<int> valores;
	
	while (tmp != 0) {
		valores.push_back(tmp->valor);
		tmp = tmp->sig;
	}



	for (int i = 0; i < valores.size(); i++) {

		for (int j = 0; j < valores.size(); j++) {
			if (valores[i] < valores[j]) {
				int temp = valores[j];
				valores[j] = valores[i];
				valores[i] = temp;
			}
		}
	}

	for (int i = 0; i < valores.size(); i++) {
		UtilidadesListaEnlazada::insertarFinal(tmpOrdenado, valores[i]);
	}

	head = tmpOrdenado;

}



void UtilidadesListaEnlazada::guardarLista(Nodo *& head, char *nombre)

{
	nodo tmp = head;

	ofstream writer(nombre);

	while (tmp != 0) {
		writer << tmp->valor << ' ';
		tmp = tmp->sig;
	}
}

void UtilidadesListaEnlazada::printList(Nodo *& head)

{
	nodo tmp = head;
	while (tmp->sig != 0) {

		if (tmp->ant != 0)
			cout << "Ant: " << tmp->ant->valor;
		else
			cout << "Ant: NULL";
		if (tmp->sig != 0)
			cout << " Sig: " << tmp->sig->valor << endl;
		else
			cout << " Sig: NULL" << endl;
		tmp = tmp->sig;
	}
}