#pragma once
#include "clsDate.h"

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Num, int From, int To)
	{
		return (Num >= From && Num <= To);
	}
	
	static bool IsNumberBetween(double Num, double From, double To)
	{
		return (Num >= From && Num <= To);
	}
	
	static bool IsDateBetween(clsDate date, clsDate start, clsDate end)
	{
		return (clsDate::IsDate1AfterDate2(date, start) || clsDate::IsDate1EqualDate2(date, start))
			&& 
			(clsDate::IsDate1BeforeDate2(date, end) || clsDate::IsDate1EqualDate2(date, start));
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int n;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			cin >> n;
		}
		return n;

	}

	static int ReadIntNumberBetween(int from, int to, string ErrorMessage)
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, from, to))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double from, double to, string ErrorMessage)
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, from, to)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}

};