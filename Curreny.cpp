#define _CRT_SECURE_NO_WARNINGS
#include"Currency.h"
#include<iostream>
#include<string>
using namespace std;

Currency::Currency(string wholeName = "whole", string partialName = "partial")
{
	setName(wholeName, partialName);
}

// virtual destructor
Currency::~Currency()
{
	cout << "currency class Deconstructor\n";
}

void Currency::setName(string wholeName, string partialName)
{
	currencyName = wholeName; fractionalName = partialName;
}
void Currency::addWholeValue(int size)
{
	wholeValue += size;
}
void Currency::addFractionalValue(int size)
{
	fractionalValue += size;
}
void Currency::subtractWholeValue(int size)
{
	wholeValue -= size;
}
void Currency::subtractFractionalValue(int size)
{
	fractionalValue -= size;
}
void Currency::setFundsToZero() {
	wholeValue = 0;
	fractionalValue = 0;
}
double Currency::getCurrentFundsValue()
{
	return (wholeValue + (fractionalValue / 100.0));
}
void Currency::balanceFraction() {
	// reuduce fractional values
	if (fractionalValue >= 100)
	{
		wholeValue += static_cast<int>(fractionalValue / 100);
		fractionalValue = fractionalValue % 100;
	}
}
