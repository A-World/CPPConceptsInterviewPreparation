/*
    Vector : Move elements safisying some criterio

    // Erase all odd elements.
    
    // Dont write loops that will delete elements individually, insead use 
*/

#include <algorithm>
#include <stddef.h>
#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{

    vector <int > v;
    
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    v.push_back(44);
    v.push_back(55);
    
    
    for (auto i = v.cbegin(); i != v.cend(); i++)
    {
        cout << *i <<endl;   
    }
    
    cout << "After removing and compacting"<< endl;
    v.erase(remove_if( v.begin(), v.end(),
        [] (int e)
        {
            return e%2 ==1;
        }
    ),v.end()  );
    for (auto i = v.cbegin(); i != v.cend(); i++)
    {
        cout << *i <<endl;   
    }
    
    
    
    
    v.clear();
}
