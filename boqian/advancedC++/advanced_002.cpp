/* 
    Introduction to C++
    
    const and functions
    
    
    //TODO : When which one of following function will get called.
    void setage(const int & a) 
    void setage(int & a) 
*/
#include <iostream>

using namespace std;

class Dog 
{
    int age;
    string name;
    public:
    Dog()
    {
       age = 3; name = "dummy";
    }

    // const reference
    void setage(const int & a) 
    { 
        age = a; 
    }

    void setage( int & a) 
    { 
        age = a; 
    }
    
    // const return value
    const string  & getName()
    {
        cout << "getName :: Address of name is " << &name<<endl;
        return name;
    }
    
    // const funciton   : this mean, following shall not change any of member varibale of class.
    // const function can not normal member function, it can call only const member function.
    void printDogName() const       // This shall be invoked by const object of class.
    {
        cout << name <<" const function" <<endl; 
        //age++;    // give compilation error.
        //getName();    // give compilation error.
    }
    
    
    void printDogName()         // This overloaded function, this are two different fucntions, so when is with const is invoked, and when is without const is invoked.
    // This shall be invoked by non const object of class.
    {
        cout << getName() <<" non-const function" <<endl; 
        //age++;    // give compilation error.
        //getName();    // give compilation error.
    }
};

int main()
{
    int i = 9 ;
    Dog d;
    d.setage(i);
    cout << i <<endl;
    
    const string  &n = d.getName();                 // you need to use refernce &n here.
    cout << "   main :: Address of name is " << &n<<endl;
    cout << n <<endl;

    const string  wiout_ref = d.getName();                 // new string is taken.
    cout << "   main :: Address of name is " << &wiout_ref<<endl;
    cout << n <<endl;

    d.printDogName();

    // const object
    const Dog d2;
    d2.printDogName();

    return 0;
}







