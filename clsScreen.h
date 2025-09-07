#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;


class clsScreen  
{



protected :

	static void _drawScreenHeader(string title, string subtitle = "") 
	{
		cout << "\n\t\t\t\t\t__________________________________________________\n";
		cout << "\n\t\t\t\t\t               " << title;
		if (subtitle != "") 
		{
			cout << "\n\t\t\t\t\t                    " << subtitle;
		}
		cout << "\n\t\t\t\t\t__________________________________________________\n\n";	
		cout << "\t\t\t\t\tUser:\t" << currentUser.username;
		cout << "\n\t\t\t\t\tDate:\t" << clsDate::dateToString(clsDate()) << endl << endl;

	}

	static bool checkAccessRights(clsUser::enPermission permission)
	{
	
		if (!currentUser.checkAccessPermission(permission))
		{
			cout << "\n\t\t\t\t\t__________________________________________________\n";
			cout << "\n\t\t\t\t\t\tAccess Denied! Contact Your Admin.\n";
			cout << "\n\t\t\t\t\t__________________________________________________\n\n";


			return false;
		}

		else 
		{
			return true;
		}
	}
};

