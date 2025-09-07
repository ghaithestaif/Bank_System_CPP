#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;


class clsFindCurrencyScreen : protected clsScreen
{

private :


	enum enFindCurrencyOptions { eCode = 1, eCountry};


	static short _readFindCurrencyOptions() 
	{
		cout << "Find By: [1] Code or [2] Country  ? :  ";

		short choice = clsInputValidate::readIntNumberBetween(1, 2, "Find By: [1] Code or [2] Country  ? :  ");

		return choice;
	}


	static void _printCurrencyCard(clsCurrency currency)
	{
		cout << "\nCurrency Card : \n";
		cout << "________________________________________________________\n";
		cout << "Country            : " << currency.getCountry() << endl;
		cout << "Code               : " << currency.getCurrencyCode() << endl;
		cout << "Name               : " << currency.getCurrencyName() << endl;
		cout << "Rate($)            : " << currency.getRate() << endl;
		cout << "________________________________________________________\n\n";
	}

	static void findCurrencyByCode() 
	{
		string currencyCode = clsInputValidate::readString("\nPlease Enter Currency Code ? :   ");

		while (!clsCurrency::isCurrencyExist(currencyCode)) 
		{
			currencyCode = clsInputValidate::readString("\nIvalid Currency Code Enter Valid Currecny Code ? :   ");
		}

		clsCurrency currency = clsCurrency::findByCode(currencyCode);

		cout << "\n\nCurrency Found :-) \n";
		
		_printCurrencyCard(currency);
	}


	static void findCurrencyByCountry()
	{
		string countryName = clsInputValidate::readString("\nPlease Enter Country Name ? :   ");

		while (clsCurrency::findByCountry(countryName).isEmpty())
		{
			countryName = clsInputValidate::readString("\nIvalid Country Name Enter Valid Country Name ? :   ");
		}

		clsCurrency currency = clsCurrency::findByCountry(countryName);

		cout << "\n\nCurrency Found :-) \n";

		_printCurrencyCard(currency);
	}


	static void _performFindCurrencyOptions(enFindCurrencyOptions choice)
	{
		switch (choice) 
		{
		case eCode :
			findCurrencyByCode();
			break;

		case eCountry:
			findCurrencyByCountry();
			break;
		}
	}

public :

	static void showFindCurrencyScreen() 
	{
		_drawScreenHeader("Find Currency Screen");

		_performFindCurrencyOptions((enFindCurrencyOptions)_readFindCurrencyOptions());
	}

};

