/*
    Thread Management : Associating thread with functor along with paramters, move function

    - Another approach, use a wrapper class, write the thread1.join inside destructor,
      whenever thread object goes out of scope, it shall call destructor, and t.join() function.
      This approach uses RAII concept.

    - Thread object can be constructed not only with regular function like function_1,
      but also with any callable object, such as functor or labmda function.

    - To pass string s as paramters to thread creation, pass it as additional paramters.

    - A paramter to thread is always pass by value.

    - In following example, child thread and parent thread sharing same memeory, which is string s.

    - std::move shall move the string s from main thread to child thread.

    - A thread can not be copied, to change the ownership of thread from one thread to another, use std::move(t1).

	- To know, which thread is executing the current block of code, use following
        std:: this_thread::get_id() //function

    Q 1. : if i write t1.join multiple times, what is behaviour

*/


#include <iostream>
#include <string>
#include <thread>
using namespace std;

int main()
{
    // Over subsription -  How many maximun thread are supported by hardware.    
    cout << "Maximum CPU thread supported are " << std::thread::hardware_concurrency()<<endl;
    return 0;
}
