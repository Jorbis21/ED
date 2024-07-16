/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramírez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:Carlos Olano del Pozo no ha participado y no se sabe el motivo

*/


#include <iostream>
#include <string>
#include "lista.h"
#include "pila.h"
using namespace std;
// Incluir otros TADs que se consideren necesarios,
// asi como el resto de definiciones auxiliares que
// se considere oportuno.
void InvierteConsonantes(Pila<char>& pila, Lista<char>::Iterator &I) {
	while (!pila.esVacia()) {
		I.set(pila.cima());
		pila.desapila();
		I.next();
	}
	
}
void invierteSecuenciasNoVocales(Lista<char>& mensaje) {
	Pila<char> pila;//pila usada para invertir las consonantes
	Lista<char>::ConstIterator Ci = mensaje.cbegin();
	Lista<char>::Iterator I = mensaje.begin();
	while (Ci != mensaje.cend()) {
		char L = Ci.elem();
		if (L == 'a' || L == 'e' || L == 'i' || L == 'o' || L == 'u') {
			InvierteConsonantes(pila,I);
			I.set(Ci.elem());
			I.next();
		}
		else {
			pila.apila(Ci.elem());
		}
		Ci.next();
	}
	InvierteConsonantes(pila, I);//Invierte las ultimas consonantes si las hay
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
