/*
    Introduction to C++	:
    Video           :   Advanced C++ Virtual Destructor and Smart Destructor

    Example of smart destructor : Using shared pointers.
 */

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog
{
    public :
    ~Dog() { cout << "Dog destroyed " <<endl; }
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
        static shared_ptr<Dog > createYellowDog()
        {
            return shared_ptr<YellowDog> (new YellowDog());
        }
};

int main()
{
    shared_ptr <Dog> pd = dogFactory::createYellowDog();
    return 0;
}