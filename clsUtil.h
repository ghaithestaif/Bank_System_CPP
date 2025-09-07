#pragma once
#include "clsDate.h"
#include <iostream>
using namespace std;

class clsUtil
{
public: 

	enum enCharType { CapitalLetters = 1, SmallLetters, Digits, MixChar, SpecialCharacters };

	static void sRand() 
	{
		srand((unsigned)time(NULL));
	}


	static int randomNumber(int from, int to)
	{
		int randomNum = rand() % (to - from + 1) + from;

		return randomNum;
	}

	static char getRandomCharacter(enCharType charType) 
	{
		if (charType == MixChar)
			charType = (enCharType) randomNumber(1, 3);

		switch (charType) 
		{

		case CapitalLetters:
			return char(randomNumber(65, 90));

		case SmallLetters:
			return char(randomNumber(97, 122));

		case Digits:
			return char(randomNumber(48, 57));

		case SpecialCharacters:
			return char(randomNumber(32, 47));

		default :
			return char(randomNumber(65, 90));

		}
	}

	static string generateWord(short length, enCharType charType)
	{
		string word = "";

		for (int i = 1; i <= length; i++) 
		{
			word += getRandomCharacter(charType);
		}

		return word;
	}


	static string generateKey(enCharType charType) 
	{
		string key = "";

		key = generateWord(4, charType) + "-";
		key += generateWord(4, charType) + "-";
		key += generateWord(4, charType) + "-";
		key += generateWord(4, charType);

		return key;
	}

	static void generateKeys(short numberOfKeys, enCharType charType) 
	{
		for (short i = 1; i <= numberOfKeys; i++) 
		{
			cout << "Key [" << i << "]  : ";
			cout << generateKey(charType) << endl;
		}
	}

	static void swap(int &a, int &b)
	{
		int temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void swap(double& a, double& b)
	{
		double temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void swap(bool& a, bool& b)
	{
		bool temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void swap(char& a, char& b)
	{
		char temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void swap(string& a, string& b)
	{
		string temp;

		temp = a;
		a = b;
		b = temp;
	}

	static void swap(clsDate& a, clsDate& b) 
	{
		clsDate::swapDates(a, b);
	}

	static void shuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++) 
		{
			swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
		}
	}


	static void shuffleArray(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
		}
	}


	static void fillArrayWithRandomNumbers(int arr[], int arrLength, int from, int to)
	{
		for (int i = 0; i < arrLength; i++) 
		{
			arr[i] = randomNumber(from, to);
		}
	}

	static void fillArrayWithRandomWords(string arr[], int arrLength, enCharType charType, short wordLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = generateWord(wordLength, charType);
		}
	}

	static void fillArrayWithRandomKeys(string arr[], int arrLength, enCharType charType)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = generateKey(charType);
		}
	}

	static string tabs(short numberOfTabs) 
	{
		string t = "";

		for (int i = 1; i < numberOfTabs; i++) 
		{
			t = t + "\t";
		}

		return t;
	}

	static string encryptText(string text, short encryptionKey = 2) 
	{
		for (short i = 0; i < text.length(); i++) 
		{
			text[i] = text[i] + encryptionKey;
		}

		return text;
	}


	static string decryptText(string text, short decryptionKey = 2)
	{
		for (short i = 0; i < text.length(); i++)
		{
			text[i] = text[i] - decryptionKey;
		}

		return text;
	}


	static string numberToText(int number)
	{
		if (number == 0)
			return "";

		if (number >= 1 && number <= 19)
		{
			string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six",
							"Seven", "Eight", "Nine", "Ten", "Eleven",
							"Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
							"Eighteen", "Nineteen" };

			return arr[number] + " ";
		}


		if (number >= 20 && number <= 99)
		{
			string arr[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

			return arr[number / 10] + numberToText(number % 10);
		}


		if (number >= 100 && number <= 199)
		{
			return "One Hundred " + numberToText(number % 100);
		}


		if (number >= 200 && number <= 999)
		{
			return numberToText((number / 100)) + " Hundreds " + numberToText(number % 100);
		}


		if (number >= 1000 && number <= 1999)
		{
			return "One Thousand " + numberToText(number % 1000);
		}


		//if (number >= 2000 && number <= 9999)
		//{
		//	return numberToText((number / 1000)) + " Thousands " + numberToText(number % 1000);
		//}


		if (number >= 2000 && number <= 999999)
		{
			return numberToText((number / 1000)) + " Thousands " + numberToText(number % 1000);
		}


		if (number >= 1000000 && number <= 1999999)
		{
			return " One Million " + numberToText(number % 1000000);
		}

		if (number >= 2000000 && number <= 199999999)
		{
			return numberToText((number / 1000000)) + " Millions " + numberToText(number % 1000000);
		}
	
		if (number >= 1000000000 <= 1999999999)
		{
			return " One Billion " + numberToText(number % 1000000000);
		}

		else 
		{
			return numberToText(number / 1000000000) + numberToText(number % 1000000000);
		}
	}


};


