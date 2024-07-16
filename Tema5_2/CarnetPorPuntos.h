#ifndef _CARNET_POR_PUNTOS_H
#define _CARNET_POR_PUNTOS_H

#include "DiccionarioHash.h"
#include "lista.h"
#include <string>
using namespace std;

class EConductorDuplicado {};
class EConductorNoExiste {};
class EPuntosNoValidos {};

class CarnetPorPuntos {
public:
   CarnetPorPuntos();
   void nuevo(const string& dni);
   void quitar(const string& dni, unsigned int puntos);
   void recuperar(const string& dni, unsigned int puntos);
   unsigned int consultar(const string& dni) const;
   unsigned int cuantos_con_puntos(unsigned int puntos) const;
   const Lista<string>& lista_por_puntos(unsigned int puntos) const;
private:
   // A COMPLETAR
	class Puntos {
	public:
		unsigned int punt;
		Lista<string>::Iterator it;
		Puntos(Lista<string>::Iterator it1) : it(it1), punt(15) {}
	};
	DiccionarioHash<string, Puntos> conductores;
	DiccionarioHash<int, Lista<string>> ordenPuntos;
};

#endif