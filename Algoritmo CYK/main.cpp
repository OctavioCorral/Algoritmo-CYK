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


int main() {
	CYKimplement y;

	string w;
	cout << "w: ";
	cin >> w;

	if (y.cyk(w)) {
		cout << "\naccepted"<<endl;
	}
	else {
		cout << "\nrejected"<<endl;
	}

	return 0;
}