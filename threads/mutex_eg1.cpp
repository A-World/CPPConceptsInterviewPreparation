// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block (int n, char c) {
  // critical section (exclusive access to std::cout signaled by locking mtx):
  mtx.lock();
  	std::cout<< "Entry"<<std::endl;
	std::cout << "Value of n is "<<n<<"Value of c is "<<c<<std::endl;
	for(int i = 0; i < n; i ++)
	{
		std::cout<<c;
	}
	std::cout<< "Exit"<<std::endl;
  //for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
  mtx.unlock();
}

int main ()
{
  std::thread th1 (print_block,40,'*');
  std::thread th2 (print_block,100,'$');

  th1.join();
  th2.join();

  return 0;
}

#if 0

#include <iostream>
#include <thread>
#include <mutex>

void common_function(int n, char c)
{
	std::cout<< "Entry"<<std::endl;
	std::cout << "Value of n is "<<n<<"Value of c is "<<c<<std::endl;
	for(int i = 0; i < n; i ++)
	{
		std::cout<<c;
	}
	std::cout<< "Exit"<<std::endl;
}

int main()
{
	std :: thread th1(common_function,40,'#');
	std :: thread th2(common_function,100,'*');	
}

#endif