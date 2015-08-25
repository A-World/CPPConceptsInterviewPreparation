// C++ 11 nullptr

#include <iostream>
#include <vector>
using namespace std;

void foo(int i )
{
    cout << "foo(int) function"<<endl;
}

void foo(char *pc )
{
    cout << "foo(char *) function"<<endl;
}

int main()
{
    cout << "Hello World" <<endl;
    foo(NULL);      // This calls foo(int).
    
    foo(nullptr);
    return 0;
}



/*      Uniform initilization search
 *      1. initlizationList constructor
 *      2. Regular constructor that takes appropriate paramters
 *      3. Aggregate initilizer : similar to struct in C.
 *
 *
 * */


