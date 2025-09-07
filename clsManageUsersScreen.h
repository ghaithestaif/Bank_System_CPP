#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private :

	enum enManageUsersMenuOptions { eListUsers = 1, eAddNewUser, eDeleteUser, eUpdateUser, eFindUser, eMainMenu };

	static short  _readManageUsersMenuOption() 
	{
		short choice;

		cout << left << setw(37) << "" << "Choose What Do You Want To Do [1 To 6] ? :  ";
		choice = clsInputValidate::readIntNumberBetween(1, 6, "Enter Number Between 1 And 6 ? : ");

		return choice;
	}

	static void _goBackToManageUserMenu() 
	{
		cout << "\n\n";
		cout << left << setw(8) << "" << "Perss Any Key To Go Back To Manage Users Menu.";
		system("pause > 0");
		showManageUsersMenu();
	}

	static void _showListUsersScreen() 
	{
		//cout << "List Users Screen Will Be Here.";
		clsListUsersScreen::showUsersList();
	}

	static void _showAddNewUserScreen()
	{
		//cout << "Add New User Screen Will Be Here.";
		clsAddNewUserScreen::showAddNewUserScreen();
	}

	static void _showDeleteUserScreen()
	{
		//cout << "Delete User Screen Will Be Here.";
		clsDeleteUserScreen::showDeleteUserScreen();
	}

	static void _showUpdateUserScreen()
	{
		//cout << "Update User Screen Will Be Here.";
		clsUpdateUserScreen::showUpdateUserScreen();
	}

	static void _showFindUserScreen()
	{
		//cout << "Find User Screen Will Be Here.";
		clsFindUserScreen::showFindUserScreen();
	}



	static void _performManageUsersMenuOptions(enManageUsersMenuOptions choice)
	{

		switch (choice) 
		{
		case eListUsers:
			system("cls");
			_showListUsersScreen();
			_goBackToManageUserMenu();
			break;

		case eAddNewUser:
			system("cls");
			_showAddNewUserScreen();
			_goBackToManageUserMenu();
			break;


		case eDeleteUser:
			system("cls");
			_showDeleteUserScreen();
			_goBackToManageUserMenu();
			break;


		case eUpdateUser:
			system("cls");
			_showUpdateUserScreen();
			_goBackToManageUserMenu();
			break;


		case eFindUser:
			system("cls");
			_showFindUserScreen();
			_goBackToManageUserMenu();
			break;


		case eMainMenu:
			break;
	
		}
	}

public :

	static void showManageUsersMenu() 
	{
		system("cls");


		if (!checkAccessRights(clsUser::pManageUsers))
		{
			return;
		}

		_drawScreenHeader("Manage Users Screen");
		
		cout << left << setw(37) << "" << "=======================================================\n";
		cout << left << setw(37) << "" << "\t\t\tManage Users Menu \n";
		cout << left << setw(37) << "" << "=======================================================\n";

		cout << left << setw(37) << "" << "[1] List Users. \n";
		cout << left << setw(37) << "" << "[2] Add New User. \n";
		cout << left << setw(37) << "" << "[3] Delete User. \n";
		cout << left << setw(37) << "" << "[4] Update User. \n";
		cout << left << setw(37) << "" << "[5] Find User. \n";
		cout << left << setw(37) << "" << "[6] Main Menu. \n";

		cout << left << setw(37) << "" << "=======================================================\n";
		
		_performManageUsersMenuOptions((enManageUsersMenuOptions) _readManageUsersMenuOption());

	}

};

