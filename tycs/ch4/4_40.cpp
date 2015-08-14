#include <iostream>

using namespace std;

class sample
{
    int i;
    float f;
    public:
    sample(int ii, float ff)
    {
        i = ii;
        f = ff;
    }

    operator int ()
    {
        return i;
    }
};

int main()
{
    cout << "Hello World" <<endl;

    sample s (3,7.2f);
    int i = s;
    cout << i<<endl;
        
}


