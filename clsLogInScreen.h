#pragma once
#include "iostream"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"
using namespace std;

class clsLogInScreen : protected clsScreen
{

private:



	static bool _logIn()
	{
		bool logInFailed = false;
		short failedLogInCount = 0;

		do
		{
			if (logInFailed)
			{
				failedLogInCount++;

				system("cls");
				_drawScreenHeader("Log In Screen");

				cout << "\nInvalid username/password!\n";
				cout << "You Have " << (3 - failedLogInCount) << " Trial(s) To Login.\n\n";

				if (failedLogInCount == 3) 
				{
					cout << "\nYou Are Locked After 3 Failed Trial(s)\n\n";
					return false;
				}
			}


			string username = clsInputValidate::readString("Enter Username ? :  ");
			string password = clsInputValidate::readString("Enter Password ? :  ");

			currentUser = clsUser::find(username, password);

			(currentUser.isEmpty()) ? logInFailed = true : logInFailed = false;

		} while (logInFailed);


		currentUser.registerLogin();

		clsMainScreen::showMainScreen();

		return true;
	}


public:

	static bool showLogInScreen()
	{
		system("cls");

		_drawScreenHeader("Log In Screen");

		return _logIn();
	}
};




