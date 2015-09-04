/*
    Introduction to C++	:
    Video       :   Advanced C++ Inheritance - Public, Protected, and Private
    Program  Part 2 : Public, protected and private inheritance - introduction
    
    - Public inheritance : IS A relationship.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class B
{
    public      : void f_pub()      {  cout << "B:f_pub is called"<<endl;     }
    private     : void f_priv()     {  cout << "B:f_priv is called"<<endl;     }
    protected   : void f_prot()     {  cout << "B:f_prot is called"<<endl;     }
};

class D_pub : public B
{
    public :
        void f()
        {
            f_pub();        // OK. D_pub public function
            //f_priv();     // Error. B's private function.
            f_prot();       // OK. D_pub protected function
        }
};

class D_prot : protected B
{
    public :
        using B::f_pub;

        void f()
        {
            f_pub();        // OK. D_pub protected function
            //f_priv();     // Error. B's private function.
            f_prot();       // OK. D_pub protected function
        }
};

class D_priv : private B
{
    public :
        void f()
        {
            f_pub();        // OK. D_pub private function
            //f_priv();     // Error. B's private function.
            f_prot();       // OK. D_pub private function
        }
};

int main()
{
    D_pub dpub;
    dpub.f();
    dpub.f_pub();

    D_prot dprot;
    dprot.f();
    dprot.f_pub();              // Note that, using B::f_pub;, this statement brings the function in public scope, hence althoug it is protected, it is accessible.

    D_priv dpriv;
    dpriv.f();

    return 0;
}