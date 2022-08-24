#include "Lexico.h"

Lexico::Lexico(){

}

void Lexico::Inicio(const string& cadena)
{
	Cadena = cadena;
	size = Cadena.length();
}

void Lexico::Tipo()
{
	switch (state) {
	case TipoSimbolo::Int:
		cout << "Entero";
		break;
	case TipoSimbolo::ID:
		cout << "Identificador";
		break;
	case TipoSimbolo::Punto:
		cout << "Punto";
		break;
	case TipoSimbolo::Real:
		cout << "Real";
		break;
	case TipoSimbolo::Error:
		cout << "Error";
		break;
	}
	cout << endl;

}

char Lexico::sigSimbolo()
{
	return Cadena[index++];
}

bool Lexico::espacio(const char& c)
{
	return c== ' ' || c == '\t';
}

bool Lexico::numero(const char& c)
{
	return isdigit(c);
}

bool Lexico::Identificador(const char& c)
{
	return isalpha(c) || c == 'ñ';
}

bool Lexico::punto(const char& c)
{
	return c== '.';
}

string Lexico::tipoAcad()
{
	string cadena;
	switch (state) {
	case TipoSimbolo::Int:
		cout << "Entero";
		break;
	case TipoSimbolo::ID:
		cout << "Identificadores";
		break;
	case TipoSimbolo::Punto:
		cout << "Punto";
		break;
	case TipoSimbolo::Real:
		cout << "Real";
		break;
	case TipoSimbolo::Error:
		cout << "Error";
		break;
	}

	return cadena;
}

void Lexico::retroceso()
{

	cout << result << " ----tipo ";
	cout << tipoAcad() << endl;
	if (state == 1) {

	}
	else if (state == 3) {
		if (isalpha(c)) {
		}
	}
	else if (state == 4) {
		if (isalpha(c)) {
		}
		else if (c == '.') {
			state = -1;
		}
	}
	result = "";
	state = 0;
}


/// Inicio del automata
void Lexico::Entrada()
{
	state = 0;
	next = true;
	result = "";

	while (index < size) {
		if (next) {
			c = sigSimbolo();
		}

		if (numero(c) and state == 0) {
			state = 1;
			result += c;
			next = true;
		}
		else if (numero(c) and state == 1) {
			result += c;
		}
		else if ((Identificador(c) or c ==164) and state == 0) {
			state = 2;
			result += c;
			next = true;
		}
		else if ((Identificador(c) or c == 164) and state == 2) {
			state = 2;
			result += c;
			next = true;
		}
		else if (espacio(c)) {

		}
		else if (punto(c) and state == 1){
			state = 3;
			result += c;
		}
		else if (numero(c) and state == 3) {
			state = 4;
			result += c;
		}
		else if (numero(c) and state == 4) {
			result += c;
		}
		else if (state == -1) {
			next = true;
			result += c;
		}
		else if (numero(c) or Identificador(c) and state != 3) {
			next = false;
			retroceso();
		}
		else {
			cout << result << " ----tipo ";
			cout << tipoAcad() << endl;
			cout << c << ": ERORR";
			result += c;
			state =-1;
		}

		if (next) {
			cout << c << ": " ;
			Tipo();
		}


	}

    cout << result << " ----tipo ";
	cout << tipoAcad() << endl;

}

