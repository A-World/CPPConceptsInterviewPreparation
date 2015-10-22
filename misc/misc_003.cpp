/*
        You need to remember all the scenarios, An interviewer may ask for different different scenarios.
        Revisiting virtual keyword.
*/

#include <iostream>
using namespace std;

class c1
{
    private :
        int private_int;
    public :
        int public_int;
        void show()
        {
            cout << "Inside public base :: show"<<endl;
        }
};

/*
    Oberservation 1 : While inheriting from base class to derived class, if you don't mention the inheritance types, by default, the public memebers of base becomes the private members of derived.
    - Following class c2 illustrates it.
*/
class c2 :  c1
{
    public :
        void c2show()
        {
            cout << "public_int = " << public_int << endl;
        }
};
class c3 :  public c1
{
    public :
        void c2show()
        {
            cout << "public_int = " << public_int << endl;
        }
};

struct S1
{
    private :
        int private_int;
    public :
        int public_int;
        void show()
        {
            cout << "Inside public base :: show"<<endl;
        }
};

/*
    Oberservation 2 : While inheriting from base struct to derived struct, if you don't mention the inheritance types, by default, the public memebers of base becomes the public members of derived.
    - Following class c2 illustrates it.
*/

struct S2 : S1
{
    public :
        void c2show()
        {
            cout << "public_int = " << public_int << endl;
        }
};

/*
    Mixed inheritace
    struct to class : Public, private, protected and defualt
    class to struct : Public, private, protected and defualt
*/
struct S
{
    private :
        int private_int;
    public :
        int public_int;
        void show()
        {
            cout << "Inside public base :: show"<<endl;
        }
};
class C1 : S
{
    public :
        void c2show()
        {
            cout << "public_int = " << public_int << endl;
        }
};



class CM
{
    private :
        int private_int;
    public :
        int public_int;
        void show()
        {
            cout << "Inside public base :: show"<<endl;
        }
};
struct SM :  CM
{
    public :
        void c2show()
        {
            cout << "public_int = " << public_int << endl;
        }
};



int main()
{
    c2 c;
    c.c2show();

    /*
        Un comment the following line, to observe the compilation error, as per observation 1
    */
    // cout << c.public_int<< endl;
    c3 a;
    a.c2show();
    cout << a.public_int<< endl;

    S2 s;
    s.c2show();
    cout << s.public_int<< endl;      // You are able to successfully access this.

    C1 cc;
    cc.c2show();
    /*
        Note: following line gives comilation error if un commeted.
    */
    //cout << cc.public_int<< endl;      // You are able to successfully access this.


    SM sm;
    sm.c2show();
    cout << sm.public_int<< endl;      // You are able to successfully access this.


}