// Multi threading : introduction
/*
    Multi threading                             multi processing
    - shared memoery                        - IPC mechanishm such as pipe,
    - fast to start
    - low overhead                          - more overhead
                                            - requires many operating system tools for protection.                            
    - Communication via shared memeory 
      is more faster than IPC channels
    - Better performance than 
      multiprocessing.
    - It is difficult to implement
    - Can not run on distributed systems.   - Multiprocess program can be easily distributed over sytems.

    
    - If two threads are sharing some resources, in below example stdout, the thread that owns that resource, 
      here main thread, should live as long as the other thread is accessing that resource.
    - You can join or detach a thread only once.
*/


#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
    cout << "Beauty is only skin-deep"<<endl;
}

int main()
{
    std::thread t1 (function_1);    // At this point t1 starts running
    // t1.join();       // main thread waits for t1 to finish.
    t1.detach();        // t1 runs freely on its own, t1 become daemon process 
                        // C++ run time library will be responsible for reclaim the resources used by t1 daemon.
    
    if(t1.joinable())
        t1.join();
    return 0;
} 



/*
    Main thread run so fast that its execution is completed before the t1 execution, hence no message is printed out.


*/