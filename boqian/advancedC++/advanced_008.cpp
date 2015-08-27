/*
    Introduction to C++		: Private destructor
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Here destructor is private, so it can not destroyed by main, it can only be destroyed by itself or by its friend.

    - This kind of mechanism is used by reference counting shared pointer.
    - A reference counting shared pointer counts the number of pointers that points to itself, when the count becomes zero, it commits suicide.
    - Provide a public interface to destroy the object.
*/

/*
    *****************************************
    - When a class has private destructor, you can not have local compile time copy of such class, it shall always be dynamically allocated.
    - For Heavy weight objects define private destructor, so they will not be stored on stack, they will be stored in heap.
    *****************************************
*/
/*
    Summary of disallowing functions
    1. C++ 11 : f() = delete
    2. C++ 03 : Declare the function private, and do not define it.
    3. Private Destructor : Stay out of stack.
*/


class OpenFile
{
    public :
        OpenFile(string filename) { cout  << "Open file " << filename <<endl;}
        void destroyMe ()
        {
            // ~OpenFile();        // For statically allocated  // This will not work for local objects.
            delete this;       // For dynamically allocated memeory
        }
    private:
    ~OpenFile()
    {
        cout << "Private Destructor" <<endl;
    }
};

int main()
{
    OpenFile *pf = new OpenFile(string ("secrete.txt"));
    pf->destroyMe();
}
