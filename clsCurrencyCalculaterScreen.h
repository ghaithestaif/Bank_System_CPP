#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculaterScreen : protected clsScreen
{

private : 

	static clsCurrency _getCurrency(string message) 
	{
		string currencyCode = clsInputValidate::readString(message);

		while (!clsCurrency::isCurrencyExist(currencyCode))
		{
			currencyCode = clsInputValidate::readString("\n\nInvalid , " + message);
		}

		return clsCurrency::findByCode(currencyCode);
	}


	static float _readAmount() 
	{
		cout << "\n\nEnter Amount To Exchange ? :  ";
		
		float amount = clsInputValidate::readDoubleNumber();

		return amount;
	}


	static void _printCurrencyCard(clsCurrency currency, string title = "Currency Card")
	{
		cout << endl << title << endl;
		cout << "________________________________________________________\n";
		cout << "Country            : " << currency.getCountry() << endl;
		cout << "Code               : " << currency.getCurrencyCode() << endl;
		cout << "Name               : " << currency.getCurrencyName() << endl;
		cout << "Rate($)            : " << currency.getRate() << endl;
		cout << "________________________________________________________\n\n";
	}

	
	static void _printCalculationsResults(float amount, clsCurrency currencyFrom, clsCurrency currencyTo) 
	{

		_printCurrencyCard(currencyFrom, "Convert From   :  ");
		
		if (currencyFrom.getCurrencyCode() == "USD") 
		{
			cout << amount << " " << currencyFrom.getCurrencyCode() << " = " 
				<< currencyFrom.convertFromUSD(amount, currencyTo) << " " << currencyTo.getCurrencyCode() << endl;

			return;
		}


		if (currencyTo.getCurrencyCode() == "USD") 
		{
			float amountInUSD = currencyFrom.convertToUSD(amount);

			cout << amount << " " << currencyFrom.getCurrencyCode() <<
				" = " << amountInUSD << " " << currencyTo.getCurrencyCode() << endl;

			return;
		}

		cout << "\nConverting From USD To : \n";

		_printCurrencyCard(currencyTo, "Convert To  :  ");


		float amountInCurrencyTo = currencyFrom.convertToOtherCurrency(amount, currencyTo);


		cout << amount << " " << currencyFrom.getCurrencyCode() << " = "
			<< amountInCurrencyTo  << " " << currencyTo.getCurrencyCode() << endl;

	}



public :

	static void showCurrencyCalculatedScreen() 
	{

		
		do
		{
			system("cls");

			_drawScreenHeader("Currency Calculater Screen");

			clsCurrency currencyFrom = _getCurrency("Please Enter The First Currency Code ? :  ");

			cout << endl;

			clsCurrency currencyTo = _getCurrency("Please Enter The Second Currency Code ? :  ");

			
			float amount = _readAmount();

			_printCalculationsResults(amount, currencyFrom, currencyTo);


			cout << "\n\nDo You Want To Perform Another Calculation ? :   y/n ? :  ";
		
		}
		while (clsInputValidate::getUserRespondAsBoolean());

	}
};

