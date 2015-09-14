/*
        C++ 11 Library- Shared Pointer - I.mp4
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
    // Raw pointer.
    //Dog *p = new Dog("Gunner");

    // With shared pointer
    shared_ptr<Dog> p ( new Dog("Gunner")); // This code is not exception safe.
    // This code has following 2 steps
        // 1. Gunner is created 2. p is created.

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
    //Dog *d = new Dog("TanK");
    shared_ptr<Dog> p  = make_shared<Dog> ("MyDog"); // faster and safer, this code is exception safe.
    cout << p.use_count()<<endl;

    // Operators supported by shared pointer
    p->bark();      // ->
    (*p).bark();    // *  : Dereference
// Following casting is also supported.
//static_pointer_cast
//dynamic_pointer_cast
//const_pointer_cast


    return 0;
}
