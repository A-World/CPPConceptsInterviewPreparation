/*
    Thread Management : Associating thread with functor

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

class Fctor
{
    public :
        void operator () () 
        {
            for(int i = 0 ; i > -100 ; i--)
            {
                cout << "from T1 "<<i<<endl;
            }
        }
};

int main()
{
//    Fctor fct;
//    std::thread t1 (fct);
    
    /*  Following code does not compile, why??   */
    //std::thread t1 (Fctor());
    
    std::thread t1 ((Fctor()));
    /*
        It has beecome declaration, 
        - with return type as std:: thread,
        - function name t1
        - function t1 argument as   pointer to another function, which takes no paramters and returns a fctor.
        
        Solution is to add another pair of paranthesis.
        std::thread t2 ((Fctor()));
    */
    
    
    
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
