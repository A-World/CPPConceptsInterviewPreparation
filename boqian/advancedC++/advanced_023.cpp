/*
    Introduction to C++	:
    Video       :   Advanced C++ Define Implicit Type Conversion
    
    Category C Tryout with two classes.
 
    // This program will not compile.
 
*/

#include <iostream>
#include <string>
using namespace std;

// Forward declaration.
class Two ;

class One
{
    public :
        One() {}
        One (Two t);
        operator Two ();
};

class Two 
{
    public:
        Two () {}
        Two (One o);
        operator One();
};

// Function Definations
One :: One (Two t)
{
    cout << "One :: One (Two t)" <<endl;
}

One :: operator Two()
{
    Two t;
    cout << "One :: operator Two()"<<endl;
    return t;
}

Two :: Two(One o)
{
    cout << "Two :: Two(One o)"<<endl;
}
Two :: operator One()
{
    One o;
    cout <<"Two :: operator One()"<<endl;
    return o;
}

int main()
{
    One o1;
    One o2;
    One o3;
    
    Two t1;
    Two t2;
    Two t3;
    
    One ot = t1;
    //Two to = o1;
    
    // As expected, I got comilation error on line One ot = t1; as call to function are ambiguous.
    // Two :: operator One()
    // One :: One (Two t)
    // So there are two functions that can be used.
    
    // So as per design principle discussed in previous example, we shall only practice one converstion methods. 
    // I'll recommend to use method 1, i.e. Convert other type object into your type.
    return 0;
}