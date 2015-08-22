/*
	Map : with functional
    - changing the sort order.
*/

#include <stddef.h>
#include <functional>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Map < key, value> 
    map <int, string, greater<int>> m;
    
    m[10] = "TEN";
    m[1] = "ONE";
    m[2] = "TW0";
    m[4] = "FOUR";
        
    
    // cbegin : Shall return const iterator.
    for (auto i = m.cbegin(); i != m.cend(); i++)
    {
        cout << "Pair is as (" << i->first <<", "<< i->second <<")"  <<endl;   
    }
        
    m.clear();
}
