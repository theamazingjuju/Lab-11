//
//  You already know who it iiiiiiiiis
//  That's right, it's YA BOI, coming at you live and di-rect
//  With some sweet ~LAB #10~ action
//
//  This lab allows a user to translate a number "input" into English text
//  while   0 < input < 1000
//
//  We'll be using the   o m e g a s p i c y   custom class "Lab10.h" to load nearly everything in
//

#include "stdafx.h"
#include "Lab10.h"

int main()
{
	// Variables
	double input;
	string input_as_text;
	bool looping = true;

	// Custom class
	Lab10 myLab;

	// Input loop
	while (looping)
	{
		input = myLab.GetDollarAmount();

		if (input == 0)  // User exits
			looping = false;

		else             // Translate and print
		{
			input_as_text = myLab.Translate(input);
			cout << "\n   ---> " << input_as_text << "\n\n\n\n\n\n";
		}
	}

	return 0;
}

