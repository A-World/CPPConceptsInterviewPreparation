// Uniform initilization

#include <iostream>
using namespace std;

class dog
{

    // If int age is private, it will not work.
    public : 
        int age;

        //  dog(int a)
        //  {
        //     age = a;
        //  }
};

int main()
{
    cout << "Hello World" <<endl;

    dog d1 {3};

    return 0;
}



/*      Uniform initilization search
 *      1. initlizationList constructor
 *      2. Regular constructor that takes appropriate paramters
 *      3. Aggregate initilizer : similar to struct in C.
 *
 *
 * */


