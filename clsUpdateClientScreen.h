#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"


class clsUpdateClientScreen : protected clsScreen
{

private :

	static void _readClientInfo(clsBankClient& client)
	{
		client.firstName = clsInputValidate::readString("Enter First Name ? : ");
		client.lastName = clsInputValidate::readString("Enter Last Name ? : ");
		client.email = clsInputValidate::readString("Enter Email ? : ");
		client.phone = clsInputValidate::readString("Enter Phone Number ? : ");
		client.pinCode = clsInputValidate::readString("Enter Pin Code ? : ");

		cout << "Enter Account Balance ? :  ";
		client.balance = clsInputValidate::readDoubleNumber();
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

	static void showUpdateClientScreen() 
	{

		if (!checkAccessRights(clsUser::pUpdateClient))
		{
			return;
		}

		_drawScreenHeader("Update Client Screen");
		string accountNumber = clsInputValidate::readString("Please Enter Account Number ? : ");

		while (!clsBankClient::isClientExist(accountNumber))
		{
			accountNumber = clsInputValidate::
				readString("Invalid Account Number, Please Enter Account Number Again? : ");
		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_printClient(client);

		char answer = 'n';

		cout << "\n\nAre You Sure You Want To Delete This Client ? : y/n ? :   ";

		cin >> answer;
		
		if (tolower(answer) == 'y') 
		{
			_readClientInfo(client);
			clsBankClient::enSaveResults saveResult = client.save();

			switch (saveResult) 
			{
			case clsBankClient::SaveSucceeded:
				cout << "\nClient Updated Successfully.\n";
				_printClient(client);

			case clsBankClient::SaveFailedEmptyObject:
				cout << "\nError Client not found!!!.\n";
				_printClient(client);
			}
		}
	}
};

