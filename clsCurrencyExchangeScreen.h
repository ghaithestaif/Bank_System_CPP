#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculaterScreen.h"
using namespace std;


class clsCurrencyExchangeMainScreen : protected clsScreen
{
	enum enCurrenciesMainMenuOptions { eListCurrencies = 1, eFindCurrency, eUpdateRate, eCurrencyCalculater, eMainMenu};


	static short _readCurrenciesMainMenuOption() 
	{
		cout << left << setw(37) << "" << "Choose What Do You Want To Do [1 To 5] ? :  ";
		
		short choice = clsInputValidate::readIntNumberBetween(1, 5, "Enter Number Between 1 And 5 ? :  ");

		return choice;
	}

	static void _goBackToCurrenciesMenu() 
	{
		cout << "\n\nEnter Any Key To Go Back To Currencies Menu...";

		system("pause > 0");

		showCurrenciesMenu();
		
	}


	static void _showCurrenciesListScreen() 
	{
		//cout << "Currencies List Screen Will Be Here.";
		clsCurrenciesListScreen::showCurrenciesListScreen();
	}

	static void _showFindCurrencyScreen()
	{
		//cout << "Find Currency  Screen Will Be Here.";
		clsFindCurrencyScreen::showFindCurrencyScreen();
	}

	static void _showUpdateCurrerncyRateScreen()
	{
		//cout << "Update Rate Screen Will Be Here.";
		clsUpdateCurrencyRateScreen::showUpdateCurrencyRateScreen();
	}

	static void _showCurrencyCalculaterScreen()
	{
		//cout << "Currency Calculater List Screen Will Be Here.";
		clsCurrencyCalculaterScreen::showCurrencyCalculatedScreen();
	}


	static void _performCurrenciesMainMenuOption(enCurrenciesMainMenuOptions choice)
	{
		switch (choice)
		{
		case eListCurrencies:
			system("cls");
			_showCurrenciesListScreen();
			_goBackToCurrenciesMenu();
			break;

		case eFindCurrency:
			system("cls");
			_showFindCurrencyScreen();
			_goBackToCurrenciesMenu();
			break;

		case eUpdateRate:
			system("cls");
			_showUpdateCurrerncyRateScreen();
			_goBackToCurrenciesMenu();
			break;


		case eCurrencyCalculater:
			system("cls");
			_showCurrencyCalculaterScreen();
			_goBackToCurrenciesMenu();
			break;

		case eMainMenu:
			
			break;
		}
	}


public :

	static void showCurrenciesMenu() 
	{
		system("cls");
		_drawScreenHeader("Currency Exchange Main Screen");

		cout << left << setw(37) << "" << "====================================================================\n";
		cout << left << setw(37) << "" << "\t\t\tExchange Currency Menu\n";
		cout << left << setw(37) << "" << "====================================================================\n";
		cout << left << setw(37) << "" << "[1] List Currencies.\n";
		cout << left << setw(37) << "" << "[2] Find Currency.\n";
		cout << left << setw(37) << "" << "[3] Update Rate.\n";
		cout << left << setw(37) << "" << "[4] Currency Calculater.\n";
		cout << left << setw(37) << "" << "[5] Main Menu.\n";

		cout << left << setw(37) << "" << "====================================================================\n";


		_performCurrenciesMainMenuOption((enCurrenciesMainMenuOptions)_readCurrenciesMainMenuOption());
	}

	
};

