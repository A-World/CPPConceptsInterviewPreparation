// C++ 11 for each

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    cout << "Hello World" <<endl;
    
    std::vector <int >vec = {2,3,4,5};  // Initilizer list

    for(int i : vec)        // This will work with any class vec that has begin() and end() function.
    {
        cout << i << endl;
    }
    
    for(auto &i : vec)        // This will work with any class vec that has begin() and end() function.
    {
        i++;        // Increment each member of vec by 1.
    }

    for(auto i : vec)        // This will work with any class vec that has begin() and end() function.
    {
        cout << i << endl;
    }

    return 0;
}



/*      Uniform initilization search
 *      1. initlizationList constructor
 *      2. Regular constructor that takes appropriate paramters
 *      3. Aggregate initilizer : similar to struct in C.
 *
 *
 * */


