#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;


class clsTransferScreen : protected clsScreen
{
private :

	static void _printClient(clsBankClient client) 
	{
		cout << "\nClient Card : \n";
		cout << "_________________________________________________________\n";
		cout << "Full Name          : " << client.getFullName() << endl;
		cout << "Account Number     : " << client.getAccountNumber() << endl;
		cout << "Balance            : " << client.balance << endl;
		cout << "_________________________________________________________\n\n";
	}


	static string _readAccountNumber(string message) 
	{
		string accountNumber = clsInputValidate::readString(message);

		while (!clsBankClient::isClientExist(accountNumber)) 
		{
			accountNumber = clsInputValidate::readString(message);
		}

		return accountNumber;
	}

	static double _readAmount(clsBankClient sourceClient) 
	{
		cout << "\nEnter Transfer Amount ? :  \n";

		double amount = clsInputValidate::
			readDoubleNumberBetween
			(0, sourceClient.balance,
				"Invalid Amount Exceeds Account Balance, Please Enter Another Amount ? :  ");

		return amount;
	}


public :

	static void showTransferScreen() 
	{
		_drawScreenHeader("Transfer Screen");

		clsBankClient sourceClient = clsBankClient::
			find(_readAccountNumber("Enter AccountNumber You Want To Transfer From ? :  "));

		_printClient(sourceClient);


		clsBankClient destinationClient = clsBankClient::
			find(_readAccountNumber("Enter AccountNumber You Want To Transfer To ? :  "));

		_printClient(destinationClient);


		double amount = _readAmount(sourceClient);

		cout << "Are You Sure You Want To Perform This Operation ? :  y/n ? :  ";

		if (clsInputValidate::getUserRespondAsBoolean()) 
		{
			if (sourceClient.transfer(amount, destinationClient, currentUser.username)) 
			{
				cout << "\nTransfer Done Successfully.\n";
			}
			
			else 
			{
				cout << "\nTransfer Failed.\n";
			}
		}

		else 
		{
			cout << "\nOperation Canceled.\n";
		}


		_printClient(sourceClient);
		_printClient(destinationClient);



	}
};

