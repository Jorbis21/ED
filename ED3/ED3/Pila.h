/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramirez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

#ifndef __PILAVD_H
#define __PILAVD_H
#include <cstddef>

class EPilaVacia {};


template <class T>
class Pila {
public:
	static const int TAM_INICIAL = 10;
	Pila() {
		_v = new T[TAM_INICIAL];
		_tam = TAM_INICIAL;
		_numElems = 0;
	}
	void apila(const T& elem) {
		_v[_numElems] = elem;
		_numElems++;
		if (_numElems == _tam)
			amplia();
	}
	void desapila() {
		if (esVacia())
			throw EPilaVacia();
		--_numElems;
	}
	const T& cima() const {
		if (esVacia())
			throw EPilaVacia();
		return _v[_numElems - 1];
	}
	bool esVacia() const {
		return _numElems == 0;
	}
	~Pila() {
		libera();
	}
	Pila(const Pila<T>& other) {
		copia(other);
	}
	Pila<T>& operator=(const Pila<T>& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}
	bool operator==(const Pila<T>& rhs) const {
		bool iguales = true;
		if (_numElems != rhs._numElems)
			iguales = false;
		else {
			unsigned int i = 0;
			while (iguales && i < _numElems) {
				if (_v[i] != rhs._v[i])
					iguales = false;
				i++;
			}
		}
		return iguales;
	}
	bool operator!=(const Pila<T>& rhs) const {
		return !(*this == rhs);
	}
private:
	T* _v;
	unsigned int _tam;
	unsigned int _numElems;
	void libera() {
		delete[]_v;
		_v = NULL;
	}
	void copia(const Pila<T>& other) {
		_tam = other._numElems + TAM_INICIAL;
		_numElems = other._numElems;
		_v = new T[_tam];
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}
	void amplia() {
		T* viejo = _v;
		_tam *= 2;
		_v = new T[_tam];

		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = viejo[i];

		delete[]viejo;
	}
};

#endif
