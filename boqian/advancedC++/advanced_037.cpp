/*
    Introduction to C++	:
    Video       :   Advanced C++ Maintain is-a Relation for Public Inheritance
    Program  Part 2 : Public, protected and private inheritance - introduction

    - public inheritance : IS A relationship.
    - A derived class should be able to do everything the base class can do.
    - Never override non virtual function.
    - Example 2
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class dog
{
    public :
        void bark() { cout << "dog :: I am just a dog "<<endl; }
};

class yellowdog : public dog
{
    public :
        void bark() { cout << "yellowdog :: I am a yellow dog "<<endl; }
};

int main()
{
    yellowdog *py  = new yellowdog();
    py->bark();

    dog *pd = py;
    pd->bark();

    return 0;
}