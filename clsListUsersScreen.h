#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;


class clsListUsersScreen : public clsScreen
{

private :

	static void _printUserRecordLine(clsUser user) 
	{
		cout << left << setw(8) << "" << "| " << left << setw(12) << user.username;
		cout << "| " << left << setw(25) << user.getFullName();
		cout << "| " << left << setw(12) << user.phone;
		cout << "| " << left << setw(25) << user.email;
		cout << "| " << left << setw(10) << user.password;
		cout << "| " << left << setw(12) << user.permissions;
	}


public : 

	static void showUsersList() 
	{
		vector <clsUser> vUsers = clsUser::getUsersList();

		string title = "Users List Screen";
		string subtitle = "(" + to_string(vUsers.size()) + ") User(s).";

		_drawScreenHeader(title, subtitle);

		
		cout << left << setw(8) << "" << "_______________________________________________________";
		cout << "_______________________________________________________\n";

		cout << left << setw(8) << "" << "| " << left << setw(12) << "Username";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permission";

		cout << endl << left << setw(8) << "" << "_______________________________________________________";
		cout << "_______________________________________________________\n";
		
		if (vUsers.size() == 0) 
		{
			cout << left << setw(25) << "\t\t System Have No Users.";
		}

		else 
		{
			for (clsUser& user : vUsers) 
			{
				_printUserRecordLine(user);
				cout << endl;
			}
		}

		cout << left << setw(8) << "" << "_______________________________________________________";
		cout << "_______________________________________________________\n";

	}
	
};

