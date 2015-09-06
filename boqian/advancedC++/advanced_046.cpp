/*
    Introduction to C++	:
    Video           :   Advanced C++ Multiple Inheritance - Devil or Angel

    Pure abstract class : A class has one or more pure virtual method.

    Pure Abstract  Classes :
    - A class containing only pure virtual function
    - No data
    - No concrete functions.
 */

/*
*********************************************************************************************
1. Multiple inheritace is an important technique, e.g. ISP - Interface Segregation Principle
2. Derive only from Pure Abstract Classes when using Multiple Inheritace.
*********************************************************************************************
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Here OutputFile is pure abstract class.
class OutputFile
{
    public :
        virtual void open() = 0;
        virtual void write() = 0;
};

int main()
{

    return 0;
}