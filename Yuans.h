#ifndef YUANS_H
#define YUANS_H
#include <string>
#include<iostream>
#include"Currency.h"

class Yuans : public Currency {
public:
	// constructor
	Yuans(string w = "Yuans", string p = "Fen") :Currency(w, p) 
	{
		//setName("Yuan", "Fen");
	}

	// destructor
	~Yuans()
	{ 
		cout << "yuans class Deconstructor\n";
	}
};

#endif