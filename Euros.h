#ifndef EUROS_H
#define EUROS_H
#include <string>
#include<iostream>
#include"Currency.h"

class Euros : public Currency {
public:
	// constructor
	Euros(string w = "Euros", string p = "Cents") :Currency(w, p) 
	{
		//setName("Euro", "Cents");
	}

	// destructor
	~Euros()
	{ 
		cout << "euros class Deconstructor\n";
	}
};

#endif