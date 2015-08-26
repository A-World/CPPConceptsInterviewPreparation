/*
    Introduction to C++		: Compiler Generated functions
*/
#include <iostream>
#include <vector>
#include <string>
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

    - default constructor is one that can work without any paramter.
*/


class collar 
{
    public :
        collar () {std::cout << "collar is born" <<endl;}
};

class dog
{
    collar m_collar;
    string & m_name;
};

int main()
{
    dog d2;             // Default is availalbe
    return 0;
}   // Need destructor, already defined.