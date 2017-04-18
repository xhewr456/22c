//WHAT IS SYSTEM('CLS')
// clears the command console screen

#include<iostream>
#include<string>
#include<iomanip>
#include"Currency.h"
#include"Wallet.h"


using namespace std;

int getMenuInput(int);
void requestCurrencyType(bool, Wallet&);
void requestCurrencyNumberValues(bool, Wallet&, int);
//void addCurrency();
//void subtractCurrency();
enum CurrencyType
{
	USDOLLARS, EUROS, RUBLES, YUANS, PESOS
};

int main()
{
	//Currency testCurrency;
	//Currency *currencyPtr = new Dollars;
	//Dollars testDollars;
	Wallet mainWallet;

	//mainWallet.listAllCurrencyValues();

	int choice = 0;
	while (choice != 5) {
		//system("cls");
		cout << "1:  add currency\n";
		cout << "2:  remove currency\n";
		cout << "3:  report current funds\n";
		cout << "4:  remove all currency\n";
		cout << "5:  exit program\n";
		cout << "\ntype your choice and press [ENTER]: ";
		choice = getMenuInput(5);
		switch (choice) {
		case 1: {   // add currency choice
					bool isAddition = true;
					requestCurrencyType(isAddition, mainWallet);
					cout << "press Enter to continue ...\n";
					cin.get();
					break;
		}
		case 2: {  // remove currency choice
					bool isAddition = false;
					requestCurrencyType(isAddition, mainWallet);
					cout << "press Enter to continue ...\n";
					cin.get();
					break;
		}
		case 3: {  // report funds choice
					cout << "\nrequesting currents funds ...\n";
					mainWallet.listAllCurrencyValues();
					cout << "\npress Enter to continue ...\n";
					cin.get();
					break;
		}
		case 4: {  // remove all funds choice
					mainWallet.zeroAllFunds();
					cout << "\npress Enter to continue ...\n";
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

void requestCurrencyType(bool isAddition, Wallet &walletReference)
{
	int choice = 0;
	cout << "\nchoose the currency type to work with\n";
	cout << "1: Dollars/Cents\n";
	cout << "2: Euro/Cents\n";
	cout << "3: Ruble/Kopek\n";
	cout << "4: Yuan/Fen\n";
	cout << "5: Peso/Centavos\n";
	cout << "6: return to main menu\n";
	cout << "\ntype your choice and press [ENTER]: ";
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

void requestCurrencyNumberValues(bool isAddition, Wallet &walletReference, int currencyType)
{
	double value;
	cout << "Enter in the values: ";
	cin >> walletReference;
	if (isAddition) { // if this is an addition request
		walletReference.addCurrency(currencyType);
	}
	else { // else it is a subtraction request
		walletReference.subtractCurrency(currencyType);
	}
	cin.ignore();
}

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