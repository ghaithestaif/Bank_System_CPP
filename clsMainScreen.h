#pragma once
#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "Global.h"
using namespace std;



class clsMainScreen :  clsScreen
{


private : 

	enum enMainMenuOptions { ShowClientsList = 1, AddNewClient,
		DeleteClient, UpdateClient,FindClient,  Transactions, ManageUsers, LoginRegister, CurrencyExchange, Exit };




	static short _readMainMenuOption() 
	{
		short choice;

		cout << left << setw(37) << "" << "Choose What Do You Want To Do  [1 To 10] : ?   ";
		choice = clsInputValidate::readIntNumberBetween(1, 10 ,"Enter Number Between 1 And 10");

		return choice;
	}


	static void _goBackToMainMenu() 
	{

		cout << "\n\nEnter any key to go back to main menu\n";
		system("pause > 0");

		showMainScreen();
	}


	static void _showClientListScreen() 
	{
		clsClientListScreen::showClientList();		
	}

	static void _showAddClientScreen()
	{
		//cout << "Adding New Client  Will Be Here But It's Not Implemented Yet.";
		clsAddNewClientScreen::showAddNewClientScreen();
	}


	static void _showDeleteClientScreen()
	{
		//cout << "Delete  Client  Will Be Here But It's Not Implemented Yet.";
		clsDeleteClientScreen::showDeleteClientScreen();
	}

	static void _showUpdateClientScreen()
	{
		//cout << "Update  Client  Will Be Here But It's Not Implemented Yet.";
		clsUpdateClientScreen::showUpdateClientScreen();

	}


	static void _showFindClientScreen()
	{
		//cout << "Find  Client  Will Be Here But It's Not Implemented Yet.";
		clsFindClientScreen::showFindClientScreen();
	}


	static void _showTransactionsScreen() 
	{
		//cout << "Transactions  Will Be Here But It's Not Implemented Yet.";
		clsTransactionsScreen::showTransactionScreen();
	}


	static void _showManageUsersScreen()
	{
		//cout << "Manage Users Will Be Here But It's Not Implemented Yet.";
		clsManageUsersScreen::showManageUsersMenu();
	}

	static void _showLoginRegisterScreen() 
	{
		clsLoginRegisterScreen::showLoginRegisterScreen();
	}

	//static void showEndScreen() 
	//{
	//	cout << "=========================================\n";
	//	cout << "               Program End :-)\n";
	//	cout << "=========================================\n";

	//}
	
	static void _showCurrencyExchangeScreen() 
	{
		clsCurrencyExchangeMainScreen::showCurrenciesMenu();
	}

	static void _logOut() 
	{
		currentUser = clsUser::find("", "");
	}


	static void _performMainMenuOptions(enMainMenuOptions choice) 
	{
		system("cls");

		switch (choice) 
		{
		case ShowClientsList:
			//system("cls");
			_showClientListScreen();
			_goBackToMainMenu();
			break;

		case AddNewClient:
			//system("cls");
			_showAddClientScreen();
			_goBackToMainMenu();
			break;

		case DeleteClient:
			//system("cls");
			_showDeleteClientScreen();
			_goBackToMainMenu();
			break;

		case UpdateClient:
			//system("cls");
			_showUpdateClientScreen();
			_goBackToMainMenu();
			break;

		case FindClient:
			//system("cls");
			_showFindClientScreen();
			_goBackToMainMenu();
			break;

		case Transactions:
			//system("cls");
			_showTransactionsScreen();
			_goBackToMainMenu();
			//system("cls");
			//showMainScreen();
			break;

		case ManageUsers:
			//system("cls");
			_showManageUsersScreen();
			//showMainScreen();
			_goBackToMainMenu();
			break;

		case LoginRegister:
			_showLoginRegisterScreen();
			_goBackToMainMenu();
			break;

		case CurrencyExchange:
			_showCurrencyExchangeScreen();
			_goBackToMainMenu();
			break;

		case Exit: 
			//system("cls");
			//showEndScreen();
			_logOut();
			break;
		}
	} 


public : 

	static void showMainScreen() 
	{
		system("cls");
		_drawScreenHeader("Main Screen");
		cout << left << setw(37) << "" << "======================================================\n";
		cout << left << setw(37) << "" << "                     Main Menu Screen\n";

		cout << left << setw(37) << "" << "======================================================\n";


		cout <<left << setw(37) <<  "" << "[1] Show Clients List.\n";
		cout << left << setw(37) << "" << "[2] Add New Client.\n";
		cout << left << setw(37) << "" << "[3] Delete Client.\n";
		cout << left << setw(37) << "" << "[4] Update Client.\n";
		cout << left << setw(37) << "" << "[5] Find Client.\n";
		cout << left << setw(37) << "" << "[6] Transactions.\n";
		cout << left << setw(37) << "" << "[7] Manage Users.\n";
		cout << left << setw(37) << "" << "[8] Login Register.\n";
		cout << left << setw(37) << "" << "[9] Currency Exchange.\n";
		cout << left << setw(37) << "" << "[10] LogOut.\n";

		cout << left << setw(37) << "" << "======================================================\n";

		_performMainMenuOptions((enMainMenuOptions) _readMainMenuOption());
	}
};

