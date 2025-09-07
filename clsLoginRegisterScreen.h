#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{

private : 

	static void _printLoginRegisterRecordLine(clsUser::stLoginRegisterRecord loggedUser)
	{
		cout << left << setw(8) << "" << "| " << left << setw(35) << loggedUser.dateTime;
		cout << "| " << left << setw(20) << loggedUser.username;
		cout << "| " << left << setw(20) << loggedUser.password;
		cout << "| " << left << setw(16) << loggedUser.permissions;
	}


public : 

	static void showLoginRegisterScreen() 
	{

		if (!checkAccessRights(clsUser::pLoginRegister)) 
		{
			return;
		}


		vector <clsUser::stLoginRegisterRecord> vLoggedUsers = clsUser::getLoginRegisterList();
		//vector <clsUser::stLoginRegisterRecord> vLoggedUsers;

		
		string title = "Login Register Users Screen";
		string subtitle = "\t(" + to_string(vLoggedUsers.size()) + ") User(s).";

		_drawScreenHeader(title, subtitle);

		cout << left << setw(8) << "" << "_________________________________________________________";
		cout << "_________________________________________\n";

		cout << left << setw(8) << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(16) << "Permissions";

		cout << endl << left << setw(8) << "" << "_________________________________________________________";
		cout << "_________________________________________\n";



		if (vLoggedUsers.size() == 0) 
		{
			cout << endl << left << setw(42) << "" << "There No Users Logged To The System." << endl;
		}

		else 
		{
			for (clsUser::stLoginRegisterRecord& loggedUser : vLoggedUsers) 
			{
				_printLoginRegisterRecordLine(loggedUser);

				cout << endl;
			}
		}

		cout << endl << left << setw(8) << "" << "_________________________________________________________";
		cout << "_________________________________________\n";

	}
};

