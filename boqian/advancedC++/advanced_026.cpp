/*
    Introduction to C++	:
    Video       :   Advanced C++ Understanding rvalue and lvalue
    Program  Part 1 :  rvalue and lvalue introduction.

    - C++ 11 has introduced rvalue reference.

    Simplified definations
    - lvalue : An object that occupies some indentifiable location in memery
    - rvalue : An object that is not lvalue

*/

#include <iostream>
#include <string>
using namespace std;
class dog
{
    public :
        void bark(){}
};

int square (const int & x)
{
    return x * x ;
}

int myglobal ;
int & foo ()
{
    return myglobal;
}

int main()
{
    // Some examples of lvalue
    int i =10;
    int *p = &i;
    //i = 2;
    dog d1;

    i = square(i);
    cout << i<< endl;
    cout << square (40) <<endl;
    // examples of r values
    int x = 1;      // here 1 is rvalue.
    int y = i + 2 ;  // here i+2 is r vlaue

    // In following example, &(i+2 ) is rvalue
    // int *px = & (i+2);      // This shall flash compilation error.

//    int sum (int x, int y ) { return x+y ; }
//    int s = sum(3,4);       // here sum(3,4) is rvalue.


    // Example of reference and some important points

    {
        int i ;
        int & r1 = i;

        // int & r2 = 5;        // Correct way is as follows
        const int & r2 = 5;
    }

    // lvalue can be used to create rvalue.
    {
                            // Lvalue       Rvalue
        int i =1 ;          //    i              1
        int x = i + 1 ;     //    x             i+1
        int xy = i;         //    xy             i
    }

    // rvalue can be used to create an lvalue
    int v[3];
    *(v+2) = 4;     // here *(v+2) is now lvalue.

    // Some misconcepts : functions or operator always yeilds rvalues
    {
        int arr[40];
        arr [30] = 30;                // [] operator on arr.
        // 2 nd

        foo() = 50;
        cout << myglobal <<endl;

    }

    // l vlaues and rvalue are both modifiable

    // rvalue for build in type are not modifiable.
    // rvalue for user defined type are modifiable.

    dog().bark();       // Here bark function can modify the dog using this pointer.

    return 0;
}