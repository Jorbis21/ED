#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

void num_a_salvo_aux(const Arbin<char>& a, int num_mon, int &num_cab, int &sol) {
	if (!a.esVacio()) {
		if(a.hijoDer().esVacio() && a.hijoIz().esVacio()){ 
			if (a.raiz() == 'C') num_cab++;
			else if (a.raiz() == 'D') 
				if (num_cab >= num_mon) sol += 1;
			else num_mon += 1;
		}
		else {
			int num_cab_der = 0, num_cab_iz = 0;
			if (a.raiz() == 'M') {
				num_a_salvo_aux(a.hijoDer(), num_mon+1, num_cab_der, sol);
				num_a_salvo_aux(a.hijoIz(), num_mon+1, num_cab_iz, sol);
				num_cab += num_cab_der + num_cab_iz;
			}
			else if (a.raiz() == 'C') {
				num_a_salvo_aux(a.hijoDer(), num_mon, num_cab_der, sol);
				num_a_salvo_aux(a.hijoIz(), num_mon, num_cab_iz, sol);
				num_cab += num_cab_der + num_cab_iz;
			}
			else {
				num_a_salvo_aux(a.hijoDer(), num_mon, num_cab_der, sol);
				num_a_salvo_aux(a.hijoIz(), num_mon, num_cab_iz, sol);
				num_cab += num_cab_der + num_cab_iz;
				if (num_cab >= num_mon) sol += 1;
			}
			
		}
	}
}
/**
  FUNCION A IMPLEMENTAR.
  Aparte de esta función, puedes implementar todas las funciones auxiliares que
  consideres oportuno. 
  Debes describir y justificar aquí la complejidad de la implementación realizada:
  
  

*/
int num_a_salvo(const Arbin<char>& a) {
	/*** A IMPLEMENTAR ***/
	int sol = 0, num_cab = 0;
	num_a_salvo_aux(a, 0, num_cab, sol);
	return sol;
}



Arbin<char> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = lee_arbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = lee_arbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}


void escribe_arbol(Arbin<char> a) {
	if (a.esVacio()) cout << "#";
	else if (a.hijoIz().esVacio() && a.hijoDer().esVacio()) cout << "[" << a.raiz() << "]";
	else {
		cout << "("; 
		escribe_arbol(a.hijoIz()); 
		cout << a.raiz(); 
		escribe_arbol(a.hijoDer());
		cout << ")";
	}
}


int main() {
	Arbin<char> arbol;
	while (cin.peek() != EOF)  {
		Arbin<char> mapa = lee_arbol(cin);
		cout << "num_a_salvo ";
		escribe_arbol(mapa);
		cout << " => ";
		cout << num_a_salvo(mapa);
		string resto_linea;
		getline(cin, resto_linea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}
