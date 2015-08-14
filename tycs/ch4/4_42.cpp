#include <iostream>

using namespace std;
int j = 100;
class sample
{
    int i ;

    public:
        sample()
        {
            i = j + 10;
            j = j + 10;
            cout << "Inside constructor with address "<<this << " i = " << i <<endl;
        }
        sample operator +(sample s )
        {
            cout << "Inside the operator + with invoking object address as "<<this 
                 << " and argument object address as "<< &s << " i = " << i << "s.i = " << s.i<< endl;
            return s;
        }

        void member_function(sample s)
        {
            cout << "Inside member_function, address of invoking object is "<<this 
                 << " and argument object address as " << &s <<endl;
        }

        // Copy constructor
        sample (const sample & s)
        {
            cout << "Inside copy Constructor"<<endl;
        }
};

void old_function(sample s)
{
    cout << "Inside old_function, argument object address is "<< &s<<endl;
}

int main()
{
    cout << "Hello World " <<endl;

    sample s,a,b,c,d;

    cout << "******* All objects created successfully "<<endl;
    s = a + b + c + d;

    cout  <<"**************"<<endl;
    s.member_function(a);
    cout <<"************"<< endl;
    old_function(a);

}

/*      Please refer  program 4_42.cpp
 *
 *
 *
 * */


