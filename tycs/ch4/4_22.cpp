//  Creating object with different type of constructos.

#include <iostream>

using namespace std;

class sample
{
    public:
        sample()
        {
            cout << "Default constructor address is " << this <<endl;
        }
        /*
        sample(int i, int j)
        {
            cout << "Paramterized constructor" <<endl;
        }
        */
        void display()
        {
            cout << "address of object is "<<this<<endl;
        }
        sample & operator = ( sample &)
        {
            cout << "Inside = operator ()"<<endl;
        }

        // Copy constructor
        sample (sample & s)
        {
            cout << " Inside copy construcor  "<<endl;
        }
};

int main()
{
    /*
    sample() ;
    sample s0;
    sample s1();
    sample s2(10,20);
    */

    // The following statement, will only create only single object, can some one explain me?
    sample s3 = sample();
    s3.display();
}




