/*
    Introduction to C++	:
    Video           :   Introduction of STL #2: Sequence Containers

    Example for deque
    - deques can grow both at end and beginning
    - deque provides random access as vector.
    - Underlying desing does not support continuous memory.
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
#include <iostream>
#include <memory>
using namespace std;

/*
    Properties of deque
    1. Fast insert/remove at the beginning and end
    2. slow insert/remove in the middle : o(n)
    3. slow search : o(n)
*/
int main()
{
    deque<int> deq = {4,6,7};   // deq : 4,6,7
    deq.push_front(2);          // deq : 2,4,6,7
    deq.push_back(3);           // deq : 2,4,6,7,3

    // deque has similar interface with vector.
    cout << deq[1] <<endl;
    return 0;
}