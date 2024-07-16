#include "GestionAdmisiones.h"

/** 
Implementación de las operaciones de la clase Paciente 
*/

Paciente::Paciente(const string& nombre, unsigned int edad, const string& sintomas, const int grav, const Lista<CodigoPaciente>::Iterator& it1):
    _nombre(nombre),  _sintomas(sintomas), _edad(edad), _grav(grav), it(it1) {}

unsigned int Paciente::edad() const {
   return _edad;	
}
const string& Paciente::nombre() const {
   return _nombre;	
}
const string& Paciente::sintomas() const {
   return _sintomas;	
}
const int& Paciente::gravedad() const {
	return _grav;
}

/**
Implementa aquí los métodos de las clases adicionales
*/
int nivel_Gravedad(Gravedad x) {
	switch (x) {
	case LEVE:
		return 0;
	break;
	case NORMAL:
		return 1;
		break;
	case GRAVE:
		return 2;
		break;
	}
}
 
/**
Debes completar la implementación de las operaciones de GestionAdmisiones,
y justificar la complejidad de los mismos.
*/ 


/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
GestionAdmisiones::GestionAdmisiones() {
	// A IMPLEMENTAR
	dic = DiccionarioHash<CodigoPaciente, Paciente>();
	llegada = DiccionarioHash<int, Lista<CodigoPaciente>>();
	llegada.inserta(0, Lista<CodigoPaciente>());//leve
	llegada.inserta(1, Lista<CodigoPaciente>());//normal
	llegada.inserta(2, Lista<CodigoPaciente>());//grave
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas, Gravedad gravedad) {
	// A IMPLEMENATR
	if (dic.contiene(codigo)) throw EPacienteDuplicado();
	else {
		llegada.busca(gravedad).valor().pon_ppio(codigo);
		int x = nivel_Gravedad(gravedad);
		dic.inserta(codigo, Paciente(nombre, edad, sintomas, x, llegada.busca(x).valor().begin()));
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	// A IMPLEMENATR
	if (!dic.contiene(codigo)) throw EPacienteNoExiste();
	else {
		DiccionarioHash<CodigoPaciente, Paciente>::ConstIterator i = dic.cbusca(codigo);
		nombre = i.valor().nombre();
		edad = i.valor().edad();
		sintomas = i.valor().sintomas();
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo, Gravedad& gravedad) const {
	// A IMPLEMENATR
	if (dic.esVacio()) throw  ENoHayPacientes();
	else {
		if (!llegada.cbusca(2).valor().esVacia()) {
			codigo = llegada.cbusca(2).valor().ultimo();
			gravedad = GRAVE;
		}
		else if (!llegada.cbusca(1).valor().esVacia()) {
			codigo = llegada.cbusca(1).valor().ultimo();
			gravedad = NORMAL;
		}
		else if (!llegada.cbusca(0).valor().esVacia()) {
			codigo = llegada.cbusca(0).valor().ultimo();
			gravedad = LEVE;
		}
		
	}
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
bool GestionAdmisiones::hay_pacientes() const {  
  // A IMPLEMENATR
	return !dic.esVacio();
}

/**
 COMPLEJIDAD: Determina y justifica aquí la complejidad de la operación
*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
  // A IMPLEMENATR
	if (dic.contiene(codigo)) {
		DiccionarioHash<CodigoPaciente, Paciente>::Iterator it = dic.busca(codigo);
		if (it != dic.end()) {
			if (it.valor().it != llegada.busca(it.valor().gravedad()).valor().end()) {
				llegada.busca(it.valor().gravedad()).valor().eliminar(it.valor().it);
			}
		}
		dic.borra(codigo);
	}
}
   
