#include "GestionAdmisiones.h"

/**
 COMPLEJIDAD: O(1)
 Constante
*/
GestionAdmisiones::GestionAdmisiones() {
	dic = DiccionarioHash<CodigoPaciente, Paciente>();
	llegada = Lista<CodigoPaciente>();
}

/**
 COMPLEJIDAD: O(log n)
 Esta función contiene los métodos de diccionario contiene() e inserta() que son de coste logarítmico
*/
void GestionAdmisiones::an_paciente(CodigoPaciente codigo, const string& nombre, unsigned int edad, const string& sintomas) {
	if (dic.contiene(codigo)) throw EPacienteDuplicado();
	else {
		llegada.pon_ppio(codigo);
		Paciente i(llegada.begin());
		i.edad = edad;
		i.nombre = nombre;
		i.sintomas = sintomas;
		dic.inserta(codigo, i);
	}
}

/**
 C COMPLEJIDAD: O(log n)
 Esta función contiene los métodos de diccionario contiene() e valorPara() que son de coste logarítmico
*/
void GestionAdmisiones::info_paciente(CodigoPaciente codigo, string& nombre, unsigned int& edad, string& sintomas) const {
	if (!dic.contiene(codigo)) throw EPacienteNoExiste();
	else {
		DiccionarioHash<CodigoPaciente, Paciente>::ConstIterator i = dic.cbusca(codigo);
		nombre = i.valor().nombre;
		edad = i.valor().edad;
		sintomas = i.valor().sintomas;
	}
}

/**
 COMPLEJIDAD: O(1)
 Constante
*/
void GestionAdmisiones::siguiente(CodigoPaciente& codigo) const {
	if (dic.esVacio()) throw  ENoHayPacientes();
	else codigo = llegada.ultimo();
}

/**
 COMPLEJIDAD: O(1)
 Constante
*/
bool GestionAdmisiones::hay_pacientes() const {  
	return !dic.esVacio();
}

/**
	COMPLEJIDAD: O(n log n)
	Realiza una busqueda lineal y binaria a la hora de borrar
	*/
void GestionAdmisiones::elimina(CodigoPaciente codigo) {
	DiccionarioHash<CodigoPaciente, Paciente>::Iterator it = dic.busca(codigo);
	if (it != dic.end()) {
		if (it.valor().it != llegada.end()) {
			llegada.eliminar(it.valor().it);
		}
	}
	dic.borra(codigo);
}