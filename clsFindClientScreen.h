#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iostream>
using namespace std;


class clsFindClientScreen : protected clsScreen
{

private:

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

public:


	static void showFindClientScreen()
	{

		if (!checkAccessRights(clsUser::pFindClient))
		{
			return;
		}

		_drawScreenHeader("Find Client Screen");

		string accountNumber = clsInputValidate::readString("Please Enter Account Number ? :   ");

		while (!clsBankClient::isClientExist(accountNumber)) 
		{
			accountNumber = 
				clsInputValidate::
				readString("Invalid Account Number, Please Enter Another Account Number ? :   ");
		}

		
		clsBankClient client = clsBankClient::find(accountNumber);

		if (!client.isEmpty()) 
		{
			cout << "\nClient Found :-) \n";
		}

		else 
		{
			cout << "\nClient Was Not Found\n";
		}

		_printClient(client);
	}
};

