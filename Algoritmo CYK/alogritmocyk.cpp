/*
AUTOR:    Octavio Corral Tovar
CURSO:    Lenguajes y Automatas 1
PROGRAMA: Implementación de CYK
FECHA:    25/05/2022
*/

using namespace std;
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "algoritmocyk.h"

//DEFINIMOS

//Metodos
CYKimplement::CYKimplement() {  //Contructor (Inicializacion)
	
	
	/*Gramatica utilizada*/

	//M
	g.push_back(rule({'M', 'M', 'A'}));
	g.push_back(rule({ 'M', 'V', 2001 }));
	g.push_back(rule({ 2001, ':' + 1000, 2002 }));
	g.push_back(rule({ 2002, 'Q', ';' + 1000 }));

	//A
	g.push_back(rule({ 'A', 'V', 2003 }));
	g.push_back(rule({ 2003, ':' + 1000, 2004 }));
	g.push_back(rule({ 2004, 'Q', ';' + 1000 }));

	//Q
	g.push_back(rule({ 'Q', 'P', 2005 }));
	g.push_back(rule({ 2005, '?' + 1000, 2006 }));
	g.push_back(rule({ 2006, 'Q', 2007 }));
	g.push_back(rule({ 2007, ':' + 1000, 'Q' }));
	g.push_back(rule({ 'Q', 'P', 2008 }));
	g.push_back(rule({ 2008, '|' + 1000, 'T' }));
	g.push_back(rule({ 'Q', 'T', 2009 }));
	g.push_back(rule({ 2009, '&' + 1000, 'F' }));
	g.push_back(rule({ 'Q', '(' + 1000, 2010 }));
	g.push_back(rule({ 2010, 'Q', ')' + 1000 }));
	g.push_back(rule({ 'Q', '!' + 1000, 'F' }));
	g.push_back(rule({ 'Q', 'p', 0 }));
	g.push_back(rule({ 'Q', 'q', 0 }));
	g.push_back(rule({ 'Q', 'r', 0 }));
	g.push_back(rule({ 'Q', '0', 0 }));
	g.push_back(rule({ 'Q', '1', 0 }));

	//P
	g.push_back(rule({ 'P', 'P', 2011 }));
	g.push_back(rule({ 2011, '|' + 1000, 'T' }));
	g.push_back(rule({ 'P', 'T', 2012 }));
	g.push_back(rule({ 2012, '&' + 1000, 'F' }));
	g.push_back(rule({ 'P', '(' + 1000, 2013 }));
	g.push_back(rule({ 2013, 'Q', ')' + 1000 }));
	g.push_back(rule({ 'P', '!' + 1000, 'F' }));
	g.push_back(rule({ 'P', 'p', 0 }));
	g.push_back(rule({ 'P', 'q', 0 }));
	g.push_back(rule({ 'P', 'r', 0 }));
	g.push_back(rule({ 'P', '0', 0 }));
	g.push_back(rule({ 'P', '1', 0 }));

	//T
	g.push_back(rule({ 'T', 'T', 2014 }));
	g.push_back(rule({ 2014, '&' + 1000, 'F' }));
	g.push_back(rule({ 'T', '(' + 1000, 2015 }));
	g.push_back(rule({ 2015, 'Q', ')' + 1000 }));
	g.push_back(rule({ 'T', '!' + 1000, 'F' }));
	g.push_back(rule({ 'T', 'p', 0 }));
	g.push_back(rule({ 'T', 'q', 0 }));
	g.push_back(rule({ 'T', 'r', 0 }));
	g.push_back(rule({ 'T', '0', 0 }));
	g.push_back(rule({ 'T', '1', 0 }));

	//F
	g.push_back(rule({ 'F', '(' + 1000, 2016 }));
	g.push_back(rule({ 2016, 'Q', ')' + 1000 }));
	g.push_back(rule({ 'F', '!' + 1000, 'F' }));
	g.push_back(rule({ 'F', 'p', 0 }));
	g.push_back(rule({ 'F', 'q', 0 }));
	g.push_back(rule({ 'F', 'r', 0 }));
	g.push_back(rule({ 'F', '0', 0 }));
	g.push_back(rule({ 'F', '1', 0 }));

	//V
	g.push_back(rule({ 'V', 'p', 0 }));
	g.push_back(rule({ 'V', 'q', 0 }));
	g.push_back(rule({ 'V', 'r', 0 }));

	//C
	g.push_back(rule{ ':' + 1000, ':', 0 });
	g.push_back(rule{ ';' + 1000, ';', 0 });
	g.push_back(rule{ '?' + 1000, '?', 0 });
	g.push_back(rule{ '|' + 1000, '|', 0 });
	g.push_back(rule{ '&' + 1000, '&', 0 });
	g.push_back(rule{ '(' + 1000, '(', 0 });
	g.push_back(rule{ ')' + 1000, ')', 0 });
	g.push_back(rule{ '!' + 1000, '!', 0 });

}



bool CYKimplement::cyk(string& w) {

	for (int i = 1; i <= w.length(); i++) {
		buscar(N[i][1], w[i - 1], g);
	}

	for (int j = 2; j <= w.length(); j++) {
		for (int i = 1; i <= (w.length() - j + 1); i++) {
			for (int k = 1; k <= j - 1; k++) {
				busquedacomb(N[i][j], N[i][k], N[i + k][j - k], g);
			}
		}
	}

	if (N[1][w.length()].find('M') != N[1][w.length()].end()) {
		return true;
	}
	else {
		return false;
	}

}

