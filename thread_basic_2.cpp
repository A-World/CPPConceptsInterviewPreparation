#include <iostream>
#include <thread>

// Add logic for thread syncronization
// Here is single function pause, which is being accessed by  multiple thread.
// Our aim is to use the mutex with only 3 thread and try to synchronize, or lock the critical area.
#include <mutex>

// Creat an object of type mutex
std::mutex mtx;

void pause(int n)
{
	mtx.lock();
	std :: cout << "Inside the pause for thread " << std::this_thread::get_id() <<" \n";
	std::this_thread :: sleep_for (std::chrono::seconds(n));
	std:: cout <<"Pause of " << n<< " seconds" <<std :: endl;
	mtx.unlock();
}

int main()
{
// Check with different different values of the time  in seconds.
	std :: thread t1(pause, 5);
	std :: thread t2(pause, 5);
	std :: thread t3(pause, 5);

	std :: cout << "Done Spawning of threads, now waiting for them to join" <<std::endl;
	std :: cout << "Thread ID for thread t1  is " << t1.get_id() << "\n";
	std :: cout << "Thread ID for thread t2  is " << t2.get_id() << "\n";
	std :: cout << "Thread ID for thread t3  is " << t3.get_id() << "\n";

	t1.join();
	t2.join();
	t3.join();
	std::cout << "Thread joining completed"<<std::endl;
}

