#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

enum enNumberingSystems { Decimal = 1, Binary = 2, Hexadecimal = 3, Octal = 4 };

struct stNumberThatWillConverted
{
	int Decimal, Binary, Octal;
	string Hexadecimal;
};

struct stResult
{
	vector <int> nResult;
	vector <string> sResult;
};

struct stConversionInfo
{
	enNumberingSystems ConvertFrom;
	enNumberingSystems ConvertTo;
	stNumberThatWillConverted NumberThatWillConvert;
	stResult Result;
};

void ShowConversionList()
{
	cout << "______________________" << endl;
	cout << setw(5) << "(1) Decimal." << endl;
	cout << setw(5) << "(2) Binary." << endl;
	cout << setw(5) << "(3) Hexadecimal." << endl;
	cout << setw(5) << "(4) Octal." << endl;
	cout << "----------------------" << endl;
}

int ReadChoise()
{
	int Number = 0;

	cin >> Number;

	while (cin.fail() || Number < 1 || Number > 4)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, Enter a valid one : [ 1 : 4 ] \n";
		cin >> Number;
	}
	return  Number;
}

enNumberingSystems TypeOfConversion(string Massage)
{
	cout << setw(5) << "|" << Massage << "|" << endl;

	ShowConversionList();
	int UserCoise = ReadChoise();
	
	return (enNumberingSystems)UserCoise;
}

int ReadValidNumber(string Type)
{
	int Number;

	cout << "Enter a " << Type << " number\n";
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, Enter a valid one :  \n";
		cin >> Number;
	}
	
	return Number;
}

string ReadString(string Type)
{
	string Hexadecimal;

	cout << "Enter a " << Type << " number\n";
	cin >> Hexadecimal;

	return Hexadecimal;
}

stNumberThatWillConverted GetNumberThatWillConverted(stConversionInfo& ConversionInfo)
{
	switch (ConversionInfo.ConvertFrom)
	{
	case Decimal:
		ConversionInfo.NumberThatWillConvert.Decimal = ReadValidNumber("Decimal");
		break;

	case Binary:
		ConversionInfo.NumberThatWillConvert.Binary = ReadValidNumber("Binary");
		break;

	case Hexadecimal:
		ConversionInfo.NumberThatWillConvert.Hexadecimal = ReadString("Hexadecimal");
		break;

	case Octal:
		ConversionInfo.NumberThatWillConvert.Octal = ReadValidNumber("Octal");
		break;
	}

	return ConversionInfo.NumberThatWillConvert;
}

vector <int> StoreNumberInArray(int SourecNumber)
{
	vector <int> Number;
	int remainder = 0;

	if (SourecNumber == 0)
	{
		Number.push_back(0);
		return Number;
	}

	while (SourecNumber > 0)
	{
		remainder = SourecNumber % 10;
		Number.insert(Number.begin(), remainder);
		SourecNumber /= 10;
	}
	return Number;
}

int reStoreNumberInArray(vector <int> & Array)
{
	int Multplier = 1, Sum = 0;

	for (int i = Array.size() - 1;i >= 0; i--)
	{
		Sum += Array[i] * Multplier;
		Multplier *= 10;
	}
	return Sum;
}

vector <string> StoreStringInArray(string Str)
{
	vector <string> String;
	for (char & Letter : Str)
	{
		String.push_back(string(1,Letter));
	}
	return String;
}

int Pow(int Base, int Exponent)
{
	int result = 1;

	for (int i = 1; i <= Exponent; i++)
	{
		result *= Base;
	}
	return result;
}

vector <int> DecimalToBinary(int Number)
{
	vector <int> Binary;
	int Remainder = 0;

	if (Number == 0)
	{
		Binary.push_back(0);
	}
	else
	{
		while (Number > 0)
		{
			Remainder = Number % 2;
			Binary.insert(Binary.begin(), Remainder);
			Number /= 2;
		}
	}
	return Binary;
}

