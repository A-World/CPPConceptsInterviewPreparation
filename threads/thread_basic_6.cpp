// Refer http://baptiste-wicht.com/posts/2012/03/cpp11-concurrency-part1-start-threads.html

#include <thread>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::thread> threads;

    for(int i = 0; i < 5; ++i)
	{
        threads.push_back(std::thread([]()
			{
				std::cout << "Hello from thread " << std::this_thread::get_id() << std::endl;
			}
		));
    }

    for(auto& thread : threads)
	{
        thread.join();
    }

    return 0;
}