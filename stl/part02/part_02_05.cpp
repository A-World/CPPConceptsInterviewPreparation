/*
	Map 
    - out of map, multimap, set, multiset, only map has operator [] defined.
    - others don't have operator [] defined.    
    
    set
    // unique elements
    // elements are sorted, when inserted.
    // Real time usecase 
     - files that user has touched.
     - set of unique names, that user has entered.
*/

#include <stddef.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<int>  s;
    
    s.insert (10);
    s.insert (11);
    s.insert (12);
    s.insert (11);
    s.insert (10);
    
    cout << "Size of set is "<< s.size()<<endl;
    
    for (auto i = s.cbegin(); i != s.cend(); i++)
    {
        cout << "Elemet is "<< *i  <<endl;   
    }
        
    s.clear();
}
