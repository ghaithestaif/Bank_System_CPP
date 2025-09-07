#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;


class clsUpdateCurrencyRateScreen : protected  clsScreen
{
private : 


	static float _readRate() 
	{
		cout << "Enter New Rate :   ";

		float newRate = clsInputValidate::readDoubleNumber();

		return newRate;
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


public : 


	static void showUpdateCurrencyRateScreen() 
	{

		_drawScreenHeader("Update Currency Screen");

		string currencyCode = clsInputValidate::readString("\nPlease Enter Currency Code  ?  :  ");

		while (!clsCurrency::isCurrencyExist(currencyCode)) 
		{
			currencyCode = clsInputValidate::readString("\nPlease Enter  A Valid Currency Code  ?  :  ");
		}

		clsCurrency currency = clsCurrency::findByCode(currencyCode);

		_printCurrencyCard(currency);

		cout << "\n\nAre You Sure You Want To Update The Rate Of This Currency ? :   y/n  ? :  ";


		if (clsInputValidate::getUserRespondAsBoolean())
		{
			cout << "\n\nUpdate Currency Rate :\n";
			cout << "______________________________________________________\n\n";

			currency.updateRate(_readRate());

			cout << "\n\nCurrency Rate Updated Successfully :-)\n";

			_printCurrencyCard(currency);

		}

	}
};

