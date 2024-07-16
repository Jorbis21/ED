#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


typedef struct {
	int x;
	double val;
} tEntrada;

typedef Lista<tEntrada> tVector;

Diccionario<int, double> carga_diccionario(const tVector& x) {
	Diccionario<int, double> Dic;
	tVector::ConstIterator I = x.cbegin();
	while (I != x.cend()) {
		Dic.inserta(I.elem().x, I.elem().val);
		I.next();
	}
	return Dic;
}
double producto_escalar(const tVector& u, const tVector& v) {
	// A IMPLEMENTAR
	double sol = 0;
	if (!u.esVacia() && !v.esVacia()) {
		Diccionario<int, double> Dic_u = carga_diccionario(u), Dic_v = carga_diccionario(v);
		Diccionario<int, double>::ConstIterator IDic_u = Dic_u.cbegin();
		while (IDic_u != Dic_u.cend()) {
			if (Dic_v.contiene(IDic_u.clave())) {
				double x = IDic_u.valor() * Dic_v.valorPara(IDic_u.clave());
				sol += x;
			}
			IDic_u.next();
		}
	}
	
	return sol;
}

bool leeVector(tVector& v) {
	if (cin.peek() == '(') {
		char sep;
		cin >> sep;
		while (cin.peek() != ')') {
			tEntrada e;
			unsigned int i;
			double val;
			cin >> e.x >> sep >> e.val;
			if (cin.peek() != ')') {
				cin >> sep;
			}
			v.pon_final(e);
		}
		cin >> sep;
		return true;
	}
	else return false;
}
void saltaLinea() {
	string s;
	getline(cin, s);
}

int main() {
	bool fin = false;
	while (!fin) {
		tVector u;
		tVector v;
		if (leeVector(u)) {
			leeVector(v);
			saltaLinea();
			cout << producto_escalar(u, v) << endl;
		}
		else {
			fin = true;
		}
	}
}