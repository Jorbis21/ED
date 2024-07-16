/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramírez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

using namespace std;

#ifndef _SECUENCIA_H_
#define _SECUENCIA_H_

/// Excepción de elemento inexistente
class ElementoInvalido {};


template<class T>
class Secuencia {
public:
	Secuencia() {
		// A IMPLEMENTAR
		size = 2;
		vector = new T[size];
		firstEmpty = 0;
	}


	void pon(const T& e) {
		if (firstEmpty == size) {
			resize();
		}
		vector[firstEmpty] = e;
		firstEmpty++;
	}

	const T& elem(int i) {
		if (i < size && i >= 0) {
			if (i < firstEmpty) {
				return vector[i];
			}
			else {
				throw ElementoInvalido();
			}
		}
	}

	int num_elems() const {
		return firstEmpty;
	}

	// DEBEN INCLUIRSE E IMPLEMENTARSE 
	// LAS OPERACIONES ADICIONALES
	// NECESARIAS PARA GARANTIZAR EL CORRECTO
	// FUNCIONAMIENTO DEL TAD
	~Secuencia() {
		delete[] vector;
	}
	Secuencia& operator=(const Secuencia& v) {
		size = v.size;
		firstEmpty = v.firstEmpty;
		for (int i = 0; i < size; i++) {
			vector[i] = v.vector[i];
		}
		return *this;
	}
	Secuencia(const Secuencia& v) {
		size = v.size;
		firstEmpty = v.firstEmpty;
		vector = new T[size];
		for (int i = 0; i < size;i++) {
			vector[i] = v.vector[i];
		}
	}


private:
	// INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	T* vector;
	int size, firstEmpty;
	void resize() {
		T* aux = new T[size * 2];
		for (int i = 0; i < size; i++) {
			aux[i] = vector[i];
		}
		delete[] vector;
		vector = aux;
		size = size * 2;
	}
};


#endif