/*
	Map 
	- It is implemented as sorted balaced tree
	- insertion is O(log n)
	- erase     is O(log n)
    - iteration is O(n)
	
    string &  map :: operator [int key]  ()
    - Look into map, if key exist, then, return referece to value, else add new element.
    
*/

#include <stddef.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

void foo ( map <int , string > & m)
{
    m[7]= "seven";
}

void foo2 ( const map <int , string > & m)
{
    // m[10], can try to modify the map, so following line gives comiplation error.
    //cout<< "Foo 2 Element is "<< m[10]<< endl;

    // Even if you try to access with simple iterator, it flashes error, use const iterator.
    //    map<int , string >:: iterator i = m.find(10);
    
    map<int , string >:: const_iterator i = m.find(10);
    cout << "Foo 2 Element is "<< i->second<<endl;

    // OR use auto
    
    auto j = m.find(12);
    if(j == m.end())
    {
        cout << "Key was not found"<< endl;
    }
    else
    {
        cout << "Foo 2 Element is "<< j->second<<endl;
    }

    
}

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
    
    foo(m);
    cout<< "Element is "<< m[10]<< endl;
    foo2(m);
    
    
    // cbegin : Shall return const iterator.
    for (auto i = m.cbegin(); i != m.cend(); i++)
    {
        cout << "Pair is as (" << i->first <<", "<< i->second <<")"  <<endl;   
    }
        
    m.clear();
}
