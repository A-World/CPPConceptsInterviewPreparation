
#include <iostream>
using namespace std;

class base
{
    public :
      virtual  void show()
        {
            cout << "Inside public base :: show"<<endl;
        }
};

class derived : public base 
{
    private :
//    public:
        void show()
        {
            cout << "Inside private derived :: show"<<endl;
        }
};


int main()
{
    derived *p ;
    p = new derived;
    base *bp;
    bp = p; 
    p->show();

}






