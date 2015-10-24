/*
    Inheritace with same data member names in base and derived classes
*/

#include <iostream>
using namespace std;

class C1
{
    public :
        virtual int public_int() {}
};

class D1 : public C1
{
    //private :
      //  int public_int;
};


int main()
{
    D1 d1;
    //cout << "public_int " << d1.C1::public_int << endl;
    cout << "size of d1 is " << sizeof(d1)<<endl;     
}
