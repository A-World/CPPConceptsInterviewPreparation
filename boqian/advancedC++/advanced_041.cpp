/*
    Introduction to C++	:
    Video           :   Advanced C++ Duality Of Public Inheritance - Interface & Implementation
    Program  Part 1 :   Public Inheritance : Implementation without interface
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Public Inheritance : Inheritance Interface + Implementation.
class dog
{
    public :
    virtual void bark () = 0;
    void run () { cout << "I am running "<<endl;}   // This is non virtual method, so it shall not be overriden,
    // This method also contains implemenation.
    virtual void eat () { cout << "I am eating" <<endl; }
    protected : 
        void sleep() { cout << "I am sleeping" <<endl; }  // Only implementaion is provided, no direct interface is provided.
};

class yellowdog : public dog
{
public :
    virtual void bark() { cout << "yellowdog :: I am yellow dog "<<endl;   }
    void isleep() { sleep(); } 
    
};

int main()
{
    return 0;
}