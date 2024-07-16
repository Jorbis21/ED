#include "CarnetPorPuntos.h"


/**
Implementa aquí los métodos de las clases adicionales
*/
CarnetPorPuntos::CarnetPorPuntos() {
	for (int i = 0; i <= 15; i++) {
		ordenPuntos.inserta(i, Lista<string>());
	}
}
 
/**
Debes completar la implementación de las operaciones de CarnetPorPuntos,
y justificar la complejidad de las mismas.
*/ 

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::nuevo(const string& dni) {
	  // A IMPLEMENTAR
	if (conductores.contiene(dni)) throw EConductorDuplicado();
	else {
		ordenPuntos.busca(15).valor().pon_ppio(dni);
		conductores.inserta(dni, Puntos(ordenPuntos.busca(15).valor().begin()));
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::quitar(const string& dni, unsigned int puntos) {
	  // A IMPLEMENTAR
	if (!conductores.contiene(dni)) throw EConductorNoExiste();
	else {
		int punt = conductores.busca(dni).valor().punt;
		if (punt > 0 && puntos > 0) {
			ordenPuntos.busca(punt).valor().eliminar(conductores.busca(dni).valor().it);
			punt -= puntos;
			if (punt < 0) punt = 0;
			conductores.busca(dni).valor().punt = punt;
			ordenPuntos.busca(punt).valor().pon_ppio(dni);
			conductores.busca(dni).valor().it = ordenPuntos.busca(punt).valor().begin();
		}
		
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void CarnetPorPuntos::recuperar(const string& dni, unsigned int puntos) {
	  // A IMPLEMENTAR
	if (!conductores.contiene(dni)) throw EConductorNoExiste();
	else {
		int punt = conductores.busca(dni).valor().punt;
		if (punt < 15 && puntos > 0) {
			ordenPuntos.busca(punt).valor().eliminar(conductores.busca(dni).valor().it);
			punt += puntos;
			if (punt > 15) punt = 15;
			conductores.busca(dni).valor().punt = punt;
			ordenPuntos.busca(punt).valor().pon_ppio(dni);
			conductores.busca(dni).valor().it = ordenPuntos.busca(punt).valor().begin();
		}
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::consultar(const string& dni) const {
	  // A IMPLEMENTAR
	if (!conductores.contiene(dni)) throw EConductorNoExiste();
	else return  conductores.cbusca(dni).valor().punt;
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
unsigned int CarnetPorPuntos::cuantos_con_puntos(unsigned int puntos) const {
	  // A IMPLEMENTAR
	if (puntos < 0 || puntos > 15) throw EPuntosNoValidos();
	else return ordenPuntos.cbusca(puntos).valor().longitud();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
const Lista<string>& CarnetPorPuntos::lista_por_puntos(unsigned int puntos) const {
	// A IMPLEMENTAR
	if (puntos < 0 || puntos > 15) throw EPuntosNoValidos();
	else ordenPuntos.cbusca(puntos).valor();
}

