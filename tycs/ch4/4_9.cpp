// Accessing private member of class with the help of pointer.

#include <iostream>
using namespace std;

class sample
{
    private :
        int i;
    public:
        sample (int ii)
        {
            i = ii;
        }
        void display()
        {
            cout << i << endl;
        }
};

int main()
{
    sample s(97);
    s.display();

    int * p = (int *) &s;
    *p = 43;

    s.display();
}

/*
 *   rm -f a.out ; g++ 4_9.cpp ; ./a.out
 *   97
 *   43
 */ 


