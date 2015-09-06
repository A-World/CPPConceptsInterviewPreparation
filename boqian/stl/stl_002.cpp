/*
    Introduction to C++	:
    Video           :   Introduction of STL #2: Sequence Containers

    Different container types
    - Sequence containers (arrays and link list)
        - vector, deque, list, forward list, array
    - Associative containers(binary trees)
        - set, multiset
        - map, multimap
    - Unordered containers (hash tables)
        - Unordered set/multiset
        - Unordered map/multimap
*/


/* STL headers */
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric>          // Some numeric algorithm
#include <functional>
//  These are standard include files, if we require some more files, we shall include time to time.

#include <iostream>
#include <memory>
using namespace std;

/*
    Properties of vector
    1. Fast insert/remove at the end : o(1)
    2. slow insert/remove at beginning or in the middle : o(n)
    3. slow search : o(n)
*/

int main()
{
    vector <int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    cout << vec[2]<<endl;           // No bound checkes are performed
    cout << vec.at(2)<<endl;        // Bound checks are performed, exception is thrown, if we try to access beyond range.

    // Following code shall throw exception
    try{
    cout << vec.at(10)<<endl;
    }
    catch (...)
    {
        cout << "Expction caught"<<endl;
    }

    vector <int > :: iterator itr1 = vec.begin();
    vector <int > :: iterator itr2 = vec.end();

    for(vector<int> :: iterator itr = itr1; itr != itr2 ; itr++)
    {
        cout << "Element is "<<*itr<<endl;
    }

    sort (itr1, itr2);
    cout << "Elelmets after sorting are "<<endl;
    for(vector<int> :: iterator itr = itr1; itr != itr2 ; itr++)
    {
        cout << "Element is "<<*itr<<endl;
    }


    for( int i = 0 ; i < vec.size(); i++)
    {
        cout << vec[i]<< " ";
    }

    for (vector <int > ::iterator itr  = vec.begin(); itr != vec.end(); itr ++)
    {
        cout << *itr<< " ";
    }

    //for (it ::vec)                // Check for C++ 11 standard for the same.
    //cout << it << "  "
    cout << endl;

    // To test, vector as dynamically allocted contiguos array of memory

    int *p = &vec[0];
    cout << *p<<endl;
    cout << *(p+ 1)<<endl;
    cout << *(p+ 2)<<endl;

    // Some common API provided by all containers
    if(vec.empty())
    {
        cout << "Not Possible" <<endl;
    }
    cout << vec.size() <<endl;

    vector <int> vec2 (vec);
    vec.clear();
    vec2.swap(vec);

    // No performance penalty, STL is very efficient.
    return 0;
}