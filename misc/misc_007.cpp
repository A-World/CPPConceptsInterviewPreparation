/*
	Constructor invokation at vector initlization
    
    Why only once constructor is called when i create a vector of 10 elements.
    - vectors uses copy constructor 
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
};

int main()
{
    std::vector <Fred> v (2);   // Create a vector of 10 elements and initlize each one with value 5
    cout << "Vector size is " << v.size()<<endl;
    for(auto it = v.begin(); it != v.end(); it ++)
        it->printVal();
}