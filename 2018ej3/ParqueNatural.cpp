#include "ParqueNatural.h"


/* 
  COMPLEJIDAD

*/
ParqueNatural::ParqueNatural() {
/* A IMPLEMENTAR */
	ecosistemas = DiccionarioHash<string, DiccionarioHash<string, Especie>>();
	especies_eco = DiccionarioHash<string, Lista<string>>();
	total_especies = Diccionario<string, int>();
}

/* 
  COMPLEJIDAD

*/
void ParqueNatural::an_ecosistema(const string& ecosistema) {
/* A IMPLEMENTAR */
	if (ecosistemas.contiene(ecosistema)) throw EEcosistemaDuplicado();
	else {
		ecosistemas.inserta(ecosistema, DiccionarioHash<string, Especie>());
		especies_eco.inserta(ecosistema, Lista<string>());
	}

}

/* 
  COMPLEJIDAD

*/
void ParqueNatural::an_ejemplares(const string& ecosistema, const string& especie, int n) {
/* A IMPLEMENTAR */
	if (!ecosistemas.contiene(ecosistema)) throw EEcosistemaNoExiste();
	else {
		DiccionarioHash<string, DiccionarioHash<string, Especie>>::Iterator i = ecosistemas.busca(ecosistema);
		if (!i.valor().contiene(especie)) {
			especies_eco.busca(ecosistema).valor().pon_ppio(especie);
			i.valor().inserta(especie, Especie(n, especies_eco.busca(ecosistema).valor().begin()));
		}
		else {
			DiccionarioHash<string, Especie >::Iterator x = i.valor().busca(especie);
			especies_eco.busca(ecosistema).valor().eliminar(x.valor().it);
			x.valor().cant += n;
			especies_eco.busca(ecosistema).valor().pon_ppio(especie);
			x.valor().it = especies_eco.busca(ecosistema).valor().begin();
		}
		if (!total_especies.contiene(especie)) total_especies.inserta(especie, n);
		else {
			Diccionario<string, int>::Iterator y = total_especies.busca(especie);
			y.setVal(y.valor() + n);
		}
	}
	
}

/* 
  COMPLEJIDAD

*/
Lista<string> ParqueNatural::lista_especies_ecosistema(const string& ecosistema, int n) const {
/* A IMPLEMENTAR */
	if (!ecosistemas.contiene(ecosistema)) throw EEcosistemaNoExiste();
	else {
		Lista<string> sol = Lista<string>();
		if (especies_eco.contiene(ecosistema)) {
			Lista<string>::ConstIterator i = especies_eco.cbusca(ecosistema).valor().cbegin();
			int cont = 0;
			while (i != especies_eco.cbusca(ecosistema).valor().cend() && cont < n) {
				sol.pon_final(i.elem());
				i.next(); cont++;
			}
		}
		return sol;
	}
	
}

/* 
  COMPLEJIDAD

*/
int ParqueNatural::numero_ejemplares_en_ecosistema(const string& ecosistema, const string& especie) const {
/* A IMPLEMENTAR */
	if (!ecosistemas.contiene(ecosistema)) throw EEcosistemaNoExiste();
	else {
		if (ecosistemas.cbusca(ecosistema).valor().contiene(especie)) {
			return ecosistemas.cbusca(ecosistema).valor().cbusca(especie).valor().cant;
		}
	}
	return 0;
}

/* 
  COMPLEJIDAD

*/
Lista<string> ParqueNatural::lista_especies_parque() const {
/* A IMPLEMENTAR */
	Lista<string> sol = Lista<string>();
	if (!total_especies.esVacio()) {
		Diccionario<string, int>::ConstIterator i = total_especies.cbegin();
		while (i != total_especies.cend()) {
			sol.pon_final(i.clave());
			i.next();
		}
	}
	return sol;
}

/* 
  COMPLEJIDAD

*/
int ParqueNatural::numero_ejemplares_en_parque(const string& especie) const {
/* A IMPLEMENTAR */
	if (total_especies.contiene(especie))
		return total_especies.cbusca(especie).valor();
	else
		return 0;
}
 