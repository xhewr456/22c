#define _CRT_SECURE_NO_WARNINGS
#include"Wallet.h"
#include<iostream>


Wallet::Wallet()
{
	current_currencies[0] = new Dollars();
	current_currencies[1] = new Euros();
	current_currencies[2] = new Rubles();
	current_currencies[3] = new Yuans();
	current_currencies[4] = new Pesos();
}
Wallet::~Wallet()
{
	for (int i = 0; i < 5; i++)
		delete current_currencies[i];
	cout << "wallet class Deconstuctor\n";
}
void Wallet::listAllCurrencyValues()
{
	for (int i = 0; i < 5; i++)
	{
		if (current_currencies[i]->getCurrentFundsValue() >= 0)
			cout << *current_currencies[i] << endl;
	}
}
void Wallet::zeroAllFunds()
{
	for (int i = 0; i < 5; i++)
	{
		current_currencies[i]->setFundsToZero();
	}
}
void Wallet::addCurrency(int currencyType)
{
	*(current_currencies[currencyType]) + tempValue;
}
void Wallet::subtractCurrency(int currencyType)
{
	*(current_currencies[currencyType]) - tempValue;
}

// input stream overloading
/*friend istream& operator >> (istream &inputStream, Wallet &refCurrencyObject)
{
inputStream >> refCurrencyObject.tempValue;
}
friend void requestCurrencyNumberValues(bool isAddition, Wallet &walletReference, int currencyType);*/
//};