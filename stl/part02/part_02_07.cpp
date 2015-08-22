/*
	unordered_map 
    - The elements are not sorted as per key.
    - This are implemented with hash tables.
        - Have a chain of buckets. 
        - Each bucket has chain of values.
        - Different keys can generate same hash, so can lie under same bucket.
    
    - Insertion is expected to be constant time O(1), in worst case, with hash collisions, it can be O(n)
    
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
        cout << "the element pair is ("<<i->first<< ", "<< i->second<<")"<<endl;
    }
        
    m.clear();
}
