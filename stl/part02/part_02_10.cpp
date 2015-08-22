/*
    Vector : v.erase function understading
*/
#include <stddef.h>
#include <iostream>
#include <vector>
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
    
    cout << "After erasing"<< endl;
    v.erase(v.cbegin(), v.cbegin() + 4);
    for (auto i = v.cbegin(); i != v.cend(); i++)
    {
        cout << *i <<endl;   
    }
    
    v.clear();
}
