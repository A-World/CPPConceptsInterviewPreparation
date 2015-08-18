#include<iostream>
using namespace std;

class base
{
    public :
        string i;
    void display()
    {
        cout << "base :: value of i is " << i<<endl;
    }        
};

class derived : public base 
{
    public :
        int i;
    void display()
    {
        cout << "derived :: value of i is " << i<<endl;
    }
};

int main()
{
    cout << "Hello World" <<endl;
    derived d;
    d.i = 10;
    d.base::i = "20";
    d.display();
    d.base::display();
}
