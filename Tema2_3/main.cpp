/*
NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/


#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
// Incluir otros TADs que se consideren necesarios,
// asi como el resto de definiciones auxiliares que
// se considere oportuno.
bool es_vocal(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'
		|| x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
}

void invierteSecuenciasNoVocales(Lista<char>& mensaje) {
	// A IMPLEMENTAR
	Lista<char> inv;
	Lista<char> res;
	while (!mensaje.esVacia()) {
		while (!mensaje.esVacia() && !es_vocal(mensaje.primero())) {
			inv.pon_final(mensaje.primero());
			mensaje.quita_ppio();
		}
		while (!inv.esVacia()) {
			res.pon_final(inv.ultimo());
			inv.quita_final();
		}
		if (!mensaje.esVacia()) {
			res.pon_final(mensaje.primero());
			mensaje.quita_ppio();
		}
	}
	mensaje = res;
}

// CODIGO ADICIONAL: NO MODIFICAR

  // Imprime la lista por la salida estandar,
  // tanto le�da desde el principio hasta el final
  // como le�da desde el final hasta el principio.
void imprime(Lista<char>& l) {
	l.imprime(cout);
	cout << "#";
	l.imprime_invertida(cout);
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for (unsigned int i = 0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		codifica(mensaje);
		imprime(mensaje);
	}
	return 0;
}