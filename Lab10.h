#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;

class Lab10
{
private:
	// Data structure
	struct myNumber
	{
		// Different types
		double dub;
		string str;
		string as_english;

		// Properties
		int len;
		bool is_zero;

		// Default Constructor (empty)
		myNumber()
		{

		}

		// Overloaded Constructor
		myNumber(double input)
		{
			dub = input;
			str = Dub_to_String(dub);

			while (str.length() < 6)
				str = "0" + str;
			len = str.length();

			if (dub == 0)
				is_zero = true;
			else
				is_zero = false;
		}
	};

	// Data
	myNumber dollars;
	string huns; string tens; string ones; string decs;

	// Conversion Functions
	static string Dub_to_String(double dub)
	{
		string myStr;
		ostringstream myStringStream;

		myStringStream << fixed;
		myStringStream << setprecision(2);

		myStringStream << dub;
		myStr = myStringStream.str();

		return myStr;
	}
	static string Nat_to_Text(char digit, string type = "Natural")
	{
		string my_return;
		int intDigit = (int)digit - 48;

		if (type == "Natural")
		{
			switch (intDigit)
			{
			case 0:
				my_return = "Zero";
				break;
			case 1:
				my_return = "One";
				break;
			case 2:
				my_return = "Two";
				break;
			case 3:
				my_return = "Three";
				break;
			case 4:
				my_return = "Four";
				break;
			case 5:
				my_return = "Five";
				break;
			case 6:
				my_return = "Six";
				break;
			case 7:
				my_return = "Seven";
				break;
			case 8:
				my_return = "Eight";
				break;
			case 9:
				my_return = "Nine";
				break;
			}
		}
		if (type == "Teen")
		{
			switch (intDigit)
			{
			case 0:
				my_return = "Ten";
				break;
			case 1:
				my_return = "Eleven";
				break;
			case 2:
				my_return = "Twelve";
				break;
			case 3:
				my_return = "Thirteen";
				break;
			case 4:
				my_return = "Fourteen";
				break;
			case 5:
				my_return = "Fifteen";
				break;
			case 6:
				my_return = "Sixteen";
				break;
			case 7:
				my_return = "Seventeen";
				break;
			case 8:
				my_return = "Eighteen";
				break;
			case 9:
				my_return = "Nineteen";
				break;

			}
		}
		if (type == "Tens")
		{
			switch (intDigit)
			{
			case 0:
				my_return = "Zero";
				break;
			case 1:
				my_return = "Teen";
				break;
			case 2:
				my_return = "Twenty";
				break;
			case 3:
				my_return = "Thirty";
				break;
			case 4:
				my_return = "Fourty";
				break;
			case 5:
				my_return = "Fifty";
				break;
			case 6:
				my_return = "Sixty";
				break;
			case 7:
				my_return = "Seventy";
				break;
			case 8:
				my_return = "Eighty";
				break;
			case 9:
				my_return = "Ninety";
				break;
			}
		}

		return my_return;
	}

	// Process Functions
	string get_Huns()
	{
		char huns_ = dollars.str[0];
		return Nat_to_Text(huns_);
	}
	string get_Tens()
	{
		char _tens = dollars.str[1];	
		return Nat_to_Text(_tens, "Tens");
	}
	string get_Ones()
	{
		char _ones = dollars.str[2];

		if (get_Tens() == "Teen")
			return Nat_to_Text(_ones, "Teen");
		else
			return Nat_to_Text(_ones);
	}
	string get_Decs()
	{
		string trimmed = dollars.str;
		trimmed.erase(0, 4);
		return trimmed;
	}
	string arrange_text(string _hunds, string _tens, string _ones, string _decs)
	{
		string myText = "";

		if (_hunds != "Zero")
			myText += _hunds + " Hundred ";

		if ((_tens != "Zero") && (_tens != "Teen"))
			myText += _tens + " ";

		if (_ones != "Zero")
			myText += _ones + " ";

		if (_decs != "00")
			if (dollars.dub >= 1)
				myText += "and " + _decs + "/100";
			else
				myText += _decs + "/100";

		return myText;
	}

public:
	// Functions to call in main
	double GetDollarAmount()
	{
		double input; double output;
		cout << "-----------------------------------------------------------\n";
		cout << " - Enter a dollar amount in the hundreds. Ex: $403.25\n";
		cout << " - Enter 0 to close the program\n";
		cout << "-----------------------------------------------------------\n";

		// Loop until the user inputs a double value:   0 < x < 1000
		bool looping = true;
		while (looping)
		{
			looping = false;

			cout << "   > $ ";
			cin >> input;

			// Exceeds bounds error
			if (input >= 1000)
			{
				cout << "\n   ---> Error: input >=  maximum of 1000\n\n\n\n\n\n";
				looping = true;
			}

			// Below bounds error
			if (input < 0)
			{
				cout << "\n   ---> Error: input < minimum of 0\n\n\n\n\n\n";
				looping = true;
			}

			// If input is acceptable
			if ((input >= 0.0) && (input < 1000))
			{
				output = input;
			}

			// If input is unnaceptable for some other reason
			else
			{
				cout << "\n   ---> Error: This input cannot be accepted for some reason, try again.\n\n\n\n\n\n";
				looping = true;
			}
		}

		return input;
	}
	string Translate(double input)
	{
		//Update the dollars struct
		dollars = myNumber(input);

		// Get/Set the different pieces of translated text
		decs = get_Decs();
		ones = get_Ones();
		tens = get_Tens();
		huns = get_Huns();

		// Arrange and return the pieces
		dollars.as_english = arrange_text(huns, tens, ones, decs);
		return dollars.as_english;
	}

	// Constructor (empty)
	Lab10()
	{}
};