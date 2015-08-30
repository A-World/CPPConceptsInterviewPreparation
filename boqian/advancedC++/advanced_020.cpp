/*
    Introduction to C++	: Koening Lookup    : Need : Theoretic reason

    NOTE :  THIS EXAMPLE IS NOT COMPLETE,  I NEED TO UNDERSTAND HOW TO USE std::accumulate FUNCITON WITH USER DEFINED CLASS.
    - I SHALL REVIST THIS PROGRAM, ONCE I COMPLETE THE ADVANCED C++ ALL 28 VIDEOS.
    
    - Ref : Video : Advanced C++ Koenig Lookup and Namespace Design, last example with accumulate example.
    
*/

#include <iostream>
#include <algorithm>
using namespace std;

namespace A
{
    class Test
    {
        public :
        Test & operator + (Test &t)
        {
            cout << "Inside operator + () function"<<endl;
            return t;
        }
    };
}

int main()
{
    
    A::Test t1,t2,t3;
    int a = 0, b = 0; 
    t3 = t1+t2;
    A::Test arr[3];
    return 0;
}
