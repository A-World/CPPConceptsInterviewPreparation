/*
    Introduction to C++		: namespaces and using directive

    C++ keyword using :
    1. using directive : to bring all the namespace memebers into current scope.
        e.g. 
        using namespace std;
    2. using declariotion
        a. Bring one specific namespace member in to current scope.
            e.g. using std::cout;
        b. Bring a member from base class to current class's scope.
        
    
    
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;        // case 1 : global scope
using std::cout;            // case 2.a : global scope

class B
{
    public:
        void f(int a) 
        {
            cout << "From base  a is "<< a <<endl; 
        }
        
        void f() 
        {
            cout << "From base  withou paramters "<< endl; 
        }

};
class D : private B
{
    public :
        void g()
        {
            using namespace std ;   // case 1 : local scope
            cout << "From D:" ;            
        }
        void h()
        {
            using std::cout;        // case 2.a : local scope
            cout << "From D:" ;                    
        }
        
        using B::f;      // case 2.b    , class scope
        /*
            How to differenciate between overloading functions
            void f()
            and void f(int )
            If i want to make only one of them public in derived class.
        */
        
        // using namespace std;         // Illegeal case 1 : claas scope
        // using std::cout;             // Illegeal case 2.a : local scope
};

// using B::f;      // Illegeal case 2.b    , class scope

int main()
{
    cout << "Hello World" <<endl;
    D d ;
    d.f(8);
    d.f();
    return 0;
}
