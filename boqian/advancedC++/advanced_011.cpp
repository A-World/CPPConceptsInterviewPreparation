/*
    Introduction to C++		: namespaces and using directive
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;        // case 1 : global scope
using std::cout;            // case 2.a : global scope


// Following code will not compile Why??

class B
{
    public:
        void f(int a)
        {
            cout << "From base  f(int ) function a is "<< a <<endl;
        }
};
class D : public B
{
    public :
    
        // f(int) is shadowed by f() of class D, this is called name hiding
        // To resolve it, use using directive
    
        using B::f;
        void f()
        {
            cout << "From D: f() function " <<endl;
        }
};

int main()
{
    cout << "Hello World" <<endl;
    D d ;
    d.f(8);
    d.f();
    return 0;
}
