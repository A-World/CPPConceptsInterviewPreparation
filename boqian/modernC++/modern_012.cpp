/*
        C++ 11 Library- Shared Pointer - II.mp4
        Program 3 : make_shared function.
        - Use make_shared function, it safer, faster and exception free.
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
    shared_ptr<Dog> p1 = make_shared<Dog>("Gunner");
    shared_ptr<Dog> p2 = make_shared<Dog>("Tank");
    p1 = p2 ; // Gunner is destroyed at this point.
    p1.reset();
    p1 = nullptr;
}

int main()
{
    foo();
    return 0;
}
