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


/*
    Define a paramtered constructor, so default constructor won't be generated.
    Disallow Copy constructor
*/

class OpenFile
{
    public :
        OpenFile(string filename) { cout  << "Open file " << filename <<endl;}
       
        // c++ 11 method
       OpenFile (const OpenFile & f) = delete;
        // c++ 03 method
       // private : OpenFile (const OpenFile & f) ;
       // private : OpenFile & operator = (const OpenFile & f) ;
        
};

int main()
{
    // OpenFile file ; // This statement flashes error.
    OpenFile f(string ("secrete.txt"));
    
    // OpenFile f2 (f);    // As we have disallowed copy constructor this statement flashes error.
}   