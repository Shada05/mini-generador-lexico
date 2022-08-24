#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"

using namespace std;

int main() {
	string cadena;
	Lexico myLexico;
	cout << "Ingrese una cadena de numero y/o letras: ";
	getline(cin, cadena);
	cout << cadena << endl;
	myLexico.Inicio(cadena);
	myLexico.Entrada();
}
