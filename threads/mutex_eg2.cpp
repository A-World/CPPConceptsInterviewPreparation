class thread
{
	public :
		id,
		native_handle_type,  // Contains implementation specific information about the thread.

	thread() constructors
	- default constructor
	- initilization constructor
	- copy constructor
	- move constructor
	~thread() destructor
	operator= 
	get_id()
	joinable
	join
	detach
	swap
	native_handle()
	static hardware_concurrency()
	
}




#include<iostream>
using namespace std;

void funciton1()
{
	cout << "Function 1 " <<endl;
}

void funciton2()
{
	cout << "Function 2 " << endl;
}

int main()
{
	thread t1 (funciton2);
	thread t2;

	
	cout << "Hello World"<<endl;
}

