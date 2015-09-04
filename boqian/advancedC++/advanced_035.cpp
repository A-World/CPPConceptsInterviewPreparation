/*
    Introduction to C++	:
    Video       :   Advanced C++ Inheritance - Public, Protected, and Private
    Program  Part 3 : Public, protected and private inheritance - introduction

    - private inheritance : HAS A relationship. (similar to composition)

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ring
{
    public :
    void tinkle() {}
};

/* Composition */
class dog
{
    ring m_ring;
    public :
    void tinkle()
    {
        m_ring.tinkle();
    }   // Call forwading
};

// The above things are known as call forwading, in it represents composition relationship.
// The same can be achieved with private inheritance.


// Achieving composition relationship using private inheritance.
class dog1 : private ring
{
    public :
    using ring::tinkle;
};

// Difference in private inheritance and composition.
// In private, it can access all other protected members,
// In general composition is preferred over private inheritance.
//  Beacause 1. Composition is considered bbetter code structure, as dog can access public interfaces, so more decoupled.
//           2. Composition is more flexible, case when do has 2 rings,same can not be achieved using private inheritance.
//           3. At run time, changing the rings.

int main()
{

    return 0;
}