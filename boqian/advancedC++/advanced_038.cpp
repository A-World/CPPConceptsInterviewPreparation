/*
    Introduction to C++	:
    Video       :   Advanced C++ Maintain is-a Relation for Public Inheritance
    Program  Part 3 : Public, protected and private inheritance - introduction

    - public inheritance : IS A relationship.
    - A derived class should be able to do everything the base class can do.
    - Never override non virtual function.
    - Never provide default values for virtual functions.
        - As per type of the pointer/reference the default value is taken.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class dog
{
    public :
    virtual void bark(string msg = "just a ") { cout << "dog :: I am "<< msg<< " dog "<<endl; }
};

class yellowdog : public dog
{
    public :
    virtual void bark(string msg = "a yellow") {
    cout << "Google"<< endl;
    cout << "yellowdog :: I am "<< msg << " dog "<<endl; }
};

int main()
{
    yellowdog *py  = new yellowdog();
    py->bark();

    // Although virtual function behaviour is same, but detault paramter is taken from pointer type.
    dog *pd = py;
    pd->bark();
    return 0;
}