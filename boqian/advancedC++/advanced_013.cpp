/*
    Introduction to C++	: Koening Lookup
    // This is applicable to namespace and not to class
*/

#include <iostream>
#include <vector>
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

/*      // If you uncomment this function, your code may not compile.
void g( A::X) 
{
    cout << "Inside ::g(X) fucntion"<<endl;
}    
*/


class C 
{
    public :
        struct Y {};
        static void h(Y y ) 
        {
            cout << "Calling C::h(Y) function "<<endl;
        }
};

int main()
{
    cout << "Hello World" <<endl;
    
    // With namespace
    A::X x;
    A::g(x);        // This runs perfect as expected.
    g(x);           // function g will also be searched where its paramter types are defined.
                    // This is called Koening Lookup or Arguement dependent lookup (ADL)
    
    // With Class
    C::Y y ;
    C::h(y);        // Works fine as expected.
    // h(y);           // Illegeal, Koening Lookup applies to namespaces only.
    
    
    return 0;
}
