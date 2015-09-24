#include <iostream>
#include <thread>

// Add logic for thread syncronization
// Here is single function pause, which is being accessed by  multiple thread.
// Our aim is to use the mutex with only 10 thread and try to synchronize, or lock the critical area.
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
	std :: thread t4(pause, 5);
	std :: thread t5(pause, 5);
	std :: thread t6(pause, 5);
	std :: thread t7(pause, 5);
	std :: thread t8(pause, 5);
	std :: thread t9(pause, 5);
	std :: thread t10(pause, 5);

	std :: cout << "Done Spawning of threads, now waiting for them to join" <<std::endl;
	std :: cout << "Thread ID for thread t1  is " << t1.get_id() << "\n";
	std :: cout << "Thread ID for thread t2  is " << t2.get_id() << "\n";
	std :: cout << "Thread ID for thread t3  is " << t3.get_id() << "\n";
	std :: cout << "Thread ID for thread t4  is " << t4.get_id() << "\n";
	std :: cout << "Thread ID for thread t5  is " << t5.get_id() << "\n";
	std :: cout << "Thread ID for thread t6  is " << t6.get_id() << "\n";
	std :: cout << "Thread ID for thread t7  is " << t7.get_id() << "\n";
	std :: cout << "Thread ID for thread t8  is " << t8.get_id() << "\n";
	std :: cout << "Thread ID for thread t9  is " << t9.get_id() << "\n";
	std :: cout << "Thread ID for thread t10  is " << t10.get_id() << "\n";

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	std::cout << "Thread joining completed"<<std::endl;
}