// C++ 11 Override keyword for virtual function
// C++ 11 final keyword 

/*
    final : 
    
    class dog final     // No class can be derived from dog
    {};
    
    class dog 
    {
        virtual void bark() final {} // No class can override bark.
    }
*/


#include <iostream>
#include <vector>
using namespace std;

class dog
{
    public:
        virtual void A(int ) {}
        virtual void B() const {}
        void C() {}
};
class yellowdog : public dog
{
    public:
        virtual void A(int ) override {}         
        virtual void B() const override  {}
        void C() {}    
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


