#include <iostream>
using namespace std;

class base
{
    protected :
        int i;
        public :
        base ()
        {
            cout << "Base class address of i is "<<&i<<endl;
        }
};

class derived : public base
{
    public:
        derived (): base()  // First base class construcor will be called and then derived class constructor will be called.
        {
            cout << "Derived class address of i is " << &i <<endl;
        }
};

int main()
{
    cout <<"Hello World" <<endl;
    derived d1;
  //  base b1;
    
}