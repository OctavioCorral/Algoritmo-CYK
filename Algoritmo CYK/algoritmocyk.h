/*
AUTOR:    Octavio Corral Tovar
CURSO:    Lenguajes y Automatas 1
PROGRAMA: Implementación de CYK
FECHA:    25/05/2022
*/

#ifndef algoritmocyk_hpp
#define algoritmocyk_hpp

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

//DECLARAMOS
typedef struct {
	int A;
	int B;
	int C;

}rule;

/*Declaracion de los mapas, sets y vectores*/
typedef vector<rule> grammar;
typedef set<int> myset;
typedef map<int, myset> row;
typedef map<int, row> tableau;	

class CYKimplement {
	
private: //atributos
	grammar g;
	tableau N;

public:
	CYKimplement(); //constructor
	rule Reglas(int A, int B, int C) {
		rule rules;
		rules.A = A;    /*A = Generador  B = Primero  C = Segundo*/
		rules.B = B;
		rules.C = C;
		return rules;
	}


	//metodos
	bool cyk(string& w);
	
	/*Metodos de busqueda de cadenas*/

	void buscar(myset& N, char letra, grammar& g) {
		for (int i = 0; i < g.size(); i++) {
			if (g[i].B == letra) N.insert(g[i].A);
			
		}
	}

	void busquedacomb(myset& N, myset& a, myset& b, grammar& g) {
		myset::iterator i;
		myset::iterator j;
		for (i = a.begin(); i != a.end(); i++) {
			for (j = b.begin(); j != b.end(); j++) {
				for (int k = 0; k < g.size(); k++) {
					if (g[k].B == *i && g[k].C == *j) N.insert(g[k].A);
					
				}
			}
		}         
	}
	   
};

#endif /*algoritmocyk_hpp*/