vector <string> DecimalToHexadecimal(int number) 
{
	if (number < 0) 
	{
		cout << "Input number cannot be negative.";
	}

	vector <string> hexadecimal;
	const char hexDigits[] = "0123456789ABCDEF";

	while (number != 0) 
	{
		int remainder = number % 16;
		hexadecimal.insert(hexadecimal.begin(),string(1, hexDigits[remainder]));
		number /= 16;
	}

	return hexadecimal;
}

vector <int> DecimalToOctal(int number)
{
	if (number < 0) 
	{
		cout << "Input number cannot be negative.";
	}

	vector <int> octal;

	while (number != 0) 
	{
		int remainder = number % 8;
		octal.insert(octal.begin(), remainder);
		number /= 8;
	}
	return octal;
}

vector <int> BinaryToDecimal(int BinaryNumber)
{
	vector <int> DecimalNumber;

	int Sum = 0, power = 0;

	while (BinaryNumber != 0)
	{
		int Digit = BinaryNumber % 10;

		Sum += Digit * Pow(2,power);
		power++;
		BinaryNumber /= 10;
	}
	DecimalNumber = StoreNumberInArray(Sum);
	return DecimalNumber;
}

vector <string> BinaryToHexadecimal(int BinaryNumber)
{
	vector <int> Decimal = BinaryToDecimal(BinaryNumber);
	
	return DecimalToHexadecimal(reStoreNumberInArray(Decimal));
}

vector <int> BinaryToOctal(int BinaryNumber)
{
	vector <int> Decimal = BinaryToDecimal(BinaryNumber);
	return DecimalToOctal(reStoreNumberInArray(Decimal));
}

vector <int> HexadecimalToDecimal(string Hexadecimal)
{
	vector <string> Hexa = StoreStringInArray(Hexadecimal);

	vector <int> Decimal;
	int DecimalValue = 0;

	// Convert each hexadecimal digit to decimal value
	for (const string & Digit : Hexa) 
	{
		DecimalValue *= 16;

		if (Digit >= "0" && Digit <= "9")
		{
			DecimalValue += std::stoi(Digit);
		}
		else if (Digit >= "A" && Digit <= "F") 
		{
			DecimalValue += 10 + (Digit[0] - 'A');
		}
		else if (Digit >= "a" && Digit <= "f") 
		{
			DecimalValue += 10 + (Digit[0] - 'a');
		}
	}

	return StoreNumberInArray(DecimalValue);
}

vector <int> HexadecimalToBinary(string Hexadecimal)
{
	vector <int> Decimal = HexadecimalToDecimal(Hexadecimal);
	return DecimalToBinary(reStoreNumberInArray(Decimal));
}

vector <int> HexadecimalToOctal(string Hexadecimal)
{
	vector <int> Decimal = HexadecimalToDecimal(Hexadecimal);
	return DecimalToOctal(reStoreNumberInArray(Decimal));
}

vector <int> OctalToDecimal(int Octalnumber)
{
	vector <int> Octal = StoreNumberInArray(Octalnumber);

	int Sum = 0,Size = Octal.size();
	for (int i = 0; i < Size; i++)
	{
		Sum += (Octal[i] * Pow(8, Size - i - 1));
	}
	return StoreNumberInArray(Sum);
}

vector <int> OctalToBinary(int Octalnumber)
{
	vector <int> Decimal = OctalToDecimal(Octalnumber);
	return DecimalToBinary(reStoreNumberInArray(Decimal));
}

vector <string> OctalToHexadecimal(int Octalnumber)
{
	vector <int> Decimal = OctalToDecimal(Octalnumber);
	return DecimalToHexadecimal(reStoreNumberInArray(Decimal));
}

void PrintIntegerArray(vector <int> & Result)
{
	for (int& Element : Result)
	{
		cout << Element << " ";
	}
	cout << endl;
}

void PrintStringArray(vector <string>& Result)
{
	for (string &Element : Result)
	{
		cout << Element;
	}
	cout << endl;
}

