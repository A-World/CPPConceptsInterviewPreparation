/*
    Introduction to C++	:
    Video           :   Advanced C++ Duality Of Public Inheritance - Interface & Implementation
    Program  Part 1 :   Public Inheritance : Inheritance Interface + Implementation.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Public Inheritance : Inheritance Interface + Implementation.
class dog
{
    public :
    virtual void bark () = 0;
    void run () { cout << "I am running "<<endl;}   // This is non virtual method, so it shall not be overriden,
    // This method also contains implemenation.
};

class yellowdog : public dog
{
public :
    virtual void bark() { cout << "yellowdog :: I am yellow dog "<<endl;   }
};

int main()
{
    return 0;
}