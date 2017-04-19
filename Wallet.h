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
	double inStreamTempValue;
public:
	Wallet();
	~Wallet();
	void displayWalletFunds();
	void zeroAllFunds();
	void addCurrency(int type);
	void subtractCurrency(int type);
	friend void requestCurrencyNumberValues(bool isAddition, Wallet &walletReference, int currencyType);

	// input stream overloading
	friend istream& operator >> (istream &inputStream, Wallet &refCurrencyObject)
	{
		inputStream >> refCurrencyObject.inStreamTempValue;
		return inputStream;
	}

};

#endif