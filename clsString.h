#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private :

	string _value;
	

	static char toUpperCase(char letter)
	{
		return (letter >= 'a' && letter <= 'z') ? letter -= 32 : letter;
	}


	static char toLowerCase(char letter)
	{
		return (letter >= 'A' && letter <= 'Z') ? letter += 32 : letter;
	}


	static bool isLowerCase(char letter)
	{
		return (letter >= 'a' && letter <= 'z');
	}


	static bool isUpperCase(char letter)
	{
		return (letter >= 'A' && letter <= 'Z');
	}


	static char invertLetter(char letter) 
	{
		return (isLowerCase(letter)) ? toUpperCase(letter) : toLowerCase(letter);
	}


	enum enWhatToCount { SmallLetters = 1, CapitalLetters, All };


	static short countLetters(string text, enWhatToCount whatToCount = enWhatToCount::All)
	{
		if (whatToCount == enWhatToCount::All)
		{
			return text.length();
		}

		short counter = 0;


		for (int i = 0; i < text.length(); i++)
		{
			if (isUpperCase(text[i]) && whatToCount == enWhatToCount::CapitalLetters)
			{
				counter++;
			}

			if (isLowerCase(text[i]) && whatToCount == enWhatToCount::SmallLetters)
			{
				counter++;
			}
		}


		return counter;
	}

	
