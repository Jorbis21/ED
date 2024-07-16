/*
NUMERO DE GRUPO:D01

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES: 
Javier Orbis Ramírez, Pable García Fernández

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
Lista<char> prim_etapa(Lista<char> mensaje) {
	Lista<char> aux;
	Lista<char> aux1;
	bool vocal = es_vocal(mensaje.primero());
	while (!mensaje.esVacia()) {
		while (!vocal) {
			aux1.pon_final(mensaje.primero());
			mensaje.quita_ppio();
			if (mensaje.esVacia()) vocal = true;
			else vocal = es_vocal(mensaje.primero());
		}
		while (!aux1.esVacia()) {
			aux.pon_final(aux1.ultimo());
			aux1.quita_final();
		}
		if (!mensaje.esVacia()) {
			aux.pon_final(mensaje.primero());
			mensaje.quita_ppio();
		}
		vocal = false;
	}
	return aux;
}
/*Lista<char> sec_etapa(Lista<char> mensaje) {
	Lista<char> aux;
	while (!mensaje.esVacia()) {
		aux.pon_final(mensaje.primero());
		mensaje.quita_ppio();
		if (!mensaje.esVacia()) {
			aux.pon_final(mensaje.ultimo());
			mensaje.quita_final();
		}
	}
	return aux;
}*/
void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	// A IMPLEMENTAR
	mensaje = prim_etapa(mensaje);
}

// CODIGO ADICIONAL: NO MODIFICAR
 
  // Imprime la lista por la salida estandar,
  // tanto leída desde el principio hasta el final
  // como leída desde el final hasta el principio.
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
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
