/*
    Introduction to C++		: Compiler Generated functions 		
*/
#include <iostream>
#include <vector>
using namespace std;
/*
    Compiler silently writes 4 functions if they are not explicitly declared 
    1. Copy constructor
    2. Copy assignment operator
    3. Destructor 
    4. Default constructor (only if no constructor is declared).

    - In case of const or references, the copy assignment operator function is not generated.
    - In case, base class doesn't have constructor, then default constructor will not be generated.
    - In case, base class destructor is private, then destructor will not be generated.
    
*/


class dog ;
//{};


// For above class, following functions shall be provided by compiler, if you remove ; from line 21 and uncomment line 22.

class dog 
{

    public :
    dog(){}         // Default constructor
                    // 1. call base class constructor
                    // 2. call data member constructor
    ~dog() {}       // Destructor
                    // 1. call base class Destructor
                    // 2. call data member's Destructor
                    
    dog(const dog &) {}     // copy constructor
                            // Member by initilization
    dog & operator = (const dog & ) {}  // copy assignment operator
                                        // Member by member copy
};

// Compiler generated functions are empty functions, that do nothing.

int main()
{

    return 0;
}







