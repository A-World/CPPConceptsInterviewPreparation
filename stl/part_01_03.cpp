/*
    use of iterators
    
    v.end () : Points to one ahead of the last element.
    the range is inclusive exclusive range
    [begin, end)
    - Iterators are generalizations of pointers
    - Iterators are operator overloaded, to be consistenst with pointer arithmatic.
        - Following operators are overloaded
        *i : dereference
        ++i or i++ 
        i+offset or i - offset
        i[] : get index
        
    - Every contains comes up with its own iterators. 
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
/*  
    //method 1
    vector<int> :: iterator i = v.begin() + 1;
    cout << *i<<endl;
*/  

    for (vector <int > :: iterator i = v.begin() ; i != v.end(); i++)
    {
        cout << *i<<endl;
    }

    for (auto i = v.begin() ; i != v.end(); i++)
    {
        cout << *i<<endl;
    }

    v.clear();
}



