// An example from  http://www.cplusplus.com/reference/thread/thread/detach/

#include <iostream>
#include <thread>
#include <chrono>

#include <mutex>

// Creat an object of type mutex
std::mutex mtx;

void pause1(int n)
{
	mtx.lock();
	std::this_thread::sleep_for( std::chrono:: seconds(n));
	std::cout<<"Pause of "<< n << " seconds ended" <<std::endl;
	mtx.unlock();
}

void pause(int n)
{
	std::cout << " Inside the function_1 " << std::endl;
}

int main()
{
	std::cout << "Hello World" << std::endl;
	
	std::thread (pause1,5).detach();
	std::thread (pause1,5).detach();
	std::thread (pause1,5).detach();
	std::thread (pause1,5).detach();
	std::thread (pause1,5).detach();
	std::cout << "Done spawning threads.\n";

	std::cout << "(the main thread will now pause for 5 seconds)\n";
	// give the detached threads time to finish (but not guaranteed!):
	pause1(5);
	return 0;	
}

