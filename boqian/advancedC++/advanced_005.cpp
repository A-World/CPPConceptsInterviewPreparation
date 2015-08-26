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


class dog
{
    public :
        string m_name;
        dog (string name = "Bob")
        {
            m_name = name;
            cout << m_name<< " is born" <<endl;
        }

        ~dog()
        {
            cout << m_name << " is died now"<<endl;
        }
};

int main()
{
    dog d1("Henry");    // Default is availalbe
    dog d2;             // Default is availalbe
    d2 = d1;            // It provides copy assignment operator function
    return 0;
}   // Need destructor, already defined.