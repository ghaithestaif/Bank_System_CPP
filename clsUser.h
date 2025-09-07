#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

const static string UsersFileName = "Users.txt";
const static string LoginRegistFileName = "LoginRegister.txt";

class clsUser : public clsPerson
{
	enum enMode { EmptyMode, UpdateMode, AddNewMode };

	enMode _mode;
	string _username;
	string _password;
	int _permissions;

	struct stLoginRegisterRecord;
	bool _markedForDelete = false;


	static string _convertObjectToDataLine(clsUser user, string separator = "#//#")
	{
		string line = "";

		line = user.firstName + separator;
		line += user.lastName + separator;
		line += user.email + separator;
		line += user.phone + separator;
		line += user.username + separator;
		line += clsUtil::encryptText(user.password, 5) + separator;
		line += to_string(user.permissions);

		return line;
	}

	string _prepareLoginRecord(string separator = "#//#")
	{
		string line = "";

		line += clsDate::getSystemDateTimeString() + separator;
		line += username + separator;
		line += clsUtil::encryptText(password, 5) + separator;
		line += to_string(_permissions);

		return line;
	}



	static stLoginRegisterRecord _convertLoginRegisterLineToRecord(string line, string separator = "#//#")
	{
		vector <string> vLoginRegistersData = clsString::split(line, separator);

		stLoginRegisterRecord loggedUserData;

		loggedUserData.dateTime = vLoginRegistersData[0];
		loggedUserData.username = vLoginRegistersData[1];
		loggedUserData.password = clsUtil::decryptText(vLoginRegistersData[2], 5);
		loggedUserData.permissions = stoi(vLoginRegistersData[3]);

		return loggedUserData;
	}

	static clsUser _convertLineToObject(string line, string separator = "#//#")
	{
		vector <string> vClientData = clsString::split(line, separator);


		return clsUser(UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], clsUtil::decryptText(vClientData[5], 5), stof(vClientData[6]));
	}

	static clsUser  _getEmptyObject()
	{
		return clsUser(EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsUser> _loadDataToVector()
	{
		vector <clsUser> vUsers;

		fstream myFile;

		myFile.open(UsersFileName, ios::in);

		if (myFile.is_open())
		{
			string line = "";

			while (getline(myFile, line))
			{
				clsUser user = _convertLineToObject(line);


				vUsers.push_back(user);
			}

			myFile.close();
		}

		return vUsers;
	}

	void _saveDataToFile(vector <clsUser>& vUsers)
	{
		fstream myFile;

		myFile.open(UsersFileName, ios::out);

		if (myFile.is_open())
		{
			string line = "";

			for (clsUser& user : vUsers)
			{
				if (user._markedForDelete == false)
				{
					line = _convertObjectToDataLine(user);

					myFile << line << endl;
				}
			}
		}

		myFile.close();

	}

	void _update()
	{
		vector <clsUser> vUsers = _loadDataToVector();

		for (clsUser& user : vUsers)
		{
			if (user.username == username)
			{
				user = *this;
				break;
			}
		}

		_saveDataToFile(vUsers);
	}

	void _addNew()
	{
		_addDataLineToFile(_convertObjectToDataLine(*this));
	}

	void _addDataLineToFile(string dataLine)
	{
		fstream myFile;

		myFile.open(UsersFileName, ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << dataLine << endl;
		}

		myFile.close();
	}

public:

	clsUser(enMode mode, string firstName, string lastName, string email,
		string phone, string username, string password, int permission)
		: clsPerson(firstName, lastName, email, phone)
	{

		_mode = mode;
		_username = username;
		_password = password;
		_permissions = permission;
	}

	struct stLoginRegisterRecord
	{
		string dateTime;
		string username;
		string password;
		int permissions;
	};

	bool isEmpty()
	{
		return (_mode == EmptyMode);
	}


	bool getMarkedForDelete()
	{
		return _markedForDelete;
	}


	void setUsername(string username)
	{
		_username = username;
	}

	string getUsername()
	{
		return _username;
	}

	__declspec(property(get = getUsername, put = setUsername)) string username;


	void setPassword(string password)
	{
		_password = password;
	}

	string getPassword()
	{
		return _password;
	}

	__declspec(property(get = getPassword, put = setPassword)) string password;


	void setPermission(int permission)
	{
		_permissions = permission;
	}

	int getPermission()
	{
		return _permissions;
	}

	__declspec(property(get = getPermission, put = setPermission)) int permissions;

	static clsUser find(string username)
	{
		fstream myFile;

		myFile.open(UsersFileName, ios::in);

		if (myFile.is_open())
		{
			string line = "";

			while (getline(myFile, line))
			{
				clsUser user = _convertLineToObject(line);

				if (user.username == username)
				{
					myFile.close();
					return user;
				}
			}

			myFile.close();
		}

		return _getEmptyObject();
	}


	static clsUser find(string username, string password)
	{
		fstream myFile;

		myFile.open(UsersFileName, ios::in);

		if (myFile.is_open())
		{
			string line = "";

			while (getline(myFile, line))
			{
				clsUser user = _convertLineToObject(line);


				if (user.username == username && user.password == password)
				{
					myFile.close();
					return user;
				}
			}

			myFile.close();
		}

		return _getEmptyObject();
	}


	static bool isUserExist(string username)
	{
		return !clsUser::find(username).isEmpty();
	}


	bool Delete()
	{
		vector <clsUser> vUsers = _loadDataToVector();

		for (clsUser& user : vUsers)
		{
			if (user.username == username)
			{
				user._markedForDelete = true;
				break;
			}
		}

		_saveDataToFile(vUsers);

		*this = _getEmptyObject();
		return true;

	}


	enum enPermission
	{
		pAll = -1, pListClients = 1, pAddNewClient = 2,
		pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16,
		pTransactions = 32, pManageUsers = 64, pLoginRegister = 128
	};



	enum enSaveResult { SaveFailedEmptyObject, SaveSucceeded, SaveFailedUserExist };


	bool checkAccessPermission(enPermission permission)
	{
		if (this->_permissions == enPermission::pAll)
			return true;

		if ((this->_permissions & permission) == permission)
			return true;

		else
			return false;
	}

	enSaveResult save()
	{
		switch (_mode)
		{
		case EmptyMode:
			return SaveFailedEmptyObject;

		case UpdateMode:
			_update();
			return SaveSucceeded;

		case AddNewMode:

			if (clsUser::isUserExist(_username))
			{
				return SaveFailedUserExist;
			}

			else
			{
				_addNew();

				_mode = UpdateMode;

				return SaveSucceeded;
			}
		}
	}

	static clsUser getAddNewUserObject(string username)
	{
		return clsUser(AddNewMode, "", "", "", "", username, "", 0);
	}

	static vector <clsUser> getUsersList()
	{
		return _loadDataToVector();
	}

	void registerLogin()
	{
		string dataLine = _prepareLoginRecord();

		fstream myFile;

		myFile.open(LoginRegistFileName, ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << dataLine << endl;

			myFile.close();
		}
	}


	static vector <stLoginRegisterRecord>  getLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoggedUsers;

		fstream myFile;

		myFile.open(LoginRegistFileName, ios::in);

		if (myFile.is_open())
		{
			string line;
			stLoginRegisterRecord loggedUser;

			while (getline(myFile, line))
			{
				loggedUser = _convertLoginRegisterLineToRecord(line);

				vLoggedUsers.push_back(loggedUser);
			}

			myFile.close();
		}

		return vLoggedUsers;
	}

};


