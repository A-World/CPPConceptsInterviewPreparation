
#include <iostream>
#include <cstring>
using namespace std;

class sample
{
    char *p;
    public:
        sample(char *s)
        {
            p = new char [100];   
            cout << "Constructor : Memoery allocated" <<endl;
            strcpy (p,s);
            cout << "string pointed is ("<<p<<")"<<endl;
        }
        ~sample()
        {
            delete [] p;
            cout << "Memory deleted" <<endl;
            cout << "string pointed is ("<<p<<")"<<endl;
        }
        void display()
        {        
            cout << "string pointed is ("<<p<<")"<<endl;
        }

};
int main()
{
    cout << "Hello World" << endl;
    sample s1("Go to bed");
    s1.display();
    cout <<"\n\n\ Calling explicit constructor"<<endl;
    s1.~sample();
    s1.display();
    cout << "***************"<<endl;
    // This function gives run time error, as you try to delete object/ try to access object which is already deleted.
}


