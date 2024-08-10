#pragma once
#include <iostream>
#include "MathFunctions.h"

using namespace std;
using namespace mf;

// Other Functions of
namespace of
{
	// Note: Prime number can only divide on one and on itself.
	bool CheckPrime(int Number)
	{
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return false;
		}
		return true;
	}

	void PrintDigitsInReversedOrder(int Number)
	{
		int Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}

	void PrintDigits(int Number)
	{
		int Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}

	void PrintWordsFromAAAtoZZZ()
	{
		cout << "\n";
		string word = "";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					cout << word << endl;
					word = "";
				}
			}
			cout << "\n____________________________\n";
		}
	}

	void PrintStringArray(string arr[100], int arrLength)
	{
		cout << "\nArray elements:\n\n";
		for (int i = 0; i < arrLength; i++)
		{
			cout << "Array[" << i << "] : ";
			cout << arr[i] << "\n";
		}
		cout << "\n";
	}

	void PrintArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	int TimesRepeated(int Number, int arr[100], int arrLength)
	{
		int count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
			{
				count++;
			}
		}
		return count;
	}

	void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
	{
		cout << "\nEnter number of elements:\n";
		cin >> arrLength;
		for (int i = 0; i < arrLength; i++)
			arr[i] = mf::RandomNumber(1, 100);
	}

	int MaxNumberInArray(int arr[100], int arrLength)
	{
		int Max = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}
		return Max;
	}

	int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = 0;
		Min = arr[0];
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}

	void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}

	void SwapNumbers(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			SwapNumbers(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[arrLength - 1 - i];
	}
	
	bool IsPalindromeArray(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] != arr[Length - i - 1])
			{
				return false;
			}
		};
		return true;
	}

	int ArryOddCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 != 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	int ArryEvenCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 == 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	int ArryPositiveCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] >= 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	int ArryNegativeCount(int arr[100], int arrLength)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < 0)
			{
				Counter++;
			}
		}
		return Counter;
	}
}