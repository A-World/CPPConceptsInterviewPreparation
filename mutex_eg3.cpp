#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void print_block (int n, char c) 
{
  // critical section (exclusive access to std::cout signaled by locking mtx):/	mtx.lock();
	for (int i=0; i<n; ++i) 
	{
		std::cout << c; 
	}
	std::cout << '\n';
	mtx.unlock();
}

int main()
{
	cout << "Mutex example 3 :: File name " << __FILE__<<endl;
	
	std::thread th1 (print_block,50,'*');
	std::thread th2 (print_block,50,'$');

	th1.join();
	th2.join();
}

