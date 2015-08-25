// C++ 11 Auto

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    cout << "Hello World" <<endl;
    
    std::vector <int >vec = {2,3,4,5};  // Initilizer list

    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
    }
    
    auto  a = 6;
    auto b = 9.6;
    auto c = a;
    
    return 0;
}



/*      Uniform initilization search
 *      1. initlizationList constructor
 *      2. Regular constructor that takes appropriate paramters
 *      3. Aggregate initilizer : similar to struct in C.
 *
 *
 * */


