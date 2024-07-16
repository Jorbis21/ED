#include "Complejo.h"

int main() {
	Complejo c1(5, 2);
	Complejo c2(-8, 3);
	Complejo c3(4, -2);
	cout << c1.real() << "   " << c1.img() << endl;
	cout << c1 + (c2 - c3) << endl;

	Complejo c4(2, -3);
	cout << c1*c4 << endl;

	Complejo c5(3, 2);
	Complejo c6(1, -2);
	cout << c5/c6 << endl;

	Complejo nc1(0, 0);
	nc1 = c1;

	c2 -= c3;
	c1 += c2;
	cout << c1 << endl;
	nc1 *= c4;
	cout << nc1 << endl;
	c5 /= c6;
	cout << c5 << endl;
	system("pause");
}