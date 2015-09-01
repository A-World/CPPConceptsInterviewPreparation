/*
    Introduction to C++	:
    Video       :   Advanced C++ All Castings Considered - Part I
    Program  Part 1 :

    Type conversions
    1. Implicit type conversions
    2. Explicit type converiosn (casting) can be achieved with
        static_cast
        dynamic_cast
        const_cast
        reinterpret_cast
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main()
{
/*
1. static_cast
    - Convert one object to another type.
    - type conversion shall be defined.
    dog d1 = static_cast < dog > (string ("BOB"));
    - convert pointer or reference from one type to a related type (down / up cast)

    dog * pd = static_cast <dog*> (new yellowdog());
*/

    int i = 9 ;
    float f = static_cast <float > (i);
    cout << f<<endl;

/*
2. dynamic_cast
    dog *pd = new yellowdog();      // This is static_cast

    yellowdog py = dynamic_cast <yellowdog * >(pd);
    - It works only on pointers or references and does nto work on object.
    - It converts from one type to related type (down cast ) or (base class to derived class)
    - It performs run time check, if succeed, py = pd, else py = 0;
    - It requires the 2 types to be polymorphic (have virtual function).
*/

/*
3. const_cast
    - Only work on pointer or reference
    - work only on same type.
    - cast away constness of object.
*/
    const char * str = "Hello World.";
    char *modifiable = const_cast<char *> (str);

    cout << str<<endl;
    cout <<modifiable <<endl;
    modifiable  = "New string";
    cout <<modifiable <<endl;

/*
4. reinterpret_cast
    - Can only work on pointers or reference, it can not work on object itself.
    - To any type
    - most powerfull cast.
*/

    return 0;
}


