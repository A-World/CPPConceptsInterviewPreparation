/*
    Introduction to C++	:
    Video       :   Advanced C++ All Castings Considered - Part II
    Program  Part 1 :
    - Trying to remove dynamic cast and acheive same thing as in example 31

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
        virtual ~dog()        {}
        virtual void bark()        {}
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

//    yellowdog * py = dynamic_cast <yellowdog *> (pd);
//    if(py)
//        py->bark();

    pd->bark();
    cout << "pd = "<<pd <<endl;


    return 0;
}


