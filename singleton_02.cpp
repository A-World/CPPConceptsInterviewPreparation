#include <iostream>
using namespace std;

class SingleTon
{
    public :
        SingleTon(const SingleTon &) = delete;
        SingleTon & operator= (const SingleTon &) = delete;

        static SingleTon * GetInstance()
        {
            static SingleTon singleObject;
            return &singleObject;
        }
    private:
        SingleTon() {}
        ~SingleTon() {}
};

int main()
{
    cout << "Hello World" <<endl;
 //   SingleTon *
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
    cout << "Single Object address is " << SingleTon::GetInstance()<<endl;
}





