/*
    Introduction to C++	:
    Video       :   Advanced C++ Maintain is-a Relation for Public Inheritance
    Program  Part 4 : Public, protected and private inheritance - introduction

    - public inheritance : IS A relationship.
    - A derived class should be able to do everything the base class can do.
    - Never override non virtual function.
    - Never provide default values for virtual functions.
        - As per type of the pointer/reference the default value is taken.
    - Force inheritance of shadowed functions
*/


/*
        Summary
        1. Precise defination of the classes.
        2. Don't override non virtual functions.
        3. Don't override default paramters values for virtual functions.
        4. Force inheritance of shadowed functions.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class dog
{
    public :
    void bark (int age) { cout << " dog :: I am "<< age << " years old"<<endl;  }
    virtual void bark(string msg = "just a ") { cout << "dog :: I am "<< msg<< " dog "<<endl; }
};

class yellowdog : public dog
{
    public :
    using dog :: bark;
    virtual void bark(string msg = "a yellow") {
    cout << "yellowdog :: I am "<< msg << " dog "<<endl; }
};

int main()
{
    yellowdog *py  = new yellowdog();
    py->bark();
    py->bark(5);

    // py will search in  derived class, when it find bark function with string signature,compiler will stop searching for bark in base class.
    // So base class bark(int age) is shadowed in derived class, so use using derective.

    return 0;
}