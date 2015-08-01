// I am not currently able to understand the outout. I shall revisit this soon.

// Aim : To study thread::detach funciton
#include <iostream>
#include <thread>
using namespace std;

/*

Detaches the thread represented by the object from the calling thread, allowing them to execute independently from each other.
Both threads continue without blocking nor synchronizing in any way. Note that when either one ends execution, 
its resources are released.
After a call to this function, the thread object becomes non-joinable and can be destroyed safely.	


// I was expected as

Hello World
Inside the function_1
Inside the function_2

or 
Hello World
Inside the function_2
Inside the function_1

Acutual output is 
Hello World

?? How come i get this output??

*/

void function_1()
{
	cout << " Inside the function_1 " << endl;
}
void function_2()
{
	cout << " Inside the function_2 " << endl;
}

int main()
{
	cout << "Hello World" <<endl;

	std :: thread t1(function_1);
	std :: thread t2(function_2);
	//t1.join();
	//t2.join();
	t1.detach();
	t2.detach();
	
}


