// An example from  http://stackoverflow.com/questions/4989451/mutex-example-tutorial


#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx ;

int i = 0;

void function1()
{
	mtx.lock ();
	i++;
	cout << i <<endl;
	mtx.unlock();	
}

int main()
{
	cout << "Hello World" <<endl;
	
	std::thread man1(function1);
	std::thread man2(function1);
	std::thread man3(function1);
	
	man1.join();
	man2.join();
	man3.join();
	return 0;
}

