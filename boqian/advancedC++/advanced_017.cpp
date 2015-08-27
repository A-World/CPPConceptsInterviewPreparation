/*
    Introduction to C++	: Koening Lookup    : Name hiding	
*/

#include <iostream>
#include <string>
using namespace std;
namespace A
{

    struct X {};
    void g(X) 
    {
        cout << "Inside A::g() fucntion"<<endl;
    }    
    
    namespace C
    {
        void g()
        {
            cout << "Inside C::g() fucntion"<<endl;           
        }
        void j()
        {
            //using A::g;
            X x ;
            g(x);
        }
    }
}

int main()
{
    A::C::j();
    return 0;
}
