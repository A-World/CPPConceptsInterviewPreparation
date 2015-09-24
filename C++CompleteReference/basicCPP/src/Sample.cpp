#include "Generic.h"

int sample()
{
	int i;
	cout << "This is output.\n"; // this is a single line comment
	/* you can still use C style comments */
	// input a number using >>
	cout << "Enter a number: ";
	cin >> i;
	// now, output a number using <<
	cout << i << " squared is " << i*i << "\n";
	
	// When ci function expects an integer, and you input some char, it prints nothing, 
	// but exits, the further input is discarded, so how to continue with further correct input reading??

	return 0;
}

// When ci function expects an integer, and you input some char, it prints nothing, 
// but exits, the further input is discarded, so how to continue with further correct input reading??
// Reference : https://developers.google.com/edu/c++/getting-started

int input_correct()
{
	int input_var = 0;
	// Enter the do while loop and stay there until either
	// a non-numeric is entered, or -1 is entered. Note that
	// cin will accept any integer, 4, 40, 400, etc.
	do 
	{
		cout << "Enter a number (-1 = quit): ";
		// The following line accepts input from the keyboard into
		// variable input_var.
		// cin returns false if an input operation fails, that is, if
		// something other than an int (the type of input_var) is entered.
		if (!(cin >> input_var)) 
		{
			cout << "You entered a non-numeric. Exiting..." << endl;
			// You entered a non numeric value, but you want to continue with loop
			cin.clear();
			cin.ignore();
			//break;
			// exit the do while loop
		}else
		if (input_var != -1) 
		{
			cout << "You entered " << input_var << endl;
		}
	} while (input_var != -1);
	
	cout << "All done." << endl;
	
	return 0;
}