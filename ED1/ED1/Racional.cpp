/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramírez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:Carlos Olano del Pozo no ha podido participar en la práctica por trabajo.

*/

#include "Racional.h"
#include <cmath>

  //Metodos publicos
  //Constructores
  	Racional::Racional(){
	 	_numer = 0;
	  	_denom = 1;
  	}
  	Racional::Racional(long n, long d){
	 	if(d == 0){
		 	throw EDenominadorCero();
	 	}
	 	else{
			_numer = n;
		 	_denom = d;
		 	reduce();
	 	}
  	}
  //Operaciones
  	Racional Racional::suma(Racional f){
	  	long mcm = Racional::mcm(_denom, f._denom);
		_numer = (_numer*(mcm/_denom))+(f._numer*(mcm/f._denom));
		_denom = mcm;
		Racional::reduce();
	  	return *this;
  	}
	Racional Racional::operator-(Racional f){
		long mcm = Racional::mcm(_denom, f._denom);
	  	_numer = (_numer*(mcm/_denom))-(f._numer*(mcm/f._denom));
		_denom = mcm;
		Racional::reduce();
	  	return *this;
	}
	Racional Racional::operator*=(Racional f){
		_numer = _numer*f._numer;
		_denom = _denom*f._denom;
		
		Racional::reduce();
		return *this;
	}
	Racional Racional::divideYActualiza(Racional f){
		_numer = _numer*f._denom;
		_denom = _denom*f._numer;
		if (_denom == 0) {
			throw EDivisionPorCero();
		}
		Racional::reduce();
		return *this;
	}
	bool Racional::operator==(Racional f){
		return ((_numer == f._numer) && (_denom == f._denom));
	}
  // Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
}

 // Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}

