/*
    Please explain the behaviour of following program
*/

#include <stddef.h>
#include <iostream>
#include <vector>

using namespace std;

class sample 
{
    int i;
public:
    sample(int a)
    {
        i = a;
        cout << "constructor with "<<i <<endl;
    }
    ~sample()
    {
        cout << "destrctor with "<< i <<endl;
    }
};

int main()
{
    vector <sample> v;
    v.push_back(11);
    cout << v.size()<<endl;

    v.clear();
}



