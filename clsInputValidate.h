#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"

class clsInputValidate
{

public : 

	static short isNumberBetween(short number, short from, short to) 
	{
		if (number >= from && number <= to)
			return true;

		return false;
	}

	static int isNumberBetween(int number, int from, int to)
	{
		if (number >= from && number <= to)
			return true;

		return false;
	}

	static float isNumberBetween(float number, float from, float to)
	{
		if (number >= from && number <= to)
			return true;

		return false;
	}


	static double isNumberBetween(double number, double from, double to)
	{
		if (number >= from && number <= to)
			return true;

		return false;
	}

	static short isDateBetween(clsDate date, clsDate from, clsDate to)
	{
		if (date.isDateAfterDate2(from) || date.isDateEqualDate2(from)
			&&
			date.isDateBeforeDate2(to) || date.isDateEqualDate2(to))
			return true;

		if (date.isDateBeforeDate2(from) || date.isDateEqualDate2(from)
			&&
			date.isDateAfterDate2(to) || date.isDateEqualDate2(to))
			return true;

		return false;
	}

	static short isDateBetween2(clsDate date, clsDate from , clsDate to) 
	{
		if (from.isDateAfterDate2(to))
			clsDate::swapDates(from, to);

		if (date.compareDates(from) == clsDate::Before
			||
			date.compareDates(to) == clsDate::After
			)
			return false;

		return true;
	}


	static int readIntNumber(string errorMessage = "Invalid Number, Enter Again")
	{
		int number;

		while (!(cin >> number)) 
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << errorMessage << endl;
		}

		return number;
	}


	static double readDoubleNumber(string errorMessage = "Invalid Number, Enter Again")
	{
		double number;

		while (!(cin >> number))
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << errorMessage << endl;
		}

		return number;
	}


	static int readIntNumberBetween(int from, int to, string errorMessage = "Not Within The Range, Enter Again")
	{
		int number = readIntNumber();

		while (!isNumberBetween(number, from, to)) 
		{
			cout << errorMessage << endl;
			number = readIntNumber();
		}

		return number;
	}

	static double readDoubleNumberBetween(double from, double to, string errorMessage = "Not Within The Range, Enter Again")
	{
		double number = readDoubleNumber();

		while (!isNumberBetween(number, from, to))
		{
			cout << errorMessage << endl;
			number = readDoubleNumber();
		}

		return number;
	}

	static bool isValidDate(clsDate date) 
	{
		return date.isValid();
	}

	static string readString(string message = "")
	{
		string text;

		cout << message;

		getline(cin >> ws, text);

		return text;
	}

	static bool readYesOrNO(string errorMessage = "Invalid Answer ,  [Y or N] ? :  ")
	{
		char answer;
		cin >> answer;

		while (toupper(answer) != 'Y' && toupper(answer) != 'N') 
		{
			cout << errorMessage;

			cin >> answer;
		}

		return (toupper(answer) == 'Y') ? true : false;
	}

	static bool getUserRespondAsBoolean()
	{
		return readYesOrNO();
	}
};

