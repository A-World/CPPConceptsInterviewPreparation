// One example for thread synchronization from 
// http://baptiste-wicht.com/posts/2012/03/cp11-concurrency-tutorial-part-2-protect-shared-data.html

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;


struct Counter {
    int value;

    Counter() : value(0){}

    void increment(){
        ++value;
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
Output with multiple runs

ashish@ubuntu:~/projects/CPPThread$ rm a.out ;g++ synchro_001.cpp  -std=c++11 -pthread ; ./a.out
25000
ashish@ubuntu:~/projects/CPPThread$ rm a.out ;g++ synchro_001.cpp  -std=c++11 -pthread ; ./a.out
24872
ashish@ubuntu:~/projects/CPPThread$ rm a.out ;g++ synchro_001.cpp  -std=c++11 -pthread ; ./a.out
24912
ashish@ubuntu:~/projects/CPPThread$ rm a.out ;g++ synchro_001.cpp  -std=c++11 -pthread ; ./a.out
24900
ashish@ubuntu:~/projects/CPPThread$ rm a.out ;g++ synchro_001.cpp  -std=c++11 -pthread ; ./a.out
24833
ashish@ubuntu:~/projects/CPPThread$

*/
