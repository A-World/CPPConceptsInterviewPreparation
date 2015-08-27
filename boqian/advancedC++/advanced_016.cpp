/*
    Introduction to C++	: Koening Lookup    : Name hiding	
*/

#include <iostream>
#include <string>
using namespace std;
namespace A
{
    void g(int ) 
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
            using A::g;
            g(8);
        }
    }
}

int main()
{
    A::C::j();
    return 0;
}
