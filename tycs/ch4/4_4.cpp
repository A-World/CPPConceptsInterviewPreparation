// Difference between delete a and delete []a

#include <iostream>
using namespace std;
class sample
{
    public:
    sample() 
    {
        cout << "Constructor for object with address is "<<this << endl;       
    }
    ~sample()
    {    
        cout << "Destructor for object with address is "<<this <<endl;       
    }
};

int main()
{
    // Create array of 10 objects
    sample *s = new sample[10];
 //   delete s[];
    delete [] s;
}

/*
 *  - Whenever u allocate memory in array, you need to delete with delete []s;
 *  - Objects are destroyed in reverse order.
 *  
 *  // Command to compile and run : rm -f a.out ; g++ 4_4.cpp ; ./a.out
 *  // output is as follow
 *  Constructor for object with address is 0x86fd00c
 *  Constructor for object with address is 0x86fd00d
 *  Constructor for object with address is 0x86fd00e
 *  Constructor for object with address is 0x86fd00f
 *  Constructor for object with address is 0x86fd010
 *  Constructor for object with address is 0x86fd011
 *  Constructor for object with address is 0x86fd012
 *  Constructor for object with address is 0x86fd013
 *  Constructor for object with address is 0x86fd014
 *  Constructor for object with address is 0x86fd015
 *  Destructor for object with address is 0x86fd015
 *  Destructor for object with address is 0x86fd014
 *  Destructor for object with address is 0x86fd013
 *  Destructor for object with address is 0x86fd012
 *  Destructor for object with address is 0x86fd011
 *  Destructor for object with address is 0x86fd010
 *  Destructor for object with address is 0x86fd00f
 *  Destructor for object with address is 0x86fd00e
 *  Destructor for object with address is 0x86fd00d
 *  Destructor for object with address is 0x86fd00c
 *
 * */



