/*
	unordered_map 
    - out of map, multimap, set, multiset, only map has operator [] defined.
    - others don't have operator [] defined.    
    
    
*/

#include <stddef.h>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map< int, string > m;

    m[1] = "ONE";
    m[2] = "TWO";
    m[4] = "FOUR";
    m[6] = "SIX";
    m[3] = "THREE";
    m[5] = "FIVE";
    
    
    cout << m[2]<< endl;
    cout << "Size of unorded map is "<< m.size()<<endl;
    
    for (auto i = m.cbegin(); i != m.cend(); i++)
    {
        //cout << "Elemet is "<< *i  <<endl;   
    }
        
    m.clear();
}
