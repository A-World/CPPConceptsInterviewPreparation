/*
    Introduction to C++	:
    Video           :   Advanced C++ Virtual Constructor - Clone() Function

    - Advantages of clone funtions
    - co varient return type virtual functions.
    - It allows the overridden virtual function to have a different return type, as long as its return type is derived from base class's return type.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dog
{
public :
    virtual Dog *  clone ( )
    {
        return new Dog (*this );
    }
};

class YellowDog : public Dog
{
public :
    virtual YellowDog *  clone ( )
    {
        return new YellowDog (*this );
    }
};

void foo (Dog *d)           // d is yellow dog
{
    //Dog * c = new Dog(*d);  // c is dog, so c is not identical copy of d
    Dog *c = d->clone();
}

int main()
{
    YellowDog d;
    foo (&d);

    return 0;
}