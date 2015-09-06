/*
    Introduction to C++	:
    Video           :   Introduction of STL #1: Overview


    N algorithms        M container     N*M implementation
    But with the help of iterators, we need to provide only N+M implementations
    - Easily extenable
*/

/*
        Reasons to use C++ Standard library
        - Code resue, no need to re-invent the wheel
        - Efficiency ( fast and use less resources). Mordern C++ compiler are usaually tuned to optimize for C++ STL code.
        - Accurate, less buggy
        - Terse, readable code, reduced control flow.
        - Standardization, guaranteed availibility
        - A role model for writing libraries.
        - Good knowledge of data sructures and algorithms.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

int main()
{
    vector <int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    vector <int > :: iterator itr1 = vec.begin();
    vector <int > :: iterator itr2 = vec.end();

    for(vector<int> :: iterator itr = itr1; itr != itr2 ; itr++)
    {
        cout << "Element is "<<*itr<<endl;
    }

    sort (itr1, itr2);
    cout << "Elelmets after sorting are "<<endl;
    for(vector<int> :: iterator itr = itr1; itr != itr2 ; itr++)
    {
        cout << "Element is "<<*itr<<endl;
    }

    return 0;
}