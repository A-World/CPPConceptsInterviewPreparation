// C++ 11 delete keyword 

#include <iostream>
#include <vector>
using namespace std;

class dog
{
    public :
        dog (int age) {}                                // This shall allow dog a = {4};
        dog (double) = delete;                          // This shall not allow dog b = {3.0}
        dog & operator  = (const dog &) = delete;       // This shall not allow a = b;
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