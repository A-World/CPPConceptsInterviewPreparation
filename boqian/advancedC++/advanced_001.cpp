/* 
    Introduction to C++
    
    const keyword : At is compile time constain that an object can not be modified.

*/
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World"<<endl;
    
    const int i = 9;
    // i = 6 ; // This flashes compile time error.
    /*
    const int *p1  = &i;        // data is const, pointer is not const.
    //    *p1 = 5;        // This will also flashes error.
    p1 ++ ; // This runs fine.
    
    
    
    //int * const p2  = &i;        // means p2 is const but the data pointed by p2 is not const.
    
    const int * const p3 = &i;   // both data and pointer are const.
        
    int const *p4 = &i;     // same as p1
    
    // Thumb rule
    // - If const is on the left of the *, then data is const
    // - If const is on the right of the *, then pointer is const.
    */
    
    // Casting away constness of data 
    
    cout << i << endl;
    const_cast<int &> (i)  = 6;
    cout << i << endl;                  // After this statement, i was exepting i to get value as 6, but is not getting value 6.
    
    // Convert a normal variable in const
    
    int j;
    
    //static_cast<const int & > (j) = 8;      // As expected, this line gives compilation error.
    
    
    string str("A123456789");
    const char *cstr = str.c_str();
    cout << cstr << endl;
    char *nonconst_cstr  = const_cast<char *> (cstr) ; 
    *nonconst_cstr ='B';
    cout << nonconst_cstr << endl;
    
}