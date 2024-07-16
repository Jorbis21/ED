#include "Complejo.h"

Complejo::Complejo(float real, float img) {
	_real = real;
	_img = img;
}

Complejo Complejo::operator +(const Complejo& c) const {
	return Complejo(_real + c._real, _img + c._img);
}

Complejo Complejo::operator -(const Complejo& c) const {
	return Complejo(_real - c._real, _img - c._img);
}

Complejo Complejo::operator *(const Complejo& c) const {
	return Complejo(_real*c._real - _img*c._img, _real*c._img + _img*c._real);
}

Complejo Complejo::operator /(const Complejo& c) const {
	if ((c._real == 0) && (c._img == 0)) throw EDivisionPorCero();
	else {
		float factor_escala = c._real*c._real + c._img*c._img;
		return Complejo((_real*c._real + _img*c._img) / factor_escala,
			(_img*c._real - _real*c._img) / factor_escala);
	}
}

Complejo& Complejo::operator= (const Complejo& c) {
	_real = c._real;
	_img = c._img;
	return *this;
}


Complejo& Complejo::operator +=(const Complejo& c) {
	Complejo suma = *this + c;
	_real = suma._real;
	_img = suma._img;
	return *this;
}

Complejo& Complejo::operator -=(const Complejo& c)  {
	Complejo resta = *this - c;
	_real = resta._real;
	_img = resta._img;
	return *this;
}

Complejo& Complejo::operator *=(const Complejo& c)  {
	Complejo producto = *this * c;
	_real = producto._real;
	_img = producto._img;
	return *this;
}

Complejo& Complejo::operator /=(const Complejo& c) {
	Complejo division = *this / c;
	_real = division._real;
	_img = division._img;
	return *this;
}

float Complejo::real() const { return _real; }
float Complejo::img() const { return _img; }

bool Complejo::operator==(const Complejo& c) {
	return (_real == c._real) && (_img == c._img);
}

ostream& operator<<(ostream& out, const Complejo& c) {
	out << c._real << "+" << c._img << "i";
	return out;
}

