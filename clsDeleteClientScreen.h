#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iostream>
using namespace std;


class clsDeleteClientScreen : protected  clsScreen
{

private :

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


	static void showDeleteClientScreen() 
	{

		if (!checkAccessRights(clsUser::pDeleteClient))
		{
			return;
		}

		_drawScreenHeader("Delete Client Screen");

		string accountNumber = clsInputValidate::readString("Please Enter Account Number ? :   ");

		while (!clsBankClient::isClientExist(accountNumber)) 
		{
			accountNumber =
				clsInputValidate::
				readString("Invalid Account Number!!!, Please Enter Another Account Number ? :   ");
		}

		clsBankClient client = clsBankClient::find(accountNumber);

		_printClient(client);

		char answer = 'n';

		cout << "Are You Sure You Want To Delete This Client ? : y/n ? :  ";
		cin >> answer;


		if (tolower(answer) == 'y')
		{

			if (client.Delete()) 
			{
				cout << "\nClient Deleted Successfully.\n";
				_printClient(client);

			}

			else 
			{
				cout << "\nClient Was Not Found !!!\n";
			}

		}
	}
	
};

