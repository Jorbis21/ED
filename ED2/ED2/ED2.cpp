#include "Secuencia.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>
using namespace std;

void haz_consulta(Secuencia<int> sec, int elem) {
	try {
		cout << sec.elem(elem) << endl;
	}
	catch (ElementoInvalido) {
		cout << "ERROR" << endl;
	}
}

void valida_memd(Secuencia<int> s, Secuencia<int>& sp) {
	s = Secuencia<int>();
	for (int i = 0; i < rand() % 10; i++) {
		s.pon(rand());
	}
	sp = sp;
	{
		Secuencia<int> sec = sp;
		sec.pon(rand());
	}
}

void valida_lib() {
	Secuencia<int> sec;
	for (int i = 0; i < 1024; i++) {
		sec.pon(rand());
	}
}

void muestra(Secuencia<int> s) {
	valida_memd(s, s);
	for (int i = 0; i < s.num_elems(); i++) {
		cout << s.elem(i) << " ";
	}
	cout << endl;
}

bool ejecuta_caso(Secuencia<int>& sec) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 1024; i++) valida_lib();
	string comando;
	cin >> comando;
	if (comando == "pon") {
		int elem;
		cin >> elem;
		sec.pon(elem);
		cout << sec.num_elems() << endl;
		return true;
	}
	else if (comando == "consulta") {
		int elem;
		cin >> elem;
		haz_consulta(sec, elem);
		return true;
	}
	else if (comando == "muestra") {
		muestra(sec);
		return true;
	}
	else if (comando == "limpia") {
		sec = Secuencia<int>();
		cout << "OK" << endl;
		return true;
	}
	else if (comando == "termina") {
		return false;
	}
	return false;
}

int main() {
	Secuencia<int> sec;
	while (ejecuta_caso(sec));
	return 0;
}