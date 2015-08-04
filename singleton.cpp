// Design a class with only single instance whroughout the execution of program.
// The single instance shall be global.

#include <iostream>
#include<string>

using namespace std;

class Singleton
{

    public:
    // There shall not be any copy constructor, you need to define copy constructor, as compiler shall not provide default copy constructor.
    // Similary, there shall not be any assignment operator. You have to provide empty definations for the same, as follow.


    // In C++ 11 std, if you want to have empty function, then you should assign it to the delete, as follows.
    Singleton(const Singleton &s ) = delete;
    Singleton & operator= (const Singleton &) = delete;
    
    static Singleton * GetInstance()
    {
        if(m_pSingleton == NULL)
        {
            m_pSingleton = new  Singleton();
        }
        return m_pSingleton;
    }

    private :
    static Singleton *m_pSingleton;
    Singleton() {}
};

Singleton *  Singleton::m_pSingleton = NULL;
int main()
{
    cout << "hello World" <<endl;
    Singleton * pSingleton;
    pSingleton = Singleton::GetInstance();
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
    cout << "pSingleton is = "<<pSingleton<<endl;
}


