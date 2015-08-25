#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
    for(int i = 0 ; i > -100 ; i--)
    {
        cout << "from T1 "<<i<<endl;
    }
}

int main()
{   
    std::thread t1 (function_1);
    for (int i = 0 ; i < 100; i++)
    {
        cout << "from main: "  << i << endl;
    }
    t1.join();
    return 0;
} 
