#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;


class clsDeleteUserScreen : protected clsScreen
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

	static void showDeleteUserScreen() 
	{
		_drawScreenHeader("Delete User Screen");

		string username = clsInputValidate::readString("Enter Username ? :  ");

		while (!clsUser::isUserExist(username)) 
		{
			username = clsInputValidate::readString("Invalid Username Not Found, Enter AnotherUsername ? :  ");
		}

		clsUser user = clsUser::find(username);

		_printUserCard(user);

		cout << "Are You Sure You Want To Delete This User ? :  y/n ? :  ";

		if (clsInputValidate::getUserRespondAsBoolean()) 
		{
			if (user.Delete()) 
			{
				cout << "\nUser Deleted Successfully :-) \n";
				_printUserCard(user);
			}

			else 
			{
				cout << "\nError User Was Not Deleted\n";
			}
		}
	}
};

