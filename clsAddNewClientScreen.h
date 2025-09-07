#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{

private :

	static void _readClientInfo(clsBankClient &client) 
	{
		client.firstName = clsInputValidate::readString("\t\t\t\tEnter First Name ? : ");
		client.lastName = clsInputValidate::readString("\t\t\t\tEnter Last Name ? : ");
		client.email = clsInputValidate::readString("\t\t\t\tEnter Email ? : ");
		client.phone = clsInputValidate::readString("\t\t\t\tEnter Phone Number ? : ");
		client.pinCode = clsInputValidate::readString("\t\t\t\tEnter Pin Code ? : ");

		cout << "\t\t\t\tEnter Account Balance ? :  ";
		client.balance = clsInputValidate::readDoubleNumber();
	}


	static void _printClient(clsBankClient client) 
	{
		cout << "\nCleint Card Info : \n";
		cout << "\n________________________________________________________\n";
		cout << "First Name           : " <<client.firstName << endl;
		cout << "Last Name            : " <<client.lastName << endl;
		cout << "Full Name            : " <<client.getFullName() << endl;
		cout << "Email                : " <<client.email << endl;
		cout << "Phone Number         : " <<client.phone << endl;
		cout << "Account Number       : " <<client.getAccountNumber() << endl;
		cout << "Pin Code             : " <<client.pinCode << endl;
		cout << "Balance              : " <<client.balance << endl;
		cout << "\n________________________________________________________\n";
	}

public :

	static void showAddNewClientScreen()
	{
		if (!checkAccessRights(clsUser::pAddNewClient))
		{
			return;
		}

		_drawScreenHeader("Add New Client Screen");
		
		string accountNumber = clsInputValidate::readString("\t\t\t\tPlease Enter Account Number ? : ");

		while (clsBankClient::isClientExist(accountNumber)) 
		{
			accountNumber = 
				clsInputValidate::
				readString("\t\t\t\tAccount Number Already Found! ,Please Enter Another Account Number ? : ");
		}

		clsBankClient client = clsBankClient::getAddNewClientObject(accountNumber);


		_readClientInfo(client);

		clsBankClient::enSaveResults saveResult = client.save();

		
		switch (saveResult) 
		{
		case clsBankClient::SaveSucceeded:
			cout << "\nClient Added Succesefully\n";
			_printClient(client);
			break;

		case clsBankClient::SaveFailedAccountNumberExists:
			cout << "\nUnable To Save due System Have Identified The Account Number As Already Exist\n";
			_printClient(client);
			break;

		case clsBankClient::SaveFailedEmptyObject:
			cout << "Error Unable to save empty client object.";
			_printClient(client);
			break;

		}

	}
};

