#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private :
	
	static void _printCurrencyRecordLine(clsCurrency currency) 
	{
		cout << left << setw(8) << ""  << "| " << left << setw(28) << currency.getCountry();
		cout << "| " << left << setw(5) << currency.getCurrencyCode();
		cout << "| " << left << setw(40) << currency.getCurrencyName();
		cout << "| " << left << setw(12) << currency.getRate();
	}


public :

	static void showCurrenciesListScreen() 
	{
		vector <clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();

		string title = "Currencies List Screen";
		string subtitle = "(" + to_string(vCurrencies.size()) + ") Currency.";

		_drawScreenHeader(title , subtitle);

		cout << left << setw(8) << "" << "________________________________________________________";
		cout << "_____________________________________\n";

		cout << left << setw(8) << "" << "| " << left << setw(28) << "Country";
		cout << "| " << left << setw(5) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(12) << "Rate/(1$)";

		cout << endl << left << setw(8) << "" << "________________________________________________________";
		cout << "_____________________________________\n";


		if (vCurrencies.size() == 0) 
		{
			cout << left << setw(42) << "" << "There's No Currencies Available Date In The System.\n";
		}

		else 
		{
			for (clsCurrency & currency : vCurrencies) 
			{
				_printCurrencyRecordLine(currency);
				cout << "\n";
			}
		}



		cout << endl << left << setw(8) << "" << "________________________________________________________";
		cout << "_____________________________________\n";

	}
};

