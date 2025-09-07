#pragma once
#include <iostream>
#include "clsPerson.h"
#include <string>
#include "clsString.h"
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson
{

private :

	enum enMode {EmptyMode, UpdateMode, AddNewMode};

	enMode _mode;
	string _accountNumber;
	string _pinCode;
	float _accountBalance;
	bool _markedForDelete = false;


	static clsBankClient _convertLineToObject(string line, string separator = "#//#")
	{
		vector <string> vClientData = clsString::split(line, separator);

		return clsBankClient(UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4],
			vClientData[5], stof(vClientData[6]));
	}


	static string _convertObjectToLine(clsBankClient client, string separator = "#//#")
	{
		string line = "";

		line = client.firstName + separator;
		line += client.lastName + separator;
		line += client.email + separator;
		line += client.phone + separator;
		line += client._accountNumber + separator;
		line += client.pinCode + separator;
		line += to_string(client.balance);

		return line;
	}

	static clsBankClient _getEmptyObject()
	{
		return clsBankClient(EmptyMode, "", "", "", "", "",
			"", 0);
	}


	

	static void saveClientDataToFile(vector <clsBankClient> vClients) 
	{
		fstream myFile;

		myFile.open("Clients.txt", ios::out);

		if (myFile.is_open())
		{
			string line = "";

			for (clsBankClient& client : vClients) 
			{
				if (client._markedForDelete == false) 
				{
					line = _convertObjectToLine(client);

					myFile << line << endl;
				}
			}

			myFile.close();
		}
	}

	static vector <clsBankClient>  loadDataToVector() 
	{
		vector <clsBankClient> vClients;

		fstream myFile;

		myFile.open("Clients.txt", ios::in);

		if (myFile.is_open()) 
		{
			string line = "";

			while (getline(myFile, line)) 
			{
				clsBankClient client = _convertLineToObject(line);

				vClients.push_back(client);
			}

			myFile.close();
		}

		return vClients;
	}

	void _update() 
	{
		vector <clsBankClient> vClients = loadDataToVector();

		for (clsBankClient &client : vClients)
		{
			if (client._accountNumber == _accountNumber) 
			{
				client = *this;
			}
		}

		saveClientDataToFile(vClients);
	}

	void _addNew() 
	{
		_addDataLineToFile(_convertObjectToLine(*this));
	}

	void _addDataLineToFile(string dataLine) 
	{
		fstream myFile;

		myFile.open("Clients.txt", ios:: out | ios:: app);

		if (myFile.is_open()) 
		{
			myFile << dataLine << endl;
		}

		myFile.close();
	}

	struct stTransferLogRecord;

	static stTransferLogRecord _convertTransferLogRecordLineToRecord(string line, string separator = "#//#")
	{
		stTransferLogRecord record;
		vector <string> transferLogData = clsString::split(line, separator);


		record.dateTime = transferLogData[0];
		record.sourceAccountNumber = transferLogData[1];
		record.destinationAccountNumber = transferLogData[2];
		record.amount = stod(transferLogData[3]);
		record.sourceBalance = stod(transferLogData[4]);
		record.destinationBalance = stod(transferLogData[5]);
		record.username = transferLogData[6];

		return record;
	}


    string _perpareTransferLogRecordLine(double amount, clsBankClient destinationClient, string username, string separator = "#//#")
	{
		string line = "";

		line = clsDate::getSystemDateTimeString() + separator;
		line += _accountNumber + separator;
		line += destinationClient._accountNumber + separator;
		line += to_string(amount) + separator;
		line += to_string(balance) + separator;
		line += to_string(destinationClient.balance) + separator;
		line += username;

		return line;
	}


	void _registerTransferLog(double amount, clsBankClient destinationClient, string username) 
	{
		string dataLine = _perpareTransferLogRecordLine(amount, destinationClient, username);

		fstream myFile;

		myFile.open("TransferLog.txt", ios::out | ios::app);

		if (myFile.is_open()) 
		{
			myFile << dataLine << endl;

			myFile.close();
		}
	}

