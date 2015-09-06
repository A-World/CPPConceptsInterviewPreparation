/*
    Introduction to C++	:
    Video           :   Advanced C++ Exceptions in Destructors

    Preventing exceptions from leaving destructors

    - Destructors may throw exceptions
    - you need to be very careful, that exception thrown inside the destructor is caught inside the destructor only, they should not be thrown out of destructor.
 */

#include <iostream>
#include <string>
#include <memory>
using namespace std;


/*
    Solution 1 : Handling exception at destructor side
    Destructor swallo the exception  : 
    ~dog()
    {
        try {
            ....
            throw exceptions
            ....
        }
        catch (... ){}
    }
*/


/*
    Solution 2 : Handling exception to client side.    
    Move the exception-prone code to a different function.
*/

class Dog
{
    public :
    string m_name ;
    Dog (string name )  { m_name = name; cout << name << " is born" <<endl; }
    ~Dog() { cout << m_name<<" is destroyed " <<endl; }
    void bark() {}
    void prepareToDestroy()
    {
        throw 20;
    }
};

int main()
{
    try {
        Dog d1 ("Henry");
        Dog d2 ("Bob");

        d1.bark();
        d2.bark();
        d1.prepareToDestroy();
        d2.prepareToDestroy();
    }
    catch(int e)
    {
        cout << "Exception e = " <<e <<" caugth" <<endl;
    }

    return 0;
}