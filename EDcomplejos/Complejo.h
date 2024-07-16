#include <iostream>

using namespace std;

#ifndef _COMPLEJO_H_
#define _COMPLEJO_H

class EDivisionPorCero {};

class Complejo {
   public:
	   Complejo(float real, float img);
	   Complejo operator +(const Complejo& c) const;
	   Complejo operator -(const Complejo& c) const;
	   Complejo operator *(const Complejo& c) const;
	   Complejo operator /(const Complejo& c) const;
	   Complejo& operator=(const Complejo& c);
	   Complejo& operator+=(const Complejo& c);
	   Complejo& operator-=(const Complejo& c);
	   Complejo& operator*=(const Complejo& c);
	   Complejo& operator/=(const Complejo& c);
	   float real() const;
	   float img() const;
	   bool operator==(const Complejo& c);
	   friend ostream& operator<<(ostream& out, const Complejo& c);
   private: 
	   float _real;
	   float _img;
};

#endif
