/*
    Introduction to C++	:
    Video           :   Advanced C++ Duality Of Public Inheritance - Interface & Implementation
    Program  Part 1 :   Public Inheritance : Inheritance Interface only.
    - Inheritance of Interfaces
    - Inheritance of Implementation

    AIM : We can achieve any of them or both of them, so aim is to understand how can we achieve it.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Public Inheritance : Inheritance Interface only.
class dog
{
    public :
    virtual void bark () = 0;
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