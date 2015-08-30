/*
    Introduction to C++	:
    Video       :   Advanced C++ Define Implicit Type Conversion

    Implicit : On its own
    - In all which cases this type conversion happens

    Categories of type conversions
                                                        Implicit            Explicit
    Standard Type conversion (build in type)                A                   B
    User defined type conversion                            C                   D

    // Cases where Category C conversion happens : Implicit user defined type conversion happens use cases.
    - This are defined by user
    - User defines it inside their own class.
    - There are two methods to define implicit user defined type conversion.
    - 1. Use constructor that can accept a single paramter
            - Convert other types of object into your class
    - 2. Use of type conversion function
            - Convert an object of your class into other types.

*/

#include <iostream>
#include <string>
using namespace std;

class dog
{
    public :
        dog(string name)            // No explicit
        {                           // If you only want to define a constructor, and no implicit type conversion, always put "explicit" before the constructor to avoid inadvertent type conversion
            m_name = name;
        }

        string getName ()
        {
            return m_name;
        }

        operator string () const
        {
            return m_name;
        }
    private :
        string m_name;
};


int main()
{
    string dogname = "Bob";
    dog dog1 = dogname;         // Convert an object of type string into dog type.
    cout << "My name is "<< dog1.getName()<<endl;

    // Method 2
    string dog2 = dog1;
    cout << dog2<<endl;     // Convert object of your class into object of other class

    // Following statement is giving me error, as it is trying to search operator << on class dog.

    // TODO : Fix error.
    // cout << (dog1)<<endl;     // Convert object of your class into object of other class


    return 0;
}

/**
        Design principle
        - Make interface easy to use correctly and hard to use incorrectly. How hard is enough ? ideally, uncompilable.
        - General Guidelines
            - Avoid defining seemingly unexpected conversion.
            - Avoid defining two-way implicit conversion.


*/
