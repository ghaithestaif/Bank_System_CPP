#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsDepositScreen : protected clsScreen
{

private:

	static string _readAccountNumber() 
	{
		string accountNumber;

		cout << "Please Enter Account Number ? :   ";
		cin >> accountNumber;

		return accountNumber;
	}


	static void _printClient(clsBankClient client)
	{
		cout << "\nCleint Card Info : \n";
		cout << "\n________________________________________________________\n";
		cout << "First Name           : " << client.firstName << endl;
		cout << "Last Name            : " << client.lastName << endl;
		cout << "Full Name            : " << client.getFullName() << endl;
		cout << "Email                : " << client.email << endl;
		cout << "Phone Number         : " << client.phone << endl;
		cout << "Account Number       : " << client.getAccountNumber() << endl;
		cout << "Pin Code             : " << client.pinCode << endl;
		cout << "Balance              : " << client.balance << endl;
		cout << "\n________________________________________________________\n";
	}


public : 

	static void showDepositScreen() 
	{
		_drawScreenHeader("Deposit Screen");

		string accountNumber = _readAccountNumber();

		while (!clsBankClient::isClientExist(accountNumber)) 
		{
			cout << "\nClient with account number [" << accountNumber << "] is not found!\n";

			accountNumber = _readAccountNumber();
		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_printClient(client);

		char answer = 'n';

		cout << "Are You Sure You Want Perform This Transaction ?  :  y/n  ?  :  ";
		
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			double amount;
			
			cout << "\nPlease Enter Deposit Amount ? :  ";
			amount = clsInputValidate::readDoubleNumber();


			client.deposit(amount);

			cout << "\nAmount Deposit Successfully.\n";
			cout << "\nNew Balance Is : " << client.balance << endl;
		}

		else 
		{
			cout << "\nOperation Was Cancelled\n";
		}

		
	}
};

