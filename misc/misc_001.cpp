// Sizes of the class , and compositions

#include <iostream>

using namespace std;


class ABC
{
    public :
    int a, b;
    char c, d;
    void * ptr;

};
class def
{
    public:
        ABC abc;
};

// 2 extra bytes are added for padding.

int main()
{
    ABC a;
    def d;
    cout << "size of abc is "<< sizeof(a)<<" and size of def " << sizeof(d)<<endl;

}




