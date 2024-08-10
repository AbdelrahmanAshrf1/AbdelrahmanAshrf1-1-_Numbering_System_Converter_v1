#pragma once
#include <iostream>

using namespace std;

// Math Functions
namespace mf
{
	// Note: Perfect Number is = Sum(all divisors) 28 = 1 + 2 + 4 + 7 + 14
	bool isPerfectNumber(int Number)
	{
		int Sum = 0;
		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}
		return Number == Sum;
	}

	// Add all the numbers digits 1234 => 1+2+3+4 = 10
	int SumOfDigits(int Number)
	{
		int Sum = 0, Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}
		return Sum;
	}

	// 1234 => 4321
	int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}
		return Number2;
	}

	bool IsPalindromeNumber(int Number)
	{
		return Number == ReverseNumber(Number);
	}

	// Add how many times that the number is found 
	int CountDigitFrequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0, Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			if (DigitToCheck == Remainder)
			{
				FreqCount++;
			}
		}
		return FreqCount;
	}

	bool GuessPassword(string OriginalPassword)
	{
		string word = "";
		int Counter = 0;
		cout << "\n";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					Counter++;
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					cout << "Trial [" << Counter << "] : " << word
						<< endl;
					if (word == OriginalPassword)
					{
						cout << "\nPassword is " << word << "\n";
						cout << "Found after " << Counter << "Trial(s)\n";
							return true;
					}
					word = "";
				}
			}
		}
		return false;
	}

	string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	int SumArray(int arr[100], int arrLength)
	{
		int Sum = 0;
		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}

	float ArrayAverage(int arr[100], int arrLength)
	{
		return (float)SumArray(arr, arrLength) / arrLength;
	}

	void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}
	}

	float MyABS(float Number)
	{
		if (Number > 0)
			return Number;
		else
			return Number * -1;
	}

	float GetFractionPart(float Number)
	{
		return Number - int(Number);
	}

	int MyRound(float Number)
	{
		int IntPart;
		IntPart = int(Number);
		float FractionsPart = GetFractionPart(Number);
		if (FractionsPart >= .5)
		{
			if (Number > 0)
			{
				return ++IntPart;
			}
			else
			{
				return --IntPart;
			}
		}
		else
		{
			return IntPart;
		}
	}

	int MyFloor(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}

	int MyCeil(float Number)
	{
		if (abs(GetFractionPart(Number)) > 0)
		{
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		}
		else
		{
			return int(Number);
		}
	}

	int MySqrt(float Number)
	{
		return pow(Number, 0.5);
	}
}