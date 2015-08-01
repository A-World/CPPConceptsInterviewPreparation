// Following example shows how mutex can be used to protect std::map shared between two threads.
// AN example from http://en.cppreference.com/w/cpp/thread/mutex

#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <mutex>

using namespace std;
std::map <std::string, std::string> m_map;
std::mutex mtx;

void save(const std::string &url)
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::string result = "fake content";
	
	mtx.lock();
	m_map[url] = result;
	mtx.unlock();	
}

int main()
{
	cout << "Hello World " <<endl;
	
	thread t1(save, "https://Google.com");
	thread t2(save, "https://Facebook.com");
	thread t3(save, "https://Facebook2.com");
	thread t4(save, "https://Facebook3.com");
	thread t5(save, "https://Facebook4.com");
	thread t6(save, "https://Facebook5.com");
	thread t7(save, "https://Facebook6.com");
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	
	for(const auto &pair : m_map)
	{
		cout << pair.first << "  "<< pair.second<<endl;
	}
	
	
}


