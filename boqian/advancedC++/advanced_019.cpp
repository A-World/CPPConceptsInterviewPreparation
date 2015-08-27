/*
    Introduction to C++	: Koening Lookup    : Need : Theoretic reason
    
    Interface of class :
    
    Defination of class : A class describes a set of data, along with functions that operates on that data.
*/

#include <iostream>
#include <string>
using namespace std;

namespace A
{
/*
    In following example,
    
    function h() and operator <<  are also part of interface of class C, as per defination of class.
*/

    class C
    {
        public :
            void f()  {}
            void g()  {}
    };
    void h( C ) {}
    ostream & operator << (ostream & , const C&);
}

void j (A::C)
{

}

/**
        Important desing principle
        1. Functions that operates on class C and in a same namespace with C are part of C's interface.
        2. Functions that are part of C's interface should be in the same namespace as C.

*/


int main()

{
    A::C c;
    c.f();
    h(c);

    return 0;
}
