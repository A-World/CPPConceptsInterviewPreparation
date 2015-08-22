/*
    Algorithms : with vector of string
    Use of functors
*/
#include <algorithm>
#include <functional>
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
    v.push_back("bear");    

    sort (v.begin(),v.end(), greater<string>());
    
    for (auto i = v.begin() ; i != v.end(); i++)
    {
        std::cout << *i<<std::endl;
    }
    v.clear();
}
