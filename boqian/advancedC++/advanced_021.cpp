/*
    Introduction to C++	:
    Video       :   Advanced C++ Define Implicit Type Conversion

    Implicit : On its own
    - In all which cases this type conversion happens

    Categories of type conversions

                                                        Implicit            Explicit
    Standard Type conversion (build in type)                A                   B
    User defined type conversion                            C                   D



    // Cases where Category A conversion happens
    - At the type of declation and initilization of variable
    - Paramter passing
    - Poiter conversion of derived type to base type pointer


*/

#include <iostream>
#include <algorithm>
using namespace std;

class dog
{};

class yellowdog : public dog
{};

void f(int i)
{}

int main()
{
    // Category A : Implicit Standard Type Conversion
    char c  = 'A';
    int i = c;          // integral promotion
    char * pc = 0;      // int to null pointer initilization
    void f (int i);         // declaration

    f(c);        // This is implicit type conversion.

    dog * pd = new yellowdog();

    return 0;
}
