#pragma once

#include <iostream>

using namespace std;

class clsUtil
{

public:

	enum enCharType
	{
		CapitalLetter =1 , SmallLetter=2, MixChars=3, Digit=4, SpecialChar=5
	}; 

	static void Srand()
	{
		//Seeds the random number generator in C++, called only once

		srand((unsigned)time(NULL));
	}
	
	static int RandomNumber(int From, int To) {
		//Function to generate a random number

		//Srand();

		int randnum = rand() % (To - From + 1) + From;
		return randnum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);

		}

		if (CharType == enCharType::CapitalLetter)
			return char(RandomNumber(65, 90));
		else if (CharType == enCharType::SmallLetter)
			return char(RandomNumber(97, 122));
		else if (CharType == enCharType::SpecialChar)
			return char(RandomNumber(33, 47));
		else if (CharType == enCharType::Digit)
			return char(RandomNumber(48, 57));
	
	}

	static string GenerateWord(enCharType CharType, short WordLength)
	{
		string word = "";
		for (short i = 0; i < WordLength; i++)
		{
			word += GetRandomCharacter(CharType);
		}
		return word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string key= "";
		for (short i = 0; i < 4; i++)
		{
			if (i==3)
				key += GenerateWord(CharType, 4);
			else
				key += GenerateWord(CharType,4) + "-";
		}
		return key;
	}

	static void GenerateKeys(int NumberOfKeys, enCharType CharType)
	{
		for (int i = 0; i < NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(int &x, int &y)
	{
		int TempNum;
		TempNum = x;
		x = y;
		y = TempNum;

	}

	static void Swap(double& x, double& y)
	{
		double TempNum;
		TempNum = x;
		x = y;
		y = TempNum;

	}

	static void Swap(string& x, string& y)
	{
		string TempNum;
		TempNum = x;
		x = y;
		y = TempNum;

	}

	static void Swap(clsDate& x, clsDate& y)
	{
		clsDate::SwapDates(x, y);
	}

	static void ShuffleArray(int Arr[100], int len)
	{
		for (int i = 0; i < len; i++)
		{
			Swap(Arr[RandomNumber(1, len) - 1], Arr[RandomNumber(1, len) - 1]);
		}
	}

	static void ShuffleArray(string Arr[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			Swap(Arr[RandomNumber(1, len) - 1], Arr[RandomNumber(1, len) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int Arr[100], int len, int From, int To)
	{
		for (int i = 0; i < len; i++)
			Arr[i] = RandomNumber(From, To);
		
	}

	static void FillArrayWithRandomWords(string Arr[100], int len, enCharType Type, short WordLen)
	{
		for (int i = 0; i < len; i++)
			Arr[i] = GenerateWord(Type, WordLen);
		
	}

	static void FillArrayWithRandomKeys(string Arr[100], int len, enCharType Type)
	{
		for (int i = 0; i < len; i++)
			Arr[i] = GenerateKey(Type);
	}

	static string Tabs(short NumTaps)
	{
		string t = "";
		for (int i = 0; i < NumTaps; i++)
		{
			t += "\t";
		}
		return t;
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		string TextAfterEncryption = "";

		
		for (char charachter : Text)
		{
			TextAfterEncryption += char((int)charachter + EncryptionKey);
		}
		return TextAfterEncryption;
	}

	static string DecryptText(string EncryptedText, short EncryptionKey)
	{
		string text = "";
		for (char charachter : EncryptedText)
		{
			text += char((int)charachter - EncryptionKey);
		}
		return text;
	}


};