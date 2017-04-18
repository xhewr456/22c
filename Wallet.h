#ifndef WALLET_H
#define WALLET_H
#include"Currency.h"
#include"Dollars.h"
#include"Rubles.h"
#include"Euros.h"
#include"Yuans.h"
#include"Pesos.h"
#include<iostream>

using namespace std;

class Wallet
{
private:
	Currency **current_currencies = new Currency*[5];
	double tempValue;
public:
	//Currency **current_currencies = new Currency*[5];
	Wallet();
	//{
		//current_currencies[0] = new Dollars();
		//current_currencies[1] = new Euros();
		//current_currencies[2] = new Rubles();
		//current_currencies[3] = new Yuans();
		//current_currencies[4] = new Pesos();
	//}
	~Wallet();
	void listAllCurrencyValues();
	void zeroAllFunds();
	void addCurrency(int type);
	void subtractCurrency(int type);
	friend void requestCurrencyNumberValues(bool isAddition, Wallet &walletReference, int currencyType);

	// input stream overloading
	friend istream& operator >> (istream &inputStream, Wallet &refCurrencyObject)
	{
		inputStream >> refCurrencyObject.tempValue;
		return inputStream;
	}

};

#endif