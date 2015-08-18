#include<iostream>
using namespace std;

class base
{
    private :
        int i[100];
};

class derived : public base
{
    private :
        int j;
};

int main()
{
    cout << "Hello World" <<endl;
    cout << sizeof(derived)<<endl<<sizeof(base) <<endl;
    derived d;
    base b;
    cout << sizeof(d) <<endl << sizeof(b)<<endl;
    
}