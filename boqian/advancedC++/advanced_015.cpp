/*
    Introduction to C++	: Koening Lookup
    
	
	Same function declared in multiple namespace
*/

#include <iostream>
#include <string>
using namespace std;
namespace A
{
    struct X {};
    void g(X x) 
    {
        cout << "Inside A::g(X) fucntion"<<endl;
    }    
}


namespace C
{
    void g(A ::X x )
    {
        cout << "Inside C::g(A::X) function "<<endl;
    }
    
    void j()
    {
        A::X x ;
        //g(x);       // So which g(x) will be called, C::g() or A::g()
                    // Code will not compile
    }
}

class B 
{
public:
    void g(A ::X x )
    {
        cout << "Inside B::g(A::X) function "<<endl;
    }
};

class D : public B
{
    public:
    void j()
    {
        A::X x ;
        g(x);       
        // For class, g(X) will be searched first in class scope, if function g is found, it will stop searching.
        // If g(X) is not found in class scope, it will be look up at global scope and then koeing scope.
    }
};


int main()
{
    cout << "Hello World" <<endl;
    C::j();
    
    D d;
    d.j();
    
    return 0;
}
