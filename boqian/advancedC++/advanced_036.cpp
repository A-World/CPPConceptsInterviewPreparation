/*
    Introduction to C++	:
    Video       :   Advanced C++ Maintain is-a Relation for Public Inheritance
    Program  Part 1 : Public, protected and private inheritance - introduction

    - public inheritance : IS A relationship.
    - A derived class should be able to do everything the base class can do.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class bird { };
class flyable : public bird {  public :  void fly()    { }  };
class penguin : public bird {};

//          Design Principle
//    A derived class should be able to do everything the base class can do.
//    - In this example we achieved our design principle by creating new class for flyable birds.

int main()
{
    return 0;
}