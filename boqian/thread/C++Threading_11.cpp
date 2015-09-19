
/*
	Video 2 : Thread management
	- Program when main thread throws exceptions, you need to catch it, and do thread.join(), else your program will crash. Approach is, RAII, resource allocation is initilization.

	Need to fix comnpilation error.	
*/

#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
	std::cout << "Beauty is skin deep "<<endl;
}

class Wrapper
{
public :
	Wrapper()
	{
		new t1(function_1);
	}
	~Wrapper()
	{
		t1->join();
		delete this->t1;
	}
private :
	std::thread *t1;

};


int main()
{
     cout << "Hello World" <<endl;
     Wrapper w1;

     try {
	for (int i = 0 ; i < 100 ; i ++) 
		cout << "From Main : " << i << endl;
     }catch(...)
     {
	throw;
     }
     return 0;

}



