#include <iostream>
#include <thread>
#include <string>

using namespace std;
/*
1. with different number of arguments
2. with differernt type of the return argurments
*/

class C
{
	int a;
};

// void funcitons
int function_1(int a, int b, string c, C e)
{
	std::cout << "Inside function 1"<<endl;
	std :: cout << "a = " << a << " b = " << b << "String entered is " << c <<std::endl;
	return 120;
}
int function_2(string s)
{
	std :: cout << "String entererd is " << s << endl;
	std::cout << "Inside function 2"<<endl;
	return 130;
}

int main()
{
	// You have just created two objects and nothing more than is.
	C a;
	std:: thread  first(function_1, 10,20, "Thread first", a);
	std:: thread  second(function_2, "Ashish Modi thread second" );
	
	// If you attempt to run the code with just two thread created with joining them, application shall crash at run time.
	first.join();
	second.join();
	
	
	
}




