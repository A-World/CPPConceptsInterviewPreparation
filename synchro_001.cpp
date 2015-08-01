// One example for thread synchronization from 
// http://baptiste-wicht.com/posts/2012/03/cp11-concurrency-tutorial-part-2-protect-shared-data.html

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

struct Counter
{
	int value;
	Counter() : value(0) {}
	void increament()
	{
		value++;
	}
};


int main()
{
	cout << "Hello World" <<endl;
	
	Counter counter  ;
	vector <thread> threads;
	for(int i = 0 ; i < 5 ; i ++ )
	{
	
	threads.push_back(  std::thread( [&counter]()
	   {
            for(int i = 0; i < 100; ++i)
			{
                counter.increament();
            }
       }));	
	}

	for(auto& thread : threads)
	{
		// Thread Join for each thread.
        thread.join();
    }

    std::cout << counter.value << std::endl;	
}

