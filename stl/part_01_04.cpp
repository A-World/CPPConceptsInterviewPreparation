/*
    Algorithms
    - Algorithms are function templates operatored on iterators.
*/
#include <algorithm>
#include <stddef.h>
#include <iostream>
#include <vector>

//using namespace std;

int main()
{
    std::vector <int> v;
    v.push_back(55);
    v.push_back(33);
    v.push_back(22);
    v.push_back(44);
    v.push_back(11);
    std::cout << v.size()<<std::endl;

    for (auto i = v.begin() ; i != v.end(); i++)
    {
        std::cout << *i<<std::endl;
    }
    std::cout << "After sorting" <<std::endl;
    
    sort (v.begin(),v.end());
    for (auto i = v.begin() ; i != v.end(); i++)
    {
        std::cout << *i<<std::endl;
    }
    
    v.clear();
}



