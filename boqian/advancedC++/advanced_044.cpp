/*
    Introduction to C++	:
    Video           :   Advanced C++ Multiple Inheritance - Devil or Angel

    - When one class is derived from more than 1 base classes, this one is called as multiple inheritance
    - Before the function sees accessability of function, it must decide which funciton is best match for funciton call.
    - Virtual base class, Issues with initilizing the virtual base class's constuctor.

    - Initilization of base virtual class is responisbility of most derived class.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class File
{
    public :
        //File() { cout << "File :: File() Default constructor"<<endl;}
        File(string fname)
        {
            cout << "File(string fname) constructor"<<endl;
        }
};

class InputFile : virtual public File
{
    public :
    InputFile(string fname) : File(fname)
    {
        cout << "InputFile(string fname) constructor"<<endl;
    }
};

class OutputFile : virtual public File
{
    public :
    OutputFile(string fname) : File(fname)
    {
        cout << "OutputFile(string fname) constructor"<<endl;
    }
};

class IOFile : public InputFile, public OutputFile
{
    public :
        // If in following constructor, if you don't provide File(fname), it will call File() consturctor.

        IOFile(string fname) :  InputFile(fname), OutputFile(fname) , File(fname)
        {
            cout << "IOFile(string fname) constructor"<<endl;
        }
};

// Diamond shape problem.

int main()
{
    IOFile f("MyFile");

    return 0;
}