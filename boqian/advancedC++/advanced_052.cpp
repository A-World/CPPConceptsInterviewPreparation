/*
    Introduction to C++	:
    Video           :   Advanced C++ Exceptions in Destructors

    - Excpetion handling, simple tryout
    - Excpetion can be recussive.
*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog
{
    public :
    string m_name ;
    Dog (string name )  { m_name = name; cout << name << " is born" <<endl; }
    ~Dog()
    {
        cout << m_name<<" is destroyed throwing other exception" <<endl;

        try
        {
            throw 40;
        }
        catch ( int e )
        {
            cout << m_name<<" : Exception Hanlding part recieved value as "<<e<<endl;
        }
    }
    void bark() {}
};

int main()
{
    try {
        Dog d1 ("Henry");
        Dog d2 ("Bob");
        throw 20;
        d1.bark();
        d2.bark();

    }
    catch(int e)
    {
        cout << "Exception e = " <<e <<" caugth" <<endl;
    }

    return 0;
}