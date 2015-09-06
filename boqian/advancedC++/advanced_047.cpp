/*
    Introduction to C++	:
    Video           :   Advanced C++ Virtual Function in Constructor or Destructor

    Calling Virtual function in Constructor or Destructor
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Dog
{
    public :
        Dog () { cout << "Dog born."<<endl;  bark(); }      // As YellowDog object is not yet contructed, so it will call bark of Dog, Here virtual behaviour of dog is not applicable.
        virtual void bark() { cout << "I am just a dog." <<endl; }
        void seeCat() { bark(); }
        ~Dog(){  bark(); }
};

class YellowDog : public Dog 
{
    public :
        YellowDog () { cout << "yellow Dog is born."<<endl; bark(); }
        void bark() { cout << "I am yellow dog." <<endl; }
        ~YellowDog(){  bark(); }
};

int main()
{

    YellowDog yd;
    //yd.seeCat();
    return 0;
}