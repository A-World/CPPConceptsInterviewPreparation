#include <iostream>

using namespace std;
int j = 100;
class sample
{

    public:
    int i ;
        sample()
        {
            i = j + 10;
            j = j + 10;
            cout << "Inside constructor with address "<<this << " i = " << i <<endl;
        }
        sample operator +(sample & s )
        {
			sample temp;
            cout << "Inside the operator + with invoking object address as "<<this 
                 << " and argument object address as "<< &s << " i = " << i << " s.i = " << s.i<< endl;
			temp.i = s.i + i;
            return temp;
        }

        void member_function(sample &s)
        {
            cout << "Inside member_function, address of invoking object is "<<this 
                 << " and argument object address as "<< &s << " i = " << i << " s.i = " << s.i<< endl;
        }

        // Copy constructor
        sample (const sample & s)
        {
            cout << "Inside copy Constructor"<<endl;
        }
};

void old_function(sample &s)
{
    cout << "Inside old_function, argument object address is "<< &s<< " s.i = "<< s.i << endl;
}

int main()
{
    cout << "Hello World " <<endl;

    sample s,a,b,c,d;

    cout << "******* All objects created successfully "<<endl;
    s = a + b + c + d;
	
	cout << " a.i is "<< a.i<<endl;
	cout << " b.i is "<< b.i<<endl;
	cout << " c.i is "<< c.i<<endl;
	cout << " d.i is "<< d.i<<endl;
	cout << " s.i is "<< s.i<<endl;
    cout  <<"**************"<<endl;
    //s.member_function(a);
    //cout <<"************"<< endl;
    //old_function(a);

}

