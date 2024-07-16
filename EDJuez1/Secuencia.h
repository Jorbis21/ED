#ifndef _SECUENCIA_H_
#define _SECUENCIA_H_

/// Excepción de elemento inexistente
class ElementoInvalido {};


template<class T>
class Secuencia {
public:
	Secuencia() {
		// A IMPLEMENTAR
		crear(INI);
	}

	~Secuencia(){
		delete[] _sec;
	}

	Secuencia(const Secuencia& s) {
		crear(s._tam);
		copiar(s);
	}

	Secuencia& operator= (const Secuencia& s) {
		if(this != &s){
			copiar(s);
		}
		return *this;
	}

	void pon(const T& e) {
		// A IMPLEMENTAR
		if(_num_elem == _tam) {
			ampliar(2*_tam);
		}
		_sec[_num_elem] = e;
		_num_elem++;
	}

	const T& elem(int i) {
		// A IMPLEMENTAR
		if (i >= _num_elem) {
			throw ElementoInvalido();
		}
		return _sec[i];
	}

	int num_elems() const {
		// A IMPLEMENTAR
		return _num_elem;
	}

     // DEBEN INCLUIRSE E IMPLEMENTARSE 
	 // LAS OPERACIONES ADICIONALES
	 // NECESARIAS PARA GARANTIZAR EL CORRECTO
	 // FUNCIONAMIENTO DEL TAD


private:
  // INCLUIR DETALLES DE REPRESENTACION Y OPERACIONES AUXILIARES
	void crear(int tam) {
		_sec = new T[tam];
		_num_elem = 0;
		_tam = tam;
	}
	void ampliar(int tam){
		T *viejo = _sec;
		_tam = tam;
		_sec = new T[_tam];
		for (int i = 0; i < _num_elem; i++) {
			_sec[i] = viejo[i];
		}
		delete[] viejo;
	}
	void copiar(const Secuencia& s) {
		if (_tam <  s._tam) {
			ampliar(s._tam);
		}
		for (int i = 0; i < s._num_elem; i++) {
			_sec[i] = s._sec[i];
		}
		_num_elem = s._num_elem;
	}
	static const int INI = 2;
	int _num_elem;
	int _tam;
	T *_sec;
};


#endif


