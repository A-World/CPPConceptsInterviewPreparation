// One example for thread synchronization from 
// http://baptiste-wicht.com/posts/2012/03/cp11-concurrency-tutorial-part-2-protect-shared-data.html

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

mutex mtx;

struct Counter {
    int value;

    Counter() : value(0){}

    void increment()
	{
		mtx.lock();
        ++value;
		mtx.unlock();
    }
};

int main(){
    Counter counter;

    std::vector<std::thread> threads;
    for(int i = 0; i < 250; ++i){
        threads.push_back(std::thread([&counter](){
            for(int i = 0; i < 100; ++i){
                counter.increment();
            }
        }));
    }

    for(auto& thread : threads){
        thread.join();
    }

    std::cout << counter.value << std::endl;

    return 0;
}


/*


************************* Output with multiple runs without synchronization ************************************

ashish@ubuntu:~/projects/CPPThread$ ./a.out ;./a.out; ./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out
24981
24831
24856
25000
25000
24896
24943
24930
24872
25000
24919
25000
25000
25000
25000
24971
24894
24952
24892
24946
24800
25000
25000
25000
24942
25000
25000
24113
25000
24828
24913
ashish@ubuntu:~/projects/CPPThread$



*************** Output with   synchronization **************



ashish@ubuntu:~/projects/CPPThread$ ./a.out ;./a.out; ./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out;./a.out
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
25000
ashish@ubuntu:~/projects/CPPThread$
*/
