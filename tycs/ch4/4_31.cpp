#include <iostream>
using namespace std;

class sample
{
    public:
    sample()
    {
        cout <<"Default constructor" <<endl;
    }

};


int main()
{
    cout << "Hello World" <<endl;

    sample s;
    s = sample();
}


