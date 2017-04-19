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

void Currency::setFundsToZero() {
	wholeValue = 0;
	fractionalValue = 0;
}
double Currency::getCurrentFundsValue()
{
	return (wholeValue + (fractionalValue / 100.0));
}

// reuduce fractional values
// Checks the values store in whole and fractional, and if both are less than zero, set both values to zero
// This is added to keep preven a situation of having negative funds, because the lab doesn't say to filter out 
// the chance that funds would go into negative numbers
void Currency::balanceFraction() {
	if (fractionalValue >= 100)
	{
		wholeValue += static_cast<int>(fractionalValue / 100);
		fractionalValue = fractionalValue % 100;
	}
	if ((wholeValue < 0) && (fractionalValue < 0))
	{
		wholeValue = 0;
		fractionalValue = 0;
	}
}
