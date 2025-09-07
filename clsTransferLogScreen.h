#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

 
class clsTransferLogScreen : protected clsScreen
{

private :

	static void _printTransferLogRecordLine(clsBankClient::stTransferLogRecord record) 
	{
		cout << left << setw(8) << "" << "| " << left << setw(20) << record.dateTime;
		cout << "| " << left << setw(8) << record.sourceAccountNumber;
		cout << "| " << left << setw(8) << record.destinationAccountNumber;
		cout << "| " << left << setw(8) << record.amount;
		cout << "| " << left << setw(13) << record.sourceBalance;
		cout << "| " << left << setw(13) << record.destinationBalance;
		cout << "| " << left << setw(13) << record.username;
	}


public :

	static void showTransferLogScreen() 
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogs = clsBankClient::getTransferLogsList();

		string title = "Transfer Log List Screen";
		string subtitle = "\t(" + to_string(vTransferLogs.size()) + ") Record(s).";

		_drawScreenHeader(title, subtitle);

		cout << left << setw(8) << "" << "_______________________________________________________________________";
		cout << "____________________________________\n";

		cout << left << setw(8) << "" << "| " <<  left << setw(20) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(13) << "s.Balance";
		cout << "| " << left << setw(13) << "d.Balance";
		cout << "| " << left << setw(13) << "User";

		cout << endl << left << setw(8) << "" << "_______________________________________________________________________";
		cout << "____________________________________\n";


		if (vTransferLogs.size() == 0) 
		{
			cout << left << setw(44) << "" << "There's No Transfers Logged To The System.";
		}

		else 
		{
		
			for (clsBankClient::stTransferLogRecord& record : vTransferLogs) 
			{
				_printTransferLogRecordLine(record);
				cout << endl;
			}
		}

		cout << endl << left << setw(8) << "" << "_______________________________________________________________________";
		cout << "____________________________________\n";
	}
};

