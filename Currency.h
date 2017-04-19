#ifndef CURRENCY_H
#define CURRENCY_H
#include <string>
#include<iostream>
#include<iomanip>

using namespace std;

class Currency {
private:
	string currencyName; 
	string fractionalName;
	int wholeValue = 0;
	int fractionalValue = 0;
public:
	// constructor
	Currency(string, string);

	// virtual destructor
	virtual ~Currency();

	void setName(string wholeName, string partialName);
	void setFundsToZero();
	double getCurrentFundsValue();
	void balanceFraction();

	//This function takes a single value, i.e. "11.99" and adds to its appropriate collection.
	friend void operator + (Currency &refCurrencyObject, double number)
	{
		refCurrencyObject.wholeValue += static_cast<int>(number);
		double x = number * 100;
		int y = (static_cast<int>(x) % 100);
		refCurrencyObject.fractionalValue += y;
		refCurrencyObject.balanceFraction();
	}

	//This function takes a single value, i.e. "11.99" and takes away from it's appropriate collection.
	friend void operator - (Currency &refCurrencyObject, double number)
	{
		refCurrencyObject.wholeValue -= static_cast<int>(number);
		double x = number * 100;
		int y = (static_cast<int>(x) % 100);
		refCurrencyObject.fractionalValue -= y;
		refCurrencyObject.balanceFraction();
	}

	// output stream overloading
	friend ostream& operator << (ostream &outputStream, Currency &refCurrencyObject)
	{
		cout << setprecision(2) << fixed;
		cout << refCurrencyObject.currencyName << ": " << refCurrencyObject.getCurrentFundsValue();
		return outputStream;
	}

	// make wallet class a friend
	friend class Wallet;
};

#endif