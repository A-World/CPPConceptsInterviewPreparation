
#include <iostream>
using namespace std;

class sample
{
    private:
        int i;
        float f;
    public:
        sample(int ii = 0, float ff = 0.0f)
        {
            i = ii;
            f = ff;

            cout << "Inside constructor i = " << i << " f = " << f<<endl;
        }
        sample operator + (sample s)
        {
            sample t;
            t.i = i + s.i;
            t.f = f + s.f;
            return t;
        }
};

int main()
{
    sample s1(3,7.2f), s2;
    s2 = s1 + 10;
    s2 = (sample)20 + s1;
}




