/*
    Introduction to C++	:
    Video       :   Advanced C++ Assignment to Self in Assignment Operator
    - Writing exception safe code.
    // Pit falls in operator overloading for self assingment
    
*/

#include <iostream>
#include <string>
using namespace std;

class collar 
{};
// Solution 1
class dog
{
public:
    collar *pcollar;
    dog & operator = (const dog & rhs)
    {
        if(this == &rhs)
            return ;
        collar *pcollarOrig = pcollar;
        pcollar  = new collar(*rhs.pcollar);    // When this function throws exception.
        delete pcollarOrig;
        return *this;    
    }
};

//solution 2 
class dog
{
    collar *pcollar;
    dog & operator = (const dog & rhs)
    {
        *pcollar = *rhs.pcollar;    // Member by member copying of collar 
                                    // Call collar's operator=
        return this;
    }
}

int main()
{
    dog d1,d2;
    d1 = d2;        // Looks sily, rare case.
    dog dogs[100];
    int i = 10, j =10 ;
    dogs [i] = dogs[j];

    return 0;
}