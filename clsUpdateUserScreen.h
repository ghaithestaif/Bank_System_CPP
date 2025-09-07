#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
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

	static void _readUserInfo(clsUser& user)
	{
		user.firstName = clsInputValidate::readString("Enter First Name ? : ");
		user.lastName = clsInputValidate::readString("Enter Last Name ? : ");
		user.email = clsInputValidate::readString("Enter Email Address ? : ");
		user.phone = clsInputValidate::readString("Enter Phone Number ? : ");
		user.password = clsInputValidate::readString("Enter Password ? : ");

		user.permissions = _readPermissionToSet();
	}


	static int _readPermissionToSet()
	{

		int permission = 0;

		cout << "Do You Want To Give User Full Access ? :  y/n ? :  ";


		if (clsInputValidate::getUserRespondAsBoolean())
		{
			return permission = clsUser::enPermission::pAll;
		}

		cout << "\n\nDo You To Give User Access To : \n";

		cout << "\nShow List  Clients  ? :  y/n ? : ";

		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pListClients;
		}

		cout << "\nAdd New Client ? :  y/n ? : ";


		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pAddNewClient;
		}

		cout << "\nDelete Client  ? :  y/n ? : ";

		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pDeleteClient;
		}

		cout << "\nUpdate Client  ? :  y/n ? : ";

		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pUpdateClient;
		}


		cout << "\nFind Client  ? :  y/n ? : ";

		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pFindClient;
		}


		cout << "\nTransactions ? :  y/n ? : ";

		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pTransactions;
		}


		cout << "\nManage Users ? :  y/n ? : ";

		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pManageUsers;
		}

		cout << "\nShow Login Register ? :  y/n ? : ";

		if (clsInputValidate::getUserRespondAsBoolean())
		{
			permission += clsUser::enPermission::pLoginRegister;
		}

		return permission;
	}


public:

	static void showUpdateUserScreen() 
	{

		_drawScreenHeader("Update User Screen");

		string username = clsInputValidate::readString("Enter Username  ? :   ");
		
		while (!clsUser::isUserExist(username)) 
		{
			username = clsInputValidate::
				readString("Invalid Username Not Found, Enter AnotherUsername  ? :   ");
		}

		clsUser user = clsUser::find(username);

		_printUserCard(user);

		cout << "Are You Sure You Want To Update This User ? : y/n ? :  ";

		if (clsInputValidate::getUserRespondAsBoolean()) 
		{

			_readUserInfo(user);

			clsUser::enSaveResult saveResult = user.save();

			switch (saveResult)
			{
			case clsUser::enSaveResult::SaveSucceeded:
				cout << "\nUser Updated Successfully :-) \n";
				_printUserCard(user);
				break;

			case clsUser::enSaveResult::SaveFailedEmptyObject:
				cout << "\nError User Not Saved Because It's Empty\n";

				break;
			}

		}
	}
};

