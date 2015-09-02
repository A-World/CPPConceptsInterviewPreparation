/*
    Introduction to C++	:
    Video       :   Advanced C++ All Castings Considered - Part II
    Program  Part 1 :

    dynamic_cast examples

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
    Yellodog is derived from dog, that means, all yellowdog are dog but not all dogs are yellow dogs.
*/

class dog
{
    public :
        virtual ~dog()
        {}
};

class yellowdog : public dog
{
    int age;
    public :
        void bark()
        {
            cout << "I am yellowdog "<<endl;
        }

        void barkage()
        {
            cout << "I am yellowdog with age "<<age<<endl;
        }
};


int main()
{
    dog * pd = new dog();

    //pd->bark();   // dog can not bark, as no bark method is asscoiated with it.
    yellowdog * py = dynamic_cast <yellowdog *> (pd);
    // Here dynamic_cast fails, as we are trying to access base class object with use of derived class pointer.

    // Here following statement, it will not crash.
    py->bark();     // although py is null, but py->bark is not null access.
    // compiler will try to interpret the bark function to be static function.
    // Here bark function does not access any data memebr of yellow function, so compiler will treat it as static function.


    // Here the function barkage will not be treated as static function, so it will be null access and program will crash here due to invalid memory access.
    //py->barkage();
    cout << "pd = "<<pd <<endl;
    cout << "py = "<<py <<endl;


    //  With static cast
    py = static_cast <yellowdog *> (pd);        // So no run type check, it will always succeed.

    // With following statements program may crash, as we are trying to access memory that is not with py.
    py->bark();
    py->barkage();
    cout << "pd = "<<pd <<endl;
    cout << "py = "<<py <<endl;

    return 0;
}


