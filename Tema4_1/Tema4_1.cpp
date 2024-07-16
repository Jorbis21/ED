#include "lista.h"
#include "diccionario.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
public:
	string alumno;
	int nota;
	Puntuacion(const string& nombre, int puntuacion) : alumno(nombre), nota(puntuacion) {}
};

// Construye una lista con las puntuaciones de aquellos alumnos cuya
// calificación final es distinta de 0. Dicha lista está ordenada
// alfabéticamente por nombre de alumno
// Parámetros:
//    bien: Lista de alumnos que han resuelto correctamente un ejercicio (si
//          un alumno ha resuelto correctamente varios ejercicios, aparecerá
//          varias veces en la lista)
//    mal: Lista de alumnos que han resuelto incorrectamente un ejercicio (si
//          un alumno ha resuelto correctamente varios ejercicios, aparecerá
//          varias veces en la lista)
//    listado: Listado de calificaciones, ordenado alfabéticamente por nombre
//          de alumno. Solo aparecen aquellos alumnos cuya calificación final 
//          es distinta de 0.
Diccionario<string, int> carga_diccionario(const Lista<string>& a, const Lista<string>& b) {
	Diccionario<string, int> sol;
	if (!a.esVacia()) {
		Lista<string>::ConstIterator Ia = a.cbegin();
		while (Ia != a.cend()) {
			if (sol.contiene(Ia.elem())) {
				int val = sol.valorPara(Ia.elem());
				sol.borra(Ia.elem());
				sol.inserta(Ia.elem(), val + 1);
			}
			else sol.inserta(Ia.elem(), 1);
			Ia.next();
		}
	}
	if (!b.esVacia()) {
		Lista<string>::ConstIterator Ib = b.cbegin();
		while (Ib != a.cend()) {
			if (sol.contiene(Ib.elem())) {
				int val = sol.valorPara(Ib.elem());
				sol.borra(Ib.elem());
				sol.inserta(Ib.elem(), val - 1);
			}
			else sol.inserta(Ib.elem(), -1);
			Ib.next();
		}
	}
	return sol;
}

void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	// A IMPLEMENTAR
	Diccionario<string, int> Dic = carga_diccionario(bien, mal);
	Diccionario<string, int>::ConstIterator IDic = Dic.cbegin();
	while (IDic != Dic.cend()) {
		if (IDic.valor() != 0) {
			listado.pon_final(Puntuacion(IDic.clave(), IDic.valor()));
		}
		IDic.next();
	}
}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
	Lista<Puntuacion>::ConstIterator i = listado.cbegin();
	Lista<Puntuacion>::ConstIterator e = listado.cend();
	while (i != e) {
		cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
		i.next();
	}
	cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
	string comienzo;
	while (cin >> comienzo) {
		Lista<string> bien;
		Lista<string> mal;
		Lista<Puntuacion> listado;
		leeResultados(bien, mal);
		califica(bien, mal, listado);
		imprimePuntuaciones(listado);
	}
	return 0;
}