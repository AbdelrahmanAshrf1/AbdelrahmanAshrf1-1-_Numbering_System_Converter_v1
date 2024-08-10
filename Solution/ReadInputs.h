#pragma once
#include <iostream>
#include <string>

using namespace std;

// read inputs "ri"
namespace ri
{
	int ReadPositiveNumber(string Message)
	{
		int Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;
		} while (Number <= 0);
		return Number;
	}

	string ReadPassword(string Massage)
	{
		string Password;

		cout << Massage << endl;
		cin >> Password;

		return Password;
	}

	string ReadText(string Massage)
	{
		string Text;

		cout << Massage << endl;
		getline(cin, Text);

		return Text;
	}

	void ReadArray(int arr[100], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;

		cout << "\nEnter array elements: \n";

		for (int i = 0; i < arrLength; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			cin >> arr[i];
		}
		cout << endl;
	}

	int ReadValidNumber()
	{
		int Number = 0;

		cout << "Please enter a number?\n";
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a valid one : \n";
			cin >> Number;
		}

		return  Number;
	}
}