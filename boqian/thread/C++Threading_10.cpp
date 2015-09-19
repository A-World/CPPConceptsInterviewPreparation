
/*
	Video 2 : Thread management
	- Program when main thread throws exceptions, you need to catch it, and do thread.join(), else your program will crash. Approach is, programmer has to handle exception, programmer has to take care for exceptions.
	
*/

#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
	std::cout << "Beauty is skin deep "<<endl;
}


int main()
{
     cout << "Hello World" <<endl;
     std::thread t1 (function_1);

     try {
	for (int i = 0 ; i < 100 ; i ++) 
		cout << "From Main : " << i << endl;
     }catch(...)
     {
   	t1.join();
	throw;
     }

     t1.join();
 
     return 0;

}



