#include <iostream>
#include <thread>

void pause(int n)
{
	
	std :: cout << "Inside the pause for thread " << std::this_thread::get_id() <<" \n";
	std::this_thread :: sleep_for (std::chrono::seconds(n));
	std:: cout <<"Pause of " << n<< " seconds" <<std :: endl;
}

int main()
{
	std :: thread t1(pause, 3);
	std :: thread t2(pause, 3);
	std :: thread t3(pause, 3);
	std :: thread t4(pause, 3);
	std :: thread t5(pause, 3);

	std :: cout << "Done Spawning of threads, now waiting for them to join" <<std::endl;
	std :: cout << "Thread ID for thread t1  is " << t1.get_id() << "\n";
	std :: cout << "Thread ID for thread t2  is " << t2.get_id() << "\n";
	std :: cout << "Thread ID for thread t3  is " << t3.get_id() << "\n";
	std :: cout << "Thread ID for thread t4  is " << t4.get_id() << "\n";
	std :: cout << "Thread ID for thread t5  is " << t5.get_id() << "\n";
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	std::cout << "Thread joining completed"<<std::endl;
}

