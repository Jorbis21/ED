#include <iostream>
using namespace std;
#include "cola.h"


bool palindroma(const Cola<char>& cola) {
	Cola<char> aux = cola;
	while (aux.getNelem() > 0){
		if (aux.primero() != aux.ultimo()) {
			return false;
		}
		else {
			aux.Avanza();
		}
	}
	return true;
}



// Codigo de lectura y ejecuci�n de caso: no modificar

bool lee_caso(Cola<char>& cola) {
	char ch;
	cin.get(ch);
	if (ch == '*') {
		return false;
	}
	else {
		while (ch != '\n') {
			if (ch != ' ')
				cola.pon(ch);
			cin.get(ch);
		}
		return true;
	}
}

int main() {
	Cola<char> cola;

	while (lee_caso(cola)) {
		bool es_palindroma = palindroma(cola);
		while (!cola.esVacia()) {
			cout << cola.primero();
			cola.quita();
		}
		cout << " = ";
		if (es_palindroma)
			cout << "SI\n";
		else
			cout << "NO\n";
	}
	return 0;
}
