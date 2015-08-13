//  Initilizing const data member.

#include <iostream>
using namespace std;

class sample
{
    private:
        const int i;
    public:
        sample () : i(3)
    {
    
    }
   
        sample(int ii) : i(ii)
    {
    
    }
    void display()
    {
        cout << "value of i is "<<i<<endl;
    }
};

int main()
{
    sample s1;
    s1.display();
    sample s2(100);
    s2.display();
}


