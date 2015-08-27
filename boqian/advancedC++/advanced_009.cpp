/*
    Introduction to C++		: struct vs class
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Small passiave objects that carry public data and have no few basic member functions.
// Data container
struct Person_t
{
    string name;        // public
    unsigned age ;
};

// Bigger acative objects that carry private data, interfaced through public member functions
// Complex Data structures.
class Person
{
    string name_;       // private
    unsigned age_;
    
    public :
        unsigned get_age() const {return age_;} // getter or accessor funciton, should be const
        void set_age(unsigned a) {age_ = a; } // setter or mutator
        
        // We hade implemetation, so we have interfaces, 
        // here variables are actually implemenation, we should talk via interfaces.
        
        // e.g. change variable type, 
        // e.g. add some sort of range conditions across variables.
};


/*      Summary
1. Use struct for passive objects with public data, use class for acive objects with private data.
2. Use setter / getter to access class's data
3. Avoid making too many setter/getter if possible
*/

int main()
{
    cout << "Hello World" <<endl;
}
