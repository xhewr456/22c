// CIS22C
// Lab 01
// Name:
// Partners Name:

/*
Program description: Demonstrates concepts learned in 22b; constructor initialization lists, operator overloading
classes, derived clases, and polymorhism.


The main starts with a main menu that gives the user 4 choices.
The first chioce is add currency, which then branches off and asks the user from what type of currency they want to add funds to.
The user enters in a value and the overloaded input stream operator and overloaded + operator combine to process the request and add
the funds to the selected currency type.

Second choice is the remove currency option.  It functions the same way as the add currency choice, only it remove funds.  After the
the funds have been removed, there is a check to see if the funds value goes into the negative .  If a negative value is detected, 
the values are set to zero to keep the program running smoothly.  (the lab doesn't say how to handle negative numbers)

The third choice is report wallet funds.  It will display any currency that has a value greater than zero.

The fourth choice is remove all funds, which sets all currency values to zero
*/


#include<iostream>
#include<string>
#include<iomanip>
#include"Currency.h"
#include"Wallet.h"


using namespace std;

int getMenuInput(int);
void requestCurrencyType(bool, Wallet&);
void requestCurrencyNumberValues(bool, Wallet&, int);
enum CurrencyType
{
	USDOLLARS, EUROS, RUBLES, YUANS, PESOS
};


// Display the menu choices the user can pick
// add currency choice
// remove currency choice
// report funds in wallet choice
// remove all fund from the wallet choice
// exit program choice
int main()
{
	Wallet mainWallet;

	int choice = 0;
	while (choice != 5) 
	{
		system("cls");
		cout << "1:  add currency\n";
		cout << "2:  remove currency\n";
		cout << "3:  report funds in the wallet\n";
		cout << "4:  REMOVE ALL FUNDS\n";
		cout << "5:  exit program\n";
		cout << "\ntype your choice and press [ENTER]: ";
		choice = getMenuInput(5);
		switch (choice) {
		case 1: {   // add currency choice
					bool isAddition = true;
					requestCurrencyType(isAddition, mainWallet);
					cout << "press <Enter> to continue ...\n";
					cin.get();
					break;
		}
		case 2: {  // remove currency choice
					bool isAddition = false;
					requestCurrencyType(isAddition, mainWallet);
					cout << "press <Enter> to continue ...\n";
					cin.get();
					break;
		}
		case 3:
		{  // report funds choice
			system("cls");
			cout << "\nThis wallet contains the following ...\n\n";
			mainWallet.displayWalletFunds();
			cout << "\npress <Enter> to continue ...\n";
			cin.get();
			break;
		}
		case 4: {  // remove all funds choice
					mainWallet.zeroAllFunds();
					cout << "\nRemoving ALL funds from the wallet ...";
					cout << "\npress <Enter> to continue ...\n";
					cin.get();
					break;
		}
		case 5: {  // exit program choice
					break;
		}
		default: {
					 // this should not get triggered
		}
		}  // end of switch bracket
	}
	cout << "press <Enter> to exit the program ...";
	cin.get();
	return 0;
}

// After the user picks what function they want to perform, add or remove, the next step is to get the
// currency type the user wants to modify
void requestCurrencyType(bool isAddition, Wallet &walletReference)
{
	int choice = 0;
	system("cls");
	cout << "\nchoose the currency type to ";
	
	if (isAddition)  // if the call is addition, display this message
		cout << "ADD funds to\n";
	else  // if the call is subtraction, display this message instead
		cout << "REMOVE funds from\n";

	cout << "1: Dollars / Cents\n";
	cout << "2: Euro / Cents\n";
	cout << "3: Ruble / Kopek\n";
	cout << "4: Yuan / Fen\n";
	cout << "5: Peso / Centavos\n";
	cout << "6: return to main menu\n";
	cout << "\ntype your choice and press <Enter>: ";
	choice = getMenuInput(6);

	switch (choice) {
	case 1: {
				requestCurrencyNumberValues(isAddition, walletReference, USDOLLARS);
				break;
	}
	case 2: {
				requestCurrencyNumberValues(isAddition, walletReference, EUROS);
				break;
	}
	case 3: {
				requestCurrencyNumberValues(isAddition, walletReference, RUBLES);
				break;
	}
	case 4: {
				requestCurrencyNumberValues(isAddition, walletReference, YUANS);
				break;
	}
	case 5: {
				requestCurrencyNumberValues(isAddition, walletReference, PESOS);
				break;
	}
	case 6: {
				cout << "\npress Enter to continue ...";
				cin.get();
				break;
	}
	default:
	{
	}
	}  // end of switch bracket
}


// This function prompts the user to enter in a value they want to add or remove from the currency type sent 
// from the requestCurrencyType() function
// Wanted to add input filtering here but was unable to get it work with the in-stream operator overloading
void requestCurrencyNumberValues(bool isAddition, Wallet &walletReference, int currencyType)
{
	double value;
	string currencyNameArray[5] = {"US Dollars", "Euros", "Pesos", "Rubles", "Yuans"};
	system("cls");
	if (isAddition)  // if this is an addition request
	{
		cout << "\nADDING funds to " << currencyNameArray[currencyType] << endl;
		cout << "Enter in a value using <123.45> format: ";
		cin >> walletReference;
		walletReference.addCurrency(currencyType);
		cout << "\nFunds Added.\n";
	}
	else  // else it is a subtraction request
	{
		cout << "\nREMOVING funds from " << currencyNameArray[currencyType] << endl;
		cout << "Enter in a value using <123.45> format: ";
		cin >> walletReference;
		walletReference.subtractCurrency(currencyType);
		cout << "\nFunds Removed.\n";
	}
	cin.ignore();
}

// Fliter out bad user input before it gets sent back to the function
int getMenuInput(int size) {
	int userInput = 0;
	string tempString;
	getline(cin, tempString);
	while ((tempString[0] < 49 || tempString[0] > (48 + size)) || tempString[1] != '\0') {  // 1 - size
		cout << "1 - " << size << " are the only valid choices, try again: ";
		getline(cin, tempString);
	}
	userInput = stoi(tempString);
	return userInput;
}