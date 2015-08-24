/*
    Thread Management

    - Another approach, use a wrapper class, write the thread1.join inside destructor, 
      whenever thread object goes out of scope, it shall call destructor, and t.join() function. 
      This approach uses RAII concept.
    
    - Thread object can be constructed not only with regular function like function_1, 
      but also with any callable object, such as functor or labmda function.
    
    
    Q 1. : if i write t1.join multiple times, what is behaviour
    
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
    std::thread t1 (function_1);    
    
    try
    {
        for (int i = 0 ; i < 100; i++)
            cout << "from main: "  << i << endl;
    }
    catch(...)
    {        
        t1.join();
        cout << "Execption caught"<<endl;
        throw;
    }
    
    cout << "executed main function t1.join()"<<endl;
    t1.join();
    return 0;
} 
