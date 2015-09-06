/*
    Introduction to C++	:
    Video           :   Advanced C++ Multiple Inheritance - Devil or Angel

    - When one class is derived from more than 1 base classes, this one is called as multiple inheritance
    - Before the function sees accessability of function, it must decide which funciton is best match for funciton call.
    - virtual inheritance.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class File
{
    public :
        string name;
        void open() { cout << "File :: Open () function "<<endl;;}
};

class InputFile : virtual public File
{
    public :
    void read() {}
};

class OutputFile : virtual public File
{
    public :
    void write() {}
};

class IOFile : public InputFile, public OutputFile
{

};

// Diamond shape problem.

int main()
{
    IOFile f;
    f.open();

    // Check, both the point to same string, you can acces it in following methods also.
    f.InputFile::name = "inputFileName";
    cout << f.OutputFile::name <<endl;
    cout << f.name <<endl;
    f.OutputFile::name = "outputFileName";
    cout << f.InputFile::name <<endl;
    cout << f.name <<endl;

    return 0;
}