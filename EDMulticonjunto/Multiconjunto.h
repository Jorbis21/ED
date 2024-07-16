#include <iostream>
using namespace std;
#ifndef _multiconjunto_
#define _multiconjunto_

template <class T>
class Conjunto{
    public:
        Conjunto();
        ~Conjunto();
        Conjunto(const Conjunto& c);
        Conjunto& operator= (const Conjunto& c);
    private:
        static const int MAX = 50;
        int _tam;
        T _elementos;
};
#endif