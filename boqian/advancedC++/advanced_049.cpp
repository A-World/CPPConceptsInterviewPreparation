/*
    Introduction to C++	:
    Video           :   Advanced C++ Virtual Destructor and Smart Destructor

    Example of virutal destructor.

 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dog
{
    public :
    virtual ~Dog() { cout << "Dog destroyed " <<endl; }
    virtual void bark() {}
};

class YellowDog : public Dog
{
    public :
    virtual ~YellowDog() { cout << "YellowDog destroyed " <<endl; }
};

class dogFactory
{
    public :
        static Dog * createYellowDog()
        {
            return new YellowDog();
        }
};

int main()
{
    Dog *pd = dogFactory::createYellowDog();
    delete pd;
    return 0;
}