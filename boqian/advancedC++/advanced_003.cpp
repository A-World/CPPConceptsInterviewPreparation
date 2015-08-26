/*
    Introduction to C++

	Logic constness : Use mutable keywoard
    Bitwise constness   : Use const_cast
*/
#include <iostream>
#include <vector>
using namespace std;

class BigArray
{
    vector <int > v  = {10,20,30,40};
//    mutable             // Solution 1
    int accessCounter = 0;
    int * v2;
    public:
        int getItem(int index) const
        {
  //          accessCounter ++;
            const_cast <BigArray * > (this) -> accessCounter ++;
            cout <<accessCounter<<endl;
            return v[index];
        }

        void setV2Item(int index, int x) const
        {
            *(v2+ index) = x;
        }

    // What is meaning of following declaration
    
    const int * const fun(const int * const &p ) const
    {}
    
    // This is const memeber function
    // return val : return value is a pointer, which is const, and data pointed by pointer is also const.
    //  Paramters
    // const int * const & p        : Means it is const reference to const pointer and also data pointed by pointer is also const.
};

int main()
{
    BigArray b;

    b.getItem(0);
    b.getItem(0);
    b.getItem(0);
    b.getItem(0);
    return 0;
}







