#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h"
using namespace std;

class clsCurrency
{

private :


	enum enMode {EmptyMode, UpdateMode};

	enMode _mode;
	string _country;
	string _currencyName;
	string _currencyCode;
	float  _rate;


	static clsCurrency _convertLineToCurrencyObject(string line, string separator = "#//#")
	{
		vector <string> vCurrencyData = clsString::split(line, separator);


		return clsCurrency(UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}


	static clsCurrency _getEmptyObject() 
	{
		return clsCurrency(EmptyMode, "", "", "", 0);
	}

	static string _convertObjectToLinRecord(clsCurrency currency, string separator = "#//#")
	{
		string line = "";

		line += currency.getCountry() + separator;
		line += currency.getCurrencyCode() + separator;
		line += currency.getCurrencyName() + separator;
		line += to_string(currency.getRate()) + separator;

		return line;
	}


	static vector <clsCurrency> _loadCurrencyDataFromFile() 
	{
		vector <clsCurrency> vCurrencyList;

		fstream myFile;

		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open()) 
		{
			string line = "";

			while (getline(myFile, line))
			{
				clsCurrency currency = _convertLineToCurrencyObject(line);

				vCurrencyList.push_back(currency);
			}

			myFile.close();
		}

		return vCurrencyList;
	}


	void _saveCurrencyDataToFile(vector <clsCurrency> vCurrencyList)
	{
		fstream myFile;

		myFile.open("Currencies.txt", ios::out);

		if (myFile.is_open())
		{
			string line = "";

			for (clsCurrency& currency : vCurrencyList) 
			{
				line = _convertObjectToLinRecord(currency);

				myFile << line << endl;
			}


			myFile.close();
		}

	}


	void _update() 
	{
		vector <clsCurrency> vCurrencyList = _loadCurrencyDataFromFile();

		for (clsCurrency& currency : vCurrencyList)
		{
			if (currency._currencyCode == _currencyCode)
			{
				currency = *this;
				break;
			}
		}

		_saveCurrencyDataToFile(vCurrencyList);
	}

public :

	clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate) 
	{
		_mode = mode;
		_country = country;
		_currencyName = currencyName;
		_currencyCode = currencyCode;
		_rate = rate;
	}


	bool isEmpty() 
	{
		return (_mode == EmptyMode);
	}

	string getCountry() 
	{
		return _country;
	}

	string getCurrencyCode() 
	{
		return _currencyCode;
	}

	string getCurrencyName()
	{
		return _currencyName;
	}


	void updateRate(float newRate) 
	{
		_rate = newRate;

		_update();
	}

	float getRate() 
	{
		return _rate;
	}

	static clsCurrency  findByCode(string currencyCode)
	{

		currencyCode = clsString::upperCaseString(currencyCode);

		fstream myFile;

		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open())
		{
			string line = "";

			while (getline(myFile, line))
			{
			
				clsCurrency currency = _convertLineToCurrencyObject(line);

				if (currency._currencyCode == currencyCode) 
				{
					myFile.close();
					return currency;
				}
			}

			myFile.close();
		}

		return _getEmptyObject();
	}


	static clsCurrency  findByCountry(string country)
	{

		country = clsString::upperCaseString(country);

		fstream myFile;

		myFile.open("Currencies.txt", ios::in);

		if (myFile.is_open())
		{
			string line = "";

			while (getline(myFile, line))
			{

				clsCurrency currency = _convertLineToCurrencyObject(line);

				if (clsString::upperCaseString(currency._country) == country)
				{
					myFile.close();
					return currency;
				}
			}

			myFile.close();
		}

		return _getEmptyObject();
	}


	static bool isCurrencyExist(string currencyCode) 
	{
		return !clsCurrency::findByCode(currencyCode).isEmpty();
	}

	static vector <clsCurrency> getCurrenciesList() 
	{
		return clsCurrency::_loadCurrencyDataFromFile();
	}

	
	float convertFromUSD(float amount, clsCurrency currencyTo) 
	{
		return amount * currencyTo._rate; 
	}

	float convertToUSD(float amount)
	{
		return amount / _rate;
	}

	float convertToOtherCurrency(float amount, clsCurrency currencyTo) 
	{
		float amountInUSD = convertToUSD(amount);

		if (currencyTo.getCurrencyCode() == "USD") 
		{
			return amountInUSD;
		}

		return convertFromUSD(amountInUSD, currencyTo);
	}
};