public : 

	clsString() 
	{
		_value = "";
	}

	clsString(string value) 
	{
		_value = value;
	}

	void setValue(string value) 
	{
		_value = value;
	}

	string getValue() 
	{
		return _value;
	}


	__declspec(property(get = getValue, put = setValue)) string value;

	static short Length(string text) 
	{
		return text.length();
	}


	short Length() 
	{
		return _value.length();
	}


	//static short  customLength(const char *str) 
	//{
	//	short counter = 0;

	//	while (*str != '\0') 
	//	{
	//		counter++;

	//		str++;
	//	}

	//	return counter;
	//}


	static string toUpperCaseFirstLetterOfEachWord(string text) 
	{
		bool isFirstLetter = "true";

		for (int i = 0; i < text.length(); i++) 
		{
			if (text[i] != ' ' && isFirstLetter)
				text[i] = toupper(text[i]);

			isFirstLetter = (text[i] == ' ') ? true : false;
		}

		return text;
	}

	void toUpperCaseFirstLetterOfEachWord() 
	{
		_value = toUpperCaseFirstLetterOfEachWord(_value);
	}


	static string upperCaseString(string text) 
	{
		for (int i = 0; i < text.length(); i++) 
		{
			text[i] = toUpperCase(text[i]);
		}

		return text;
	}


	void upperCaseString() 
	{
		_value = upperCaseString(_value);
	}

	static string lowerCaseString(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = toLowerCase(text[i]);
		}

		return text;
	}


	void lowerCaseString()
	{
		_value = lowerCaseString(_value);
	}


	static string invertAllString(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = invertLetter(text[i]);
		}

		return text;
	}


	void invertAllString()
	{
		_value = invertAllString(_value);
	}


	static short countLetters(string text) 
	{
		return countLetters(text, enWhatToCount::All);
	}

	short countLetters() 
	{
		return countLetters(_value, enWhatToCount::All);
	}


	static short countCapitalLetters(string text)
	{
		return countLetters(text, enWhatToCount::CapitalLetters);
	}

	short countCapitalLetters()
	{
		return countLetters(_value, enWhatToCount::CapitalLetters);
	}

	static short countSmallLetters(string text)
	{
		return countLetters(text, enWhatToCount::SmallLetters);
	}

	short countSmallLetters()
	{
		return countLetters(_value, enWhatToCount::SmallLetters);
	}
	

	static short countSpecificLetter(string text, char letter, bool matchCase = true) 
	{
		short counter = 0; 

		for (int i = 0; i < text.length(); i++) 
		{
			if (matchCase) 
			{
				if (letter == text[i])
					counter++;
			}

			else 
			{
				if (toLowerCase(letter) == toLowerCase(text[i]))
					counter++;
			}
		}

		return counter;
	}

	short countSpecificLetter(char letter, bool matchCase = true) 
	{
		return  countSpecificLetter(_value, letter, matchCase);
	}

	static bool isVowel(char letter) 
	{
		letter = toLowerCase(letter);

		return ((letter == 'a') || (letter == 'e') || (letter == 'i') ||
			(letter == 'o') || (letter == 'u'));
	}


	static short countVowels(string text)
	{
		short counter = 0;

		for (int i = 0; i < text.length(); i++)
		{
			if (isVowel(text[i]))
				counter++;
		}

		return counter;
	}


	short countVowels() 
	{
		return countVowels(_value);
	}


	static string subString(string text, short start, short end) 
	{
		if (start < 0 || start > end || start > text.length())
			return "";

		if (end > text.length())
			end = text.length();


		string subText = "";

		for (int i = start; i < end; i++) 
		{
			subText += text[i];
		}

		return subText;
	}
	

	string subString(short start, short end) 
	{
		return subString(_value, start, end);
	}


	static string eraseString(string text, short start, short end) 
	{
		string words = "";

		if (start < 0 || start > end || start > text.length())
			return "";

		if (end > text.length())
			end = text.length();
		
		words = subString(text, 0, start) + subString(text, end, text.length());

		return words;
	}

	string eraseString(short start, short end)
	{
		return eraseString(_value, start, end);
	}

	static vector <string> split(string text, string delimiter) 
	{
		vector <string> vText; 

		string word = "";
		short pos = 0;

		while ((pos = text.find(delimiter)) != string::npos)
		{
			word = subString(text, 0, pos);

			/*if (word != "")*/
				vText.push_back(word);

			//text.erase( 0, pos + delimiter.length());

			text = eraseString(text, 0, pos + delimiter.length());
		}

		if (text != "")
			vText.push_back(text);

		return vText;
	}


	vector <string>  split(string delimiter) 
	{
		return split(_value, delimiter);
	}

	static string joinString(vector<string> &vText, string delimiter) 
	{
		string text = "";

		for (string data : vText) 
		{
			text += data + delimiter;
		}

	      //subString(text, text.length() - delimiter.length());
		 return subString(text, 0, text.length() - delimiter.length());
		 //return text.substr(0, text.length() - delimiter.length());

	}

	static string joinString(string arr[], short length, string delimiter)
	{
		string text = "";

		for (short i = 0; i < length; i++) 
		{
			text += arr[i] + delimiter;
		}

		//subString(text, text.length() - delimiter.length());
		return subString(text, 0, text.length() - delimiter.length());

		//return text.substr(0, text.length() - delimiter.length());
	}

	
	static string trimLeft(string text) 
	{
		for (int i = 0; i < text.length(); i++) 
		{
			if (text[i] != ' ')
				return text.substr(i, text.length());
		}

		return text;
	}

	void trimLeft() 
	{
		_value = trimLeft(_value);
	}


	static string trimRight(string text)
	{
		for (int i = text.length() - 1; i >= 0; i--)
		{
			if (text[i] != ' ')
				return text.substr(0, i + 1);
		}

		return text;
	}

	void trimRight()
	{
		_value = trimRight(_value);
	}
	

	static string trim(string text)
	{
		return trimLeft(trimRight(text));
	}

	void trim() 
	{
		_value = trim(_value);
	}


	static short countWords(string text) 
	{
		short pos = 0;
		short counter = 0; 

		string delimiter = " ";
		string word = "";

		while ((pos = text.find(delimiter)) != string::npos) 
		{
			word = text.substr(0, pos);

			if (word != "")
				counter++;

			text.erase(0, pos + delimiter.length());
		}

		if (text != "")
			counter++;

		return counter;
	}

	short countWords() 
	{
		return countWords(_value);
	}
	

	static string replaceWord(string text, string stringToReplace, string replaceTo, bool matchCase = true)
	{
		vector <string> vText = split(text, " ");

		for (string &line : vText)
		{
			if (matchCase) 
			{
				if (line == stringToReplace)
				{
					line = replaceTo;
					break;
				}
			}

			else 
			{

				if (upperCaseString(line) == upperCaseString(stringToReplace))
				{
					line = replaceTo;
					break;
				}
			}
		}

		return joinString(vText, " ");
	}


	void replaceWord(string stringToReplace, string replaceTo, bool matchCase = true)
	{
		_value = replaceWord(_value, stringToReplace, replaceTo, matchCase);
	}

	
	static string removePunctuations(string text)
	{
		string words = "";

		for (short i = 0; i < text.length(); i++) 
		{
			if (!ispunct(text[i]))
				words += text[i];

		}

		return words;
	}


	void removePunctuations() 
	{
		_value = removePunctuations(_value);
	}

	
};

