/*
	Placement new operator and explicit call to destructors
*/
#include <iostream>
#include <vector>
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
    //private :
        Fred ( const Fred & f)
        {
            cout << "Copy constructor"<<endl;
        }
        ~Fred()
        {
            cout << "Destructor "<<endl;
        }
};

int main()
{
    char memory[sizeof(Fred)];
    void *p;
    Fred *fp = new (p) Fred(10);
    
    fp->printVal();
    
    fp->~Fred();

}