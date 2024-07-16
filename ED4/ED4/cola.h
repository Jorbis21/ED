/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramirez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

/**
@file Cola.h

Implementaci�n del TAD Cola utilizando una
lista enlazada de nodos.

Estructura de Datos y Algoritmos
Facultad de Inform�tica
Universidad Complutense de Madrid

(c) Marco Antonio G�mez Mart�n, 2012   Mercedes G�mez Albarr�n, 2016
*/
#ifndef __COLA_LISTA_ENLAZADA_H
#define __COLA_LISTA_ENLAZADA_H
#include <cstddef>

/// Excepciones generadas por algunos m�todos
class EColaVacia {};

//Excepci�n que se levanta si se especifica
//una posici�n inv�lida para la operaci�n
//llevarAlPrincipio. 
class EPosicionInvalida {};

/**
Implementaci�n del TAD Cola utilizando una lista enlazada.

Las operaciones son:

- ColaVacia: -> Cola. Generadora implementada en el
constructor sin par�metros.
- pon: Cola, Elem -> Cola. Generadora
- quita: Cola - -> Cola. Modificadora parcial.
- primero: Cola - -> Elem. Observadora parcial.
- esVacia: Cola -> Bool. Observadora.
- longitud: unsigned int. Devuelve el n�mero de elementos
de la cola.

@author Marco Antonio G�mez Mart�n   Mercedes G�mez Albarr�n
*/
template <class T>
class Cola {
public:



	/** Constructor; operacion ColaVacia */
	Cola() : _prim(NULL), _ult(NULL), _nelems(0) {}

	void pon(const T& elem) {
		Nodo* nuevo = new Nodo(elem);
		Nodo* ant = _ult;
		if (esVacia()) _prim = nuevo;
		else {
			_ult->_sig = nuevo;
		}	
		_ult = nuevo;
		_ult->_ant = ant;
		_nelems++;
	}
	void Avanza() {
		_prim = _prim->_sig;
		if (_ult->_ant == NULL)
			_ult = _prim;
		else
			_ult = _ult->_ant;
		_nelems -= 2;
	}
	int getNelem() {
		return _nelems;
	}
	void quita() {
		if (esVacia())
			throw EColaVacia();
		Nodo* aBorrar = _prim;
		if (_prim == _ult)
			_prim = _ult = NULL;
		else
			_prim = _prim->_sig;
		delete aBorrar;
		_nelems--;
	}
	
	const T& primero() const {
		if (esVacia())
			throw EColaVacia();
		return _prim->_elem;
	}
	const T& ultimo() const {
		if (esVacia())
			throw EColaVacia();
		return _ult->_elem;
	}
	bool esVacia() const {
		return _prim == NULL;
	}
	unsigned int longitud() const {
		return _nelems;
	}
	~Cola() {
		libera();
		_prim = _ult = NULL;
	}
	Cola(const Cola<T>& other) : _prim(NULL), _ult(NULL) {
		copia(other);
	}
	Cola<T>& operator=(const Cola<T>& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	/** Operador de comparaci�n. */
	bool operator==(const Cola<T>& rhs) const {
		Nodo* p1 = _prim;
		Nodo* p2 = rhs._prim;
		while ((p1 != NULL) && (p2 != NULL) && (p1->_elem == p2->_elem)) {
			p1 = p1->_sig;
			p2 = p2->_sig;
		}
		return (p1 == NULL) && (p2 == NULL);
	}

	bool operator!=(const Cola<T>& rhs) const {
		return !(*this == rhs);
	}


private:

	/**
	Clase nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que podr�a ser NULL si
	el nodo es el �ltimo de la lista enlazada.
	*/
	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T& elem) : _elem(elem), _sig(NULL), _ant(NULL){}
		Nodo(const T& elem, Nodo* sig) :
			_elem(elem), _sig(sig) {}
		Nodo(const T& elem, Nodo* sig, Nodo* ant) :
			_elem(elem), _sig(sig), _ant(ant) {}
		T _elem;
		Nodo* _sig;
		Nodo* _ant;
	};


	/**
	Genera una copia de other en la cola receptora
	*/
	void copia(const Cola& other) {
		if (other.esVacia())
			_prim = _ult = NULL;
		else {
			Nodo* puntAOrigen = other._prim;
			Nodo* ultimo;
			_prim = new Nodo(puntAOrigen->_elem);
			ultimo = _prim;
			while (puntAOrigen->_sig != NULL) {
				puntAOrigen = puntAOrigen->_sig;
				ultimo->_sig = new Nodo(puntAOrigen->_elem);
				ultimo = ultimo->_sig;
			}
			_ult = ultimo;
		}
		_nelems = other._nelems;
	}


	/**
	Elimina todos los nodos de la lista enlazada que soporta la cola.
	*/
	void libera() {
		while (_prim != NULL) {
			Nodo* aBorrar = _prim;
			_prim = _prim->_sig;
			delete aBorrar;
		}
	}


	/** Puntero al primer elemento. */
	Nodo* _prim;

	/** Puntero al �ltimo elemento. */
	Nodo* _ult;

	/** N�mero de elementos */
	unsigned int _nelems;
};

#endif // __PILA_LISTA_ENLAZADA_H