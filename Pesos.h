#ifndef PESOS_H
#define PESOS_H
#include <string>
#include<iostream>
#include"Currency.h"

class Pesos : public Currency {
public:
	// constructor
	Pesos(string w = "Pesos", string p = "Centavos") :Currency(w, p)
	{
		//setName("Peso", "Centavos");
	}

	// destructor
	~Pesos()
	{
		cout << "pesos class Deconstructor\n";
	}
};

#endif