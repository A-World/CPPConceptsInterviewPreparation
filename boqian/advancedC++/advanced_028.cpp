/*
    Introduction to C++	:
    Video       :   Advanced C++ Resource Managing Class
    Program  Part 1 :
    - case when a class owns pointer to member of other class.
    - Solution 2 is implemented
    - This saves copies of objects as required in STL container.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Here person owns the string through its pointer.

class Person
{
    public :
        Person() {m_pname = 0;}
        Person(string name )
        {
            m_pname = new string (name);
        }
        ~Person()
        {
            delete m_pname;
        }
        // Solution 2 Delete copy constructor and copy assignment operator.
private:
        Person(const Person  & p);
        // Copy assignment operator
        Person & operator = ( const Person & p);

public:
        void printName()
        {
            cout << * m_pname << endl;
        }
    private :
        string * m_pname;
};


int main()
{
    // Here vector is of pointer ot Persons and not actual persons.
    vector <Person *>  persons;
    persons.push_back (new Person("George"));
    // This can be understood as follows
    // 1. "George" is constructed
    // 2. A copy of "George" is saved in the vector persons (this copy is shallow copy, thats is default copy construcot will do.)
    // 3. "George" is destroyed.

    persons.back()->printName();        // This function shall return reference to last element pushed into vector.
    return 0;
}


