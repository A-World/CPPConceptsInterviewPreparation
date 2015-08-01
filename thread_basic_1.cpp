#include <iostream>
#include <thread>

using namespace std;
/*
1. with different number of arguments
2. with differernt type of the return argurments
*/

// void funcitons
int function_1()
{
	std::cout << "Inside function 1"<<endl;
	return 120;
}
int function_2()
{
	std::cout << "Inside function 2"<<endl;
	return 130;
}

int main()
{
	// You have just created two objects and nothing more than is.
	std:: thread  first(function_1);
	std:: thread  second(function_2);
	
	// If you attempt to run the code with just two thread created with joining them, application shall crash at run time.
	first.join();
	second.join();
	
	
	
}




