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
    
    Q 1. : if i write t1.join multiple times, what is behaviour
    
*/


#include <iostream>
#include <string>
#include <thread>

using namespace std;

class Fctor
{
    public :
        void operator () (string msg) 
        {
            cout << "T1 says " <<msg<<endl;
            msg = "Trust is the mother of deceit";
        }
};

int main()
{

    string s = "where there is no trust, there is no love";    
    std::thread t1 ((Fctor()), std::move(s));   // After move(s), the s becomes empty.
    std::thread t2 = std::move(t1);     // After execution of this, t1 becomes empty.
    
    cout << "from main: "  << s << endl;
    t2.join();
    

    return 0;
} 
