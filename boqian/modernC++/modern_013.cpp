/*
        C++ 11 Library- Shared Pointer - II.mp4
        Program 2 : make_shared function, default deleter, customized delete
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
    shared_ptr<Dog> p2 = shared_ptr<Dog>(new Dog("Tank"),
    [] (Dog*p) { cout <<"Customized deleting"<<endl; p->bark(); delete p;});       // constructor


    // Custom delete is useful when u declare shared pointer to marray of objects, without custome delete, it will cause only one object to delete.

    //shared_ptr<Dog> p3 (new Dog[3]); // dog[1] and dog[2] has memory leaks.
    shared_ptr<Dog> p4 (new Dog[3],
    [](Dog*p) { delete []p;});
}

int main()
{
    foo();
    return 0;
}
