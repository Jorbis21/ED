/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramírez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:Carlos Olano del Pozo no ha participado y no se sabe el motivo

*/


#include <iostream>
#include <string>
#include "Arbin.h"

using namespace std;

/**
  COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de
			   esta función
			   ***A COMPLETAR***
			   La complejidad de este algoritmo T(n) esta en funcion de la altura del arbol binario y del numero de ramas.
			   T(n) = k si n = 0
			   T(n) corresponde a O(n) por lo tanto lineal
*/
unsigned int alturaArbin(const Arbin<int>& a, int x) {
	if (!a.esVacio()) 
		if (a.hijoIz().esVacio() && !a.hijoDer().esVacio()) {
			x++;
			return alturaArbin(a.hijoDer(), x);
		}	
		else if (a.hijoDer().esVacio() && !a.hijoIz().esVacio()) {
			x++;
			return alturaArbin(a.hijoIz(), x);
		}
		else if (!a.hijoIz().esVacio() && !a.hijoDer().esVacio()) {
			x++;
			if (alturaArbin(a.hijoIz(), x) >= alturaArbin(a.hijoDer(), x)) {
				return alturaArbin(a.hijoIz(), x);
			}
			else {
				return alturaArbin(a.hijoDer(), x);
			}
		}
		else
			return ++x;
	else
		return 0;
}
unsigned int numero_hojas_mas_profundas_que(const Arbin<int>& a, unsigned int k) {
	// A IMPLEMENTAR
		if (k == 0 || k == 1)
			return alturaArbin(a, 0);
		else if (k >= alturaArbin(a, 0))
			return 0;
		else 
			return alturaArbin(a, 0) - k + 1;
}


Arbin<int> lee_arbol(istream& in) {
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
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}



/**
La entrada al programa consiste de líneas formadas por:
(1) Un árbol de enteros
(2) El valor de k
Los árboles se codifican de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con
	v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
	con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estándar
el número de hojas que están a profundidad mayor que k


Ejemplo de entrada:

([2]1([4]3[5])) 0
([2]1([4]3[5])) 1
([2]1([4]3[5])) 2
([2]1([4]3[5])) 3
([2]1([4]3[5])) 4
([2]1([4]3[5])) 100
(([4]3[5])1[2]) 0
(([4]3[5])1[2]) 1
(([4]3[5])1[2]) 2
(([4]3[5])1[2]) 3
(([4]3[5])1[2]) 4
(([4]3[5])1[2]) 100
((([4]3[5])3([4]3[5]))1(([4]3[5])5([4]3[5]))) 0


Salida asociada:

3
3
2
0
0
0

*/


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF) {
		Arbin<int> a = lee_arbol(cin);
		int k;
		cin >> k;
		cout << numero_hojas_mas_profundas_que(a, k) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}