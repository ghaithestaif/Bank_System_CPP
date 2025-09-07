#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;


class clsFindUserScreen : protected clsScreen 
{

private :

	static void _printUserCard(clsUser user)
	{
		cout << "\nUser Card   : ";
		cout << "\n__________________________________________________________\n";
		cout << "First Name                : " << user.firstName << endl;
		cout << "Last Name                 : " << user.lastName << endl;
		cout << "Full Name                 : " << user.getFullName() << endl;
		cout << "Email                     : " << user.email << endl;
		cout << "Phone Number              : " << user.phone << endl;
		cout << "Username                  : " << user.username << endl;
		cout << "Password                  : " << user.password << endl;
		cout << "Permission                : " << user.permissions << endl;

		cout << "\n__________________________________________________________\n";
	}


public : 

	static void showFindUserScreen() 
	{
		_drawScreenHeader("Find User Screen");

		string username = clsInputValidate::readString("Enter Username  ? : ");

		while (!clsUser::isUserExist(username)) 
		{
			username = clsInputValidate::readString("Invalid Username Not Found, Enter Another Username  ? : ");
		}

		clsUser user = clsUser::find(username);

		if (!user.isEmpty())
		{
			cout << "\nUser Is Found :-) \n";
		}
		else 
		{
			cout << "\nUser Is Not Found \n";
		}

		_printUserCard(user);
	}
};

