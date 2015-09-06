/*
    Introduction to C++	:
    Video           :   Advanced C++ Code Reuse - Inheritance vs Composition

    CONCLUSION:Composition is more flexiable.
    - Class name shall not reveal the implementation details.
    - If class name is revealing the details, we are loosing the benifits of abstrations.
    - In software engineering good naming is not cosmatic, good naming is critical element of good software design.
    - Names shall be precise and self explainatory.
*/
/*
            ****************************** SUMMARY *************************************
            Code reuse : Composition is better than inheritance.
            1. Less code coupling between reused code and reuser of the code
                a. Child class automatically inherites ALL parent class's public method.
                b. Child class can access parent's protected members.
                    - Inheritance breaks encapsulation.
            2. Dynamic binding
                a. Inheritance is bound at compile time.
                b. Composition can be bound either at compile time or at run time.
            3. Flexible code construct
                Dog             ActivityManager
                BullDog         OutdoorActivityManager
                ShepherdDog     IndoorActivityManager
                ....            .....
            ****************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Code reuse with inheritance.
// here we are using the code reuse for the common activity functions
class dog
{
public :
    // common activity functions of dog e.g. bark(), eat(), sleep().
};

class bulldog : public dog
{
    // Call common activity functions to perform more tasks.
};
class shapherdDog : public dog
{
    // Call common activity functions to perform more tasks.
};


// Code reuse with composition
class ActivityManager
{
    // Common Activities.
};


class Dog
{
    // Some some dog attributes.
};

class BullDog : public Dog
{
    ActivityManager *pActMngr;
    // Call the common activity functions throught pActMngr
};

class ShepherdDog : public Dog
{
    ActivityManager *pActMngr;
    // Call the common activity functions throught pActMngr
};


// For dynamic binding at run time.
class OutdoorActivityManager : public ActivityManager {};
class IndoorActivityManager : public ActivityManager {};

// So the pointer pActMngr, can switch between OutdoorActivityManager and IndoorActivityManager easily.
// Also there can multiple instances of ActivityManager pointers, which can not achieved via inheritance.

int main()
{
    return 0;
}