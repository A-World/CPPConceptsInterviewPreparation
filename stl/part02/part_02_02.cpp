/*
	Map : Interators
    - element of map is pair of <const int, string>
    - pair is defined in header utility, it has 2 elemets .first key and .second value
    - Inserting elemets in map, you need not to use function push_back. you can directly insert element into map using m[key] = value;
    - When you insert the elements in map, those are sorted as per key values.
*/

#include <stddef.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Map < key, value> 
    map <int, string> m;
    
    m[10] = "TEN";
    m[1] = "ONE";
    m[2] = "TW0";
    m[4] = "FOUR";
    
    cout << m[4]<<endl;
    m[4] = "four!";
    cout << m[4]<<endl;
    
    
    for (map<int , string> :: iterator i = m.begin(); i != m.end(); i++)
    {
        cout << "Pair is as (" << i->first <<", "<< i->second <<")"  <<endl;   
    }
    
    
    
    m.clear();
}
