/*
    You can write your own STL container, algorithms, and iteratros.

    Security problems
    - Buffer overflow, buffer underflow, heap overflow
*/

#include <stddef.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    cout << v.size()<<endl;
    
    // Undefined behaviour
    v[5] = 55; 
    for (size_t i = 0 ; i < v.size() ; ++i)
    {
        cout << v[i] <<endl;
    }
    
    v.clear();
}



