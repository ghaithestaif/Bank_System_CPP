#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include"clsUtil.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

private :

	static void printClientRcordBalanceLine(clsBankClient client) 
	{
	
		cout << left << setw(25) << "" << "| " << left << setw(20) << client.getAccountNumber();
		cout << "| " << left << setw(50) << client.getFullName();
		cout << "| " << left << setw(14) << client.balance;

		//cout << "\t\t| " << left << setw(20) << client.getAccountNumber();
		//cout << "| " << left << setw(50) << client.getFullName();
		//cout << "| " << left << setw(14) << client.balance;
	}


public : 

	static void showTotalBalances() 
	{
		vector <clsBankClient> vClients = clsBankClient::getClientList();
		//vector <clsBankClient> vClients;

		string title = "Balance List Screen";

		string subtitle = " (" + to_string(vClients.size()) + ") Client(s).";

		_drawScreenHeader(title, subtitle);

	/*	cout << left << setw(25) << "" << "\n\t\t___________________________________________________________________";
		cout << "________________________________\n\n";*/

		cout << "\n\t\t___________________________________________________________________";
		cout << "________________________________\n\n";

		cout << left << setw(25) << "" << "| " << left << setw(20) << "Acccount Number";
		cout << "| " << left << setw(50) << "Client Name";
		cout << "| " << left << setw(14) << "Balance";


		//cout << "\t\t| " << left << setw(20) << "Acccount Number";
		//cout << "| " << left << setw(50) << "Client Name";
		//cout << "| " << left << setw(14) << "Balance";

		//cout << left << setw(25) << "" << "\n\t\t___________________________________________________________________";
		//cout << "________________________________\n";

		cout << "\n\t\t___________________________________________________________________";
		cout << "________________________________\n\n";

		if (vClients.size() == 0) 
		{
			cout << left << setw(25) << "\t\t\t\t\t\tThere is Clients In System.";
		}

		else 
		{
			for (clsBankClient& client : vClients)
			{
				printClientRcordBalanceLine(client);

				cout << endl;
			}

			cout << left << setw(25) << "" << "\n\t\t___________________________________________________________________";
			cout << "________________________________\n";

			double totalBalances = clsBankClient::getTotalBalances();

			cout << "\t\t\t\t\t\t\tTotal Balances  = " << totalBalances << endl;

			cout << "\t\t\t\t\t\t(" << clsUtil::numberToText(totalBalances) << "). \n";
		}

	}
};

