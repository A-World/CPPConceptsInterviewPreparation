/*
    Thread Management : Associating thread with functor along with paramters

    - Another approach, use a wrapper class, write the thread1.join inside destructor, 
      whenever thread object goes out of scope, it shall call destructor, and t.join() function. 
      This approach uses RAII concept.
    
    - Thread object can be constructed not only with regular function like function_1, 
      but also with any callable object, such as functor or labmda function.
    
    - To pass string s as paramters to thread creation, pass it as additional paramters.
    
    - A paramter to thread is always pass by value.
    
    Q 1. : if i write t1.join multiple times, what is behaviour
    
*/


#include <iostream>
#include <string>
#include <thread>

using namespace std;

void function_1()
{
    cout << "Beauty is only skin-deep"<<endl;
}

class Fctor
{
    public :
        void operator () (string msg) 
        {
            cout << "T1 says " <<msg<<endl;
        }
};

int main()
{

    string s = "where there is no trust, there is no love";
    // To pass string s as paramters to thread creation, pass it as additional paramters.
    
    std::thread t1 ((Fctor()), s);
    try
    {
        cout << "from main: "  << s << endl;
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
