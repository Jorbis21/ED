
#include "ParqueDeAtracciones.h"

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/

ParqueDeAtracciones::ParqueDeAtracciones() {
	  // A IMPLEMENTAR	
	atraccion = DiccionarioHash<string, Cola<string>>();
	ninios = DiccionarioHash<string, listaAtracc>();
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::an_atraccion(const string& nombre_atraccion) {
	  // A IMPLEMENTAR
	if (!atraccion.contiene(nombre_atraccion))
		atraccion.inserta(nombre_atraccion, Cola<string>());
	else throw EAtraccionYaExiste();
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::an_ninio(const string& nombre_ninio) {
	  // A IMPLEMENTAR
	if (!ninios.contiene(nombre_ninio))
		ninios.inserta(nombre_ninio,listaAtracc());
	else throw ENinioYaRegistrado();
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::poner_en_fila(const string& nombre_ninio, const string& nombre_atraccion) {
	  // A IMPLEMENTAR
	if (ninios.contiene(nombre_ninio) && atraccion.contiene(nombre_atraccion) && !ninios.valorPara(nombre_ninio).esperando) {
		Cola<string> aux = atraccion.valorPara(nombre_atraccion);
		aux.pon(nombre_ninio);
		atraccion.inserta(nombre_atraccion, aux);
		listaAtracc aux1 = ninios.valorPara(nombre_ninio);
		aux1.esperando = true;
		//no debe aparecer si es igual a 0
		if (aux1.atracciones.contiene(nombre_atraccion)) {
			aux1.atracciones.inserta(nombre_atraccion, aux1.atracciones.valorPara(nombre_atraccion));
		}
		else aux1.atracciones.inserta(nombre_atraccion, 0);
		ninios.inserta(nombre_ninio, aux1);
	}
	else throw EAccesoAtraccion();
	
}	

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::avanzar(const string& nombre_atraccion) {
	  // A IMPLEMENTAR
	if (atraccion.contiene(nombre_atraccion)) {
		Cola<string> aux = atraccion.valorPara(nombre_atraccion);
		if (!aux.esVacia()){
			string ninio = aux.primero();
			listaAtracc aux1 = ninios.valorPara(ninio);
			int veces = aux1.atracciones.valorPara(nombre_atraccion) + 1;
			aux1.esperando = false;
			aux1.atracciones.inserta(nombre_atraccion, veces);
			ninios.inserta(ninio, aux1);
			aux.quita();
			atraccion.inserta(nombre_atraccion, aux);
		}
	}
	else throw EAtraccionNoExiste();
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
Lista<string> ParqueDeAtracciones::atracciones_visitadas(const string& nombre_ninio) const {
	   // A IMPLEMENTAR
	Lista<string> att = Lista<string>();
	if (ninios.contiene(nombre_ninio)) {
		Diccionario<string, int> aux = ninios.valorPara(nombre_ninio).atracciones;
		Diccionario<string, int>::ConstIterator i = aux.cbegin();
		while (i != aux.cend()) {
			if(i.valor() > 0) att.pon_final(i.clave());
			i.next();
		}
	}
	else throw ENinioNoRegistrado();
	return att;
}
  
/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/  
int ParqueDeAtracciones::numero_visitas(const string& nombre_ninio, const string& nombre_atraccion) const {
	    // A IMPLEMENTAR
	int num = 0;
	if (!ninios.contiene(nombre_ninio) || !atraccion.contiene(nombre_atraccion)) {
		throw EConsultaNumViajes();
	}
	if (ninios.valorPara(nombre_ninio).atracciones.contiene(nombre_atraccion)) {
		num = ninios.valorPara(nombre_ninio).atracciones.valorPara(nombre_atraccion);
	}
	return num;
}
   
 