/*
    Introduction to C++	: Koening Lookup    : Name hiding	

    Case where Koening Lookup is not applicable
    
*/

#include <iostream>
#include <string>
using namespace std;

namespace A
{
    struct X {};
    
    void g(X) 
    {
        cout << "A::g(X) function "<<endl;
    }
    void g()
    {
        cout << "A::g() function "<<endl;
    }
}

int main()
{

    std::cout << "Hi\n" ;   // This calls std::operator <<
    // This is equivalent as follows
    std::operator << (std::cout, "Hi\n");
    // The statemenet 1 works because of Koening Lookup
    
    A::X x ;
    g(x)      ; // Koening Lookup happens
    // g();    // Error // Koening Lookup not Applicable
    
    
    return 0;
}
