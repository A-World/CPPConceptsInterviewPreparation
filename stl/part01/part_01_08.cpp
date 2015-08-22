/*
    Algorithms : with vector of string
    Use of functors : Lambda expressions : unamed functions
    
    sort : If there are more than 1 elements matching the crieterios, sort funciton can not guarantee unique order of elements, use 
    stable_sort : It guarantees the order in which elements where inserted in vector.
*/
#include <algorithm>
//#include <functional>
#include <stddef.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector <string> v;
    v.push_back("cat");
    v.push_back("antelop");
    v.push_back("puppy");
    v.push_back("man");
    v.push_back("ant");
    v.push_back("bear");    

    stable_sort (v.begin(),v.end(), 
        [] (const string & left, const string & right)
        {
            return    left.size() < right.size() ;// ? left :right ;
        }
    );
    
    for (auto i = v.begin() ; i != v.end(); i++)
    {
        std::cout << *i<<std::endl;
    }
    v.clear();
}
