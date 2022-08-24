#ifndef _LEXICO
#define _LEXICO

#include <iostream>
#include <string>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;



class Lexico {
private:

	class TipoSimbolo {

	public:
		static const int Int = 1;
		static const int ID = 2;
		static const int Punto = 3;
		static const int Real = 4;
		static const int Error = -1;
	};

	int state, size,index = 0;
	float number;
	string Cadena, result;
	char c;
	bool next;


public:

	Lexico();

	void Inicio(const string& cadena);


	void Tipo();
	void Entrada();


	char sigSimbolo();

	bool espacio(const char& c) ;
	bool numero(const char& c);
	bool Identificador(const char& c);
	bool punto(const char& c);

	string tipoAcad();
	void retroceso();
};



#endif
