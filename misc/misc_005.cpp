/*
	Constructor invokation at array initlization
*/

#include <iostream>
using namespace std;

class Fred
{
    int var;
    public :
        Fred() { cout << "Default Constructor" <<endl; }
        Fred(int a)
        {
            cout << "Inside constructor "<<endl;
            var = a;
        }
        void printVal()
        {
            cout << "var is "<< var <<endl;
        }
};

int main()
{
    Fred a[10];
    cout << endl;
    Fred *p = new Fred[10];
    cout << endl;
}
