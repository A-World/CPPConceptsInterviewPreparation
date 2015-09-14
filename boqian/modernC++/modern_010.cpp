/*
        C++ 11 Library- Shared Pointer - I.mp4
        Program 2 : This example show the wrong practice. This program will crash, as it makes attempt to delte object which is already deleted.
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
    // Raw pointer.
    //Dog *p = new Dog("Gunner");

    // With shared pointer
    shared_ptr<Dog> p ( new Dog("Gunner"));
    // shared_ptr keeps track of how many pointers or how many shared pointers are pointing to the object.
    // When that number becomes zero, the object will be deleted automatically.

    cout << p.use_count()<<endl;

    {
        cout << "******************* Creating New shared pointer *********************" <<endl;
        shared_ptr<Dog> p2 = p;
        cout << p.use_count()<<endl;
        cout << p2.use_count()<<endl;
        p2->bark();
        cout << "******************* Out of scope New shared pointer *********************" <<endl;
    }
    cout << p.use_count()<<endl;

    p->bark();  // Dangling pointer
}// Memory leak
int main()
{
    // foo();

    // An object should be assigned to a smart pointer as soon as it is created.
    // Raw pointer should not be used again.
    Dog *d = new Dog("TanK");
    shared_ptr<Dog> p (d); cout << p.use_count()<<endl;
    shared_ptr<Dog> p2 (d); cout << p2.use_count()<<endl;

    return 0;
}
