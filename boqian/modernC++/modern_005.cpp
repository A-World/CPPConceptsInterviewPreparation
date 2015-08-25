// C++ 11 delegating constructor

#include <iostream>
#include <vector>
using namespace std;

class dog
{
    int a = 10;
    public:
        dog()
        {
            
        }
        dog(int a) : dog()  // dog() function shall be called at start only.
        {
            // other defunation
        }
};


int main()
{
    cout << "Hello World" <<endl;
    return 0;
}



/*      Uniform initilization search
 *      1. initlizationList constructor
 *      2. Regular constructor that takes appropriate paramters
 *      3. Aggregate initilizer : similar to struct in C.
 *
 *
 * */


