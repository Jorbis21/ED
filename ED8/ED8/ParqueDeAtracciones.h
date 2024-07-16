/*
NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS PARTICIPANTES:

SI ALGUN MIEMBRO DEL GRUPO NO HA PARTICIPADO EN LA PRACTICA,
EXPLICAR EL MOTIVO:

*/

#ifndef _PARQUE_ATRACCIONES_H
#define _PARQUE_ATRACCIONES_H
#include <string>
#include "lista.h"
#include "DiccionarioHash.h"

using namespace std;

class EAtraccionYaExiste {};

class ENinioYaRegistrado {};

class EAtraccionNoExiste {};

class ENinioNoRegistrado {};

class EAccesoAtraccion {};

class EConsultaNumViajes {};


class ParqueDeAtracciones {
public:
   ParqueDeAtracciones();
   void an_atraccion(const string& nombre_atraccion);
   void an_ninio(const string& nombre_ninio);
   void poner_en_fila(const string& nombre_ninio, const string& nombre_atraccion);
   void avanzar(const string& nombre_atraccion);
   Lista<string> atracciones_visitadas(const string& nombre_ninio) const;
   int numero_visitas(const string& nombre_ninio,const string& nombre_atraccion) const;
private:
   // Definir la representación que se estime oportuna, así como declarar los métodos
   // auxiliares que se consideren oportunos (si se estima necesario). 
	Lista<string> atracciones;
	DiccionarioHash<string, Lista<string>> ninios;
};

#endif