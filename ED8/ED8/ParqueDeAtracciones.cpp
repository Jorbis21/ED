/*
NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

#include "ParqueDeAtracciones.h"

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/

ParqueDeAtracciones::ParqueDeAtracciones() {
	  // A IMPLEMENTAR
	atracciones = Lista<string>();
	ninios = DiccionarioHash<string, Lista<string>>();
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::an_atraccion(const string& nombre_atraccion) {
	  // A IMPLEMENTAR
	for (int i = 0; i < atracciones.longitud(); i++) {
		
	}
	atracciones.pon_final(nombre_atraccion);

}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::an_ninio(const string& nombre_ninio) {
	  // A IMPLEMENTAR
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::poner_en_fila(const string& nombre_ninio, const string& nombre_atraccion) {
	  // A IMPLEMENTAR
}	

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
void ParqueDeAtracciones::avanzar(const string& nombre_atraccion) {
	  // A IMPLEMENTAR
}

/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/
Lista<string> ParqueDeAtracciones::atracciones_visitadas(const string& nombre_ninio) const {
	   // A IMPLEMENTAR
}
  
/*
COMPLEJIDAD: Determina justificadamente la complejidad de la operaci?n.

*/  
int ParqueDeAtracciones::numero_visitas(const string& nombre_ninio, const string& nombre_atraccion) const {
	    // A IMPLEMENTAR
}
   
 