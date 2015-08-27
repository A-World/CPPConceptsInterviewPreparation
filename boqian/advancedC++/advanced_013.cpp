/*
    Introduction to C++	: Koening Lookup
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

int main()
{
    cout << "Hello World" <<endl;
    
    A::X x;
    A::g(x);        // This runs perfect as expected.
    g(x);           // function g will also be searched where its paramter types are defined.
                    // This is called Koening Lookup or Arguement dependent lookup (ADL)
    
    return 0;
}
