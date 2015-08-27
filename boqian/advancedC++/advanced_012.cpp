/*
    Introduction to C++		: Anonymous namespaces 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
void g()
{
    cout << "Inside global :: g()"<<endl;
}
namespace       // This will be of file scope
{
    void g()
    {
        cout << "Inside namespace :: g()"<<endl;
    }
    void h()    // this function is of file scope, same as static void h()
    {
        std:: cout << "h()"<<endl; 
        g();        // This will be of namespace.
    }

}

int main()
{
    cout << "Hello World" <<endl;
    // g();     // This flashes error, call to g() is ambugious.
    h();
    
    return 0;
}
