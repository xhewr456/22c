#ifndef RUBLES_H
#define RUBLES_H
#include <string>
#include<iostream>
#include"Currency.h"

class Rubles : public Currency 
{
public:
	// constructor
	Rubles(string w = "Rubles", string p = "Kopek") :Currency(w, p) 
	{
		//setName("Ruble", "Kopek");
	}

	// destructor
	~Rubles()
	{ 
		cout << "rubles class Deconstructor\n";
	}
};

#endif