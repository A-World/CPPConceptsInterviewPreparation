/*
    Introduction to C++	:
    Video           :   Advanced C++ Multiple Inheritance - Devil or Angel

    Interface Segregation Principle : Multiple inheritance has essential role to play.
    - Split large interfaces into smaller and more specific ones so that clients only need to know about the methods that are of interest to them.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Engineer
{
    public :
    // ... 40 APIs
};

class Son
{
    public :
    // ... 50 APIs

};

// Andy - very complicated persons, can do lot of things, can provide lots of services.
class Andy : public Engineer, Son
{
    public :
    // ... 500 APIs

};

// With the help of Interface Segregation Principle, we are making Adny much simpler person to deal with.

int main()
{

    return 0;
}