public :

	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone,
		string accountNumber, string pinCode, float accountBalance)
		: clsPerson(firstName, lastName, email, phone)
	{
		
		_mode = mode;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_accountBalance = accountBalance;
	}

	struct stTransferLogRecord 
	{
		string dateTime;
		string sourceAccountNumber;
		string destinationAccountNumber;
		double amount;
		double sourceBalance;
		double destinationBalance;
		string username;
	};

	bool isEmpty() 
	{
		return _mode == EmptyMode;
	}
	
	string getAccountNumber() 
	{
		return _accountNumber;
	}

	void setPinCode(string pinCode) 
	{
		_pinCode = pinCode;
	}

	string getPinCode() 
	{
		return _pinCode;
	}


	__declspec(property(get = getPinCode, put = setPinCode))string pinCode;


	void setAccountBalance(float balance)
	{
		_accountBalance = balance;
	}

	float getAccountBalance()
	{
		return _accountBalance;
	}


	__declspec(property(get = getAccountBalance, put = setAccountBalance))float balance;


	//void print() 
	//{
	//	cout << "\nCleint Card Info : \n";
	//	cout << "\n________________________________________________________\n";
	//	cout << "First Name           : " << firstName << endl;
	//	cout << "Last Name            : " << lastName << endl;
	//	cout << "Full Name            : " << getFullName() << endl;
	//	cout << "Email                : " << email << endl;
	//	cout << "Phone Number         : " << phone << endl;
	//	cout << "Account Number       : " << _accountNumber << endl;
	//	cout << "Pin Code             : " << pinCode << endl;
	//	cout << "Balance              : " << balance << endl;
	//	cout << "\n________________________________________________________\n";

	//}


	static clsBankClient find(string accountNumber) 
	{
		fstream myFile;

		myFile.open("Clients.txt", ios::in);

		if (myFile.is_open()) 
		{
			string line = "";

			while (getline(myFile, line)) 
			{
				clsBankClient client = _convertLineToObject(line);

				if (client._accountNumber == accountNumber) 
				{
					myFile.close();

					return client;
				}
			}


			myFile.close();
		}

		return _getEmptyObject();
	}


	static clsBankClient find(string accountNumber, string pinCode)
	{
		fstream myFile;

		myFile.open("Clients.txt", ios::in);

		if (myFile.is_open())
		{
			string line = "";

			while (getline(myFile, line))
			{
				clsBankClient client = _convertLineToObject(line);

				if (client._accountNumber == accountNumber && client.pinCode == pinCode)
				{
					myFile.close();

					return client;
				}
			}


			myFile.close();
		}

		return _getEmptyObject();
	}


	static bool isClientExist(string accountNumber) 
	{
		return !clsBankClient::find(accountNumber).isEmpty();
	}


	static clsBankClient getAddNewClientObject(string accountNumber) 
	{
		return clsBankClient(AddNewMode, "", "", "", "", accountNumber, "", 0);
	}


	enum enSaveResults { SaveFailedEmptyObject , SaveSucceeded, SaveFailedAccountNumberExists};

	enSaveResults save() 
	{
		switch (_mode) 
		{
		case EmptyMode :
			return SaveFailedEmptyObject;

		case UpdateMode :
			_update();
			return SaveSucceeded;

		case AddNewMode :

			if (isClientExist(_accountNumber)) 
			{
				return SaveFailedAccountNumberExists;
			}

			else 
			{
				_addNew();

				_mode = UpdateMode;

				return SaveSucceeded;
			}
		}
	}


	bool Delete() 
	{
		vector <clsBankClient> vClients = loadDataToVector();

		for (clsBankClient& client : vClients) 
		{
			if (client._accountNumber == _accountNumber) 
			{
				client._markedForDelete = true;

				saveClientDataToFile(vClients);

				*this = _getEmptyObject();

				return true;
			}
		}

		return false;
	}

	static vector <clsBankClient> getClientList() 
	{
		return loadDataToVector();
	}


	static double getTotalBalances() 
	{
		vector <clsBankClient> vClients = clsBankClient::getClientList();

		double totalBalances = 0;

		for (clsBankClient& client : vClients) 
		{
			totalBalances += client.balance;
		}

		return totalBalances;
	}


	bool transfer(double amount, clsBankClient &destinationClient, string username) 
	{
		if (amount > balance)
		{
			return false;
		}

		withdraw(amount);

		destinationClient.deposit(amount);

		_registerTransferLog(amount, destinationClient, username);

		return true;
	}


	void deposit(double amount)
	{
		balance += amount;
		save();
	}


	bool withdraw(double amount)
	{
		if (amount > balance) 
		{
			return false;
		}
		else
		{
			balance -= amount;
			save();
		}
	}


	static vector <stTransferLogRecord> getTransferLogsList()
	{
		vector <stTransferLogRecord> vTransferLogs;

		fstream myFile;

		myFile.open("TransferLog.txt", ios::in);

		if (myFile.is_open()) 
		{
			string line = "";
			stTransferLogRecord record;

			while (getline(myFile, line))
			{
				record = _convertTransferLogRecordLineToRecord(line);

				vTransferLogs.push_back(record);
			}

			myFile.close();
		}

		return vTransferLogs;
	}
};

