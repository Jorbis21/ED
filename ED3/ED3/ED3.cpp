/*
NUMERO DE GRUPO:D43

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:Javier Orbis Ramirez, Carlos Olano del Pozo

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

#include <iostream>
#include <string>
#include "Pila.h"
using namespace std;




bool esEquilibrada(const string& cadena) {
    int lengthC = cadena.length(), p = 0, c = 0, l=0;
    Pila<char> a;
    for (int x = 0; x < lengthC;x++) {
        a.apila(cadena[x]);
    }
    while (!a.esVacia()) {
        char cima = a.cima();
        if (cima == '(')
            p++;
        else if (cima == ')')
            p--;
        if (cima == '{')
            c++;
        else if (cima == '}')
            c--;
        if (cima == '[')
            l++;
        else if (cima == ']')
            l--;
        a.desapila();
    }
    if (p == 0 && c == 0 && l == 0) {
        return true;
    }
    return false;
}


int main() {
    string cadena;
    while (getline(cin, cadena)) {
        if (esEquilibrada(cadena))
            cout << "EQUILIBRADA" << endl;
        else
            cout << "NO_EQUILIBRADA" << endl;
    }
    return 0;
}