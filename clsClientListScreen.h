#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <string>
using namespace std;


class clsClientListScreen : protected  clsScreen
{

private :

	static void _printClientRecordLine(clsBankClient client) 
	{
		cout << left << setw(8) << "" << "| " << left << setw(16) << client.getAccountNumber();
		cout << "| " << left << setw(20) << client.getFullName();
		cout << "| " << left << setw(12) << client.phone;
		cout << "| " << left << setw(20) << client.email;
		cout << "| " << left << setw(10) << client.pinCode;
		cout << "| " << left << setw(20) << client.balance;
	}

public : 

	static void showClientList() 
	{

		if (!checkAccessRights(clsUser::pListClients)) 
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::getClientList();

		string title = "Client List Screen";
		string subtitle = "  (" + to_string(vClients.size()) + ") Client(s).";

		_drawScreenHeader(title, subtitle);

		cout << "\n\n" << left << setw(8) << "" << "________________________________________________________________________";
		cout << "____________________________________\n\n";
		cout << left << setw(8) << "" << "| " << left << setw(16) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(20) << "Balance";

		cout << endl << left << setw(8) << "" << "________________________________________________________________________";
		cout << "____________________________________\n";


		if (vClients.size() == 0) 
		{
			cout << "\t\t\t\t\t  No Clients Available In The System\n";
		}

		else 
		{
			for (clsBankClient& client : vClients) 
			{
				_printClientRecordLine(client);

				cout << endl;
			}
		}

		cout << endl << left << setw(8) << "" << "________________________________________________________________________";
		cout << "____________________________________\n";
	}
};

