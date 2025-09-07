#pragma once
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include <iostream>
#include <iomanip>
using namespace std;


class clsTransactionsScreen : protected  clsScreen
{

private:

	enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw, eTotalBalance,eTransfer, eTransferLog, eMainMenu};


	static short _readTransactionsMenuOption() 
	{
		cout << left << setw(37) << "" << "Choose What Do You Want To Do [1 To 6] ? :  ";
		short choice = 
			clsInputValidate::readIntNumberBetween(1, 6, "Enter Number Between 1 And 6? ? :  ");

		return choice;
	}


	static void _goBackToTransactionsMenu() 
	{
		cout << "\n\nEnter Any Key To Go Bank To Transactions Menu\n";
		system("pause > 0");
		
		system("cls");
		showTransactionScreen();
	}

	static void _showDepositScreen() 
	{
		//cout << "Depoist Screen will be here.\n"
		clsDepositScreen::showDepositScreen();
	}

	static void _showWithdrawScreen()
	{
		//cout << "Withdraw Screen will be here.\n";
		clsWithdrawScreen::showWithdrawScreen();
	}


	static void _showTotalBalanceScreen()
	{
		//cout << "Total Balances Screen will be here.\n";
		clsTotalBalancesScreen::showTotalBalances();
	}

	static void _showTransferScreen()
	{
		//cout << "Total Balances Screen will be here.\n";
		clsTransferScreen::showTransferScreen();
	}

	static void _showTransferLogScreen()
	{
		//cout << "Transfer Log  Screen  will be here.\n";
		clsTransferLogScreen::showTransferLogScreen();
	}

	static void _performTransactionsMenuOptions(enTransactionsMenuOptions choice) 
	{
		switch (choice) 
		{
		case eDeposit:
			system("cls");
			_showDepositScreen();
			_goBackToTransactionsMenu();
			break;


		case eWithdraw:
			system("cls");
			_showWithdrawScreen();
			_goBackToTransactionsMenu();
			break;

		case eTotalBalance:
			system("cls");
			_showTotalBalanceScreen();
			_goBackToTransactionsMenu();
			break;

		case eTransfer:
			system("cls");
			_showTransferScreen();
			_goBackToTransactionsMenu();
			break;

		case eTransferLog:
			system("cls");
			_showTransferLogScreen();
			_goBackToTransactionsMenu();

		case eMainMenu:
		{
		
		}
			
		}
	}

public : 

	static void showTransactionScreen() 
	{

		if (!checkAccessRights(clsUser::pTransactions))
		{
			return;
		}

		_drawScreenHeader("Transactions Screen");

		cout << left << setw(37) << "" << "=========================================================\n";
		cout << left << setw(37) << "" << "\t\t    Transactions Menu Screen\n";

		cout << left << setw(37) << "" << "=========================================================\n";

		cout << left << setw(37) << "" << "[1] Deposit.\n";
		cout << left << setw(37) << "" << "[2] Withdraw.\n";
		cout << left << setw(37) << "" << "[3] Total Balances.\n";
		cout << left << setw(37) << "" << "[4] Transfer.\n";
		cout << left << setw(37) << "" << "[5] Transfer Log.\n";
		cout << left << setw(37) << "" << "[6] Main Menu.\n";

		cout << left << setw(37) << "" << "=========================================================\n";
	
		_performTransactionsMenuOptions((enTransactionsMenuOptions) _readTransactionsMenuOption());
	}
};