void AutoPrintArray(stConversionInfo ConversionInfo)
{
	if (ConversionInfo.Result.nResult.empty())
	{
		PrintStringArray(ConversionInfo.Result.sResult);
	}
	else
	{
		PrintIntegerArray(ConversionInfo.Result.nResult);
	}
}

stResult GetConverters(stConversionInfo ConversionInfo)
{
	stResult Result;

	// Converting from Decimal 
	switch (ConversionInfo.ConvertFrom)
	{
	case Decimal:
		switch (ConversionInfo.ConvertTo)
		{
		case Decimal:
			Result.nResult = StoreNumberInArray(ConversionInfo.NumberThatWillConvert.Decimal);
			break;
		case Binary:
			Result.nResult = DecimalToBinary(ConversionInfo.NumberThatWillConvert.Decimal);
			break;
		case Hexadecimal:
			Result.sResult = DecimalToHexadecimal(ConversionInfo.NumberThatWillConvert.Decimal);
			break;
		case Octal:
			Result.nResult = DecimalToOctal(ConversionInfo.NumberThatWillConvert.Decimal);
			break;
		}
	}

	// Converting from Binary 
	switch (ConversionInfo.ConvertFrom)
	{
	case Binary:
		switch (ConversionInfo.ConvertTo)
		{
		case Decimal:
			Result.nResult = BinaryToDecimal(ConversionInfo.NumberThatWillConvert.Binary);
			break;
		case Binary:
			Result.nResult = StoreNumberInArray(ConversionInfo.NumberThatWillConvert.Binary);
			break;
		case Hexadecimal:
			Result.sResult = BinaryToHexadecimal(ConversionInfo.NumberThatWillConvert.Binary);
			break;
		case Octal:
			Result.nResult = BinaryToOctal(ConversionInfo.NumberThatWillConvert.Binary);
			break;
		}
	}

	// Converting from Hexadecimal
	switch (ConversionInfo.ConvertFrom)
	{
	case Hexadecimal:
		switch (ConversionInfo.ConvertTo)
		{
		case Decimal:
			Result.nResult = HexadecimalToDecimal(ConversionInfo.NumberThatWillConvert.Hexadecimal);
			break;
		case Binary:
			Result.nResult = HexadecimalToBinary(ConversionInfo.NumberThatWillConvert.Hexadecimal);
			break;
		case Hexadecimal:
			Result.sResult = StoreStringInArray(ConversionInfo.NumberThatWillConvert.Hexadecimal);
			break;
		case Octal:
			Result.nResult = HexadecimalToOctal(ConversionInfo.NumberThatWillConvert.Hexadecimal);
			break;
		}
	}

	// Converting from Hexadecimal
	switch (ConversionInfo.ConvertFrom)
	{
	case Octal:
		switch (ConversionInfo.ConvertTo)
		{
		case Decimal:
			Result.nResult = OctalToDecimal(ConversionInfo.NumberThatWillConvert.Octal);
			break;
		case Binary:
			Result.nResult = OctalToBinary(ConversionInfo.NumberThatWillConvert.Octal);
			break;
		case Hexadecimal:
			Result.sResult = OctalToHexadecimal(ConversionInfo.NumberThatWillConvert.Octal);
			break;
		case Octal:
			Result.nResult = StoreNumberInArray(ConversionInfo.NumberThatWillConvert.Octal);
			break;
		}
	}

	return Result;
}

void NumberingSystemConverter()
{
	char AnotherOperation = 'y';

	while (AnotherOperation == 'y' || AnotherOperation == 'Y')
	{
		stConversionInfo ConversionInfo;

		ConversionInfo.ConvertFrom = TypeOfConversion("Convert From");
		ConversionInfo.ConvertTo = TypeOfConversion("Convert To");
		ConversionInfo.NumberThatWillConvert = GetNumberThatWillConverted(ConversionInfo);
		ConversionInfo.Result = GetConverters(ConversionInfo);
		AutoPrintArray(ConversionInfo);

		cout << "Do you want to do another operation ? [ Y / N ] ";
		cin >> AnotherOperation;
	}
}

int main()
{
	NumberingSystemConverter();

	return 0;
}
