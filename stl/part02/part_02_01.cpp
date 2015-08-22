/*
    Sequence container
    - vector
    - list
    - deque
    - Forward_list
    
    Associative container
    keys are associated with values
    - maps
    - Multimaps
    - set
    - multisets
    
    - unordered_map
    - unordered_multimap
    - unordered_set
    - unordered_multisets
    
    Containers adaptors
    - stack
    - queue
    - priority_queue
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
    
    // Inserting elemets in map, you need not to use function push_back. you can directly insert element into map.
    m[10] = "TEN";
    m[1] = "ONE";
    m[2] = "TW0";
    m[4] = "FOUR";
    
    cout << m[4]<<endl;
    m[4] = "four!";
    cout << m[4]<<endl;
    
    
    m.clear();
}








