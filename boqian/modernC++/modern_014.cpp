/*
        C++ 11 Library- Shared Pointer - II.mp4
        Program 3 : p.get() function, convert smart pointer to raw pointer
*/
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog
{
    string _name;
    public :
        Dog(string name )
        {
            cout << "Dog is created : " << name <<endl;
            _name = name;
        }
        Dog ()
        {
            cout << "Dog is created : " << endl;
            _name = "Nameless";
        }
        ~Dog()
        {
            cout << "Dog is destroyed : " <<_name<< endl;
        }
        void bark()
        {
            cout << "Dog " <<_name<< " rules!"<<endl;
        }
};

void foo()
{
    shared_ptr<Dog> p1 = make_shared<Dog>("Gunner");    // Using default deleter : operator delete.

    // To recieve raw pointer use following funciton
    Dog *d = p1.get();
    d->bark();
}

int main()
{
    foo();
    return 0;
}
