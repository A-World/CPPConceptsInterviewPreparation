/*
    Introduction to C++	:
    Video       :   Advanced C++ Inheritance - Public, Protected, and Private
    Program  Part 1 : Public, protected and private inheritance - introduction

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class B {};

class D_priv : private B {};
class D_prot : protected B {};
class D_pub : public B {};

/*
    Access control rules
    1. None of derived class can access anything that is private in B.
    2. D_pub inherites public member of B as public and protected member of B as protected.
    3. D_prot inherites public member of B as protected and protected member of B as protected.
    4. D_priv inherites public member of B as private and protected member of B as private.

    Casting : // Need to understand it again. What exactly author wants to convey.
    1. Anyone can cast a D_pub * to B*. D_pub is a special kind of B.
    2. D_priv's members and friends can cast a D_priv * to B*.
    3. D_prot's members and friends and children can cast a D_priv * to B*.

*/


int main()
{
    // As states above, write code to access different different members in different case, to prove above mentioned point.


    // Reader is supposed to write code by himself/herself
    return 0;
}


