/*
    - Simple derived class example.
*/

#include <iostream>
using namespace std;

class base1
{
	public :
		void func1()
        {
            cout << "base1 :: func1()"<<endl;
        }
};
class base2
{
	public :
		void func1()
        {
            cout << "base2 :: func1()"<<endl;
        }
};


class derived : public base1, public base2
{
	public :
		void func1()
        {
            cout << "derived :: func1()"<<endl;
        }
};

int main()
{
    derived d;
    d.base1::func1();
    d.base2::func1();
    
    // Derived class function always overrides the base class functions.
    d.func1();
}
