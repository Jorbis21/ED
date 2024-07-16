/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramírez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:Carlos Olano del Pozo no ha participado y no se sabe el motivo

*/


#include <iostream>
#include <fstream>
#include <string>
#include "Arbin.h"

using namespace std;

int tramo(const Arbin<int>& cuenca, int& cau) {
	int tramos = 0, cauIz = 0, cauDer = 0;
	if (cuenca.esVacio()) 
		return 0;
	else if (cuenca.hijoDer().esVacio() && cuenca.hijoIz().esVacio())
		cau++;
	else {
		tramos += tramo(cuenca.hijoIz(), cauIz);
		tramos += tramo(cuenca.hijoDer(), cauDer);
		cau = cauIz + cauDer + cuenca.raiz();
		if (cau < 0) {
			cau = 0;
		}
		else if (cau >= 3) {
			tramos++;
		}
	}
	return tramos;
}

int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int cau = 0, tramos = tramo(cuenca, cau);
	if (cau >= 3) {
		tramos--;
	}
	return tramos;
}

Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF) {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}