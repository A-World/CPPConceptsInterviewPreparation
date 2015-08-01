// Aim : To understand functionality of thread::join() and thread::joinable() functions.
// What is difference between this two functions

/*

	thread::join 
	- forces the current thread to wait for the other one 
	- (in this case, the main thread has to wait for the thread t1 to finish)

	thread::joinable()
	- returns true or false value, 
	- if thread is joinable, then returns true.
	- else false

*/
#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
	std::cout << "Function 1 " << std::endl;
}

int main()
{
	cout << "Hello World" << endl;
	
	std :: thread t1 (function_1);
	
	if(t1.joinable())
	{
		t1.join();
	}
	
	if(t1.joinable())
	{
		cout << "T1 is still joinable" <<endl;
	}
	else
	{
		cout << "T1 is not joinable now" << endl;
	}
	
}