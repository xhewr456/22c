#ifndef DOLLARS_H
#define DOLLARS_H
#include<string>
#include<iostream>
#include"Currency.h"

class Dollars : public Currency
{
public:
	// constructor
	Dollars(string w = "Dollars", string p = "Cents") :Currency(w, p)
	{
		//setName("Dollars", "Cents");
	}

	// virtual destructor
	virtual ~Dollars()
	{
		cout << "dollars class Deconstructor\n";
	}
};

#endif