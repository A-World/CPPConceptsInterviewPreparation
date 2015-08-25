// C++ 11 lambda function

#include <iostream>
#include <vector>
using namespace std;

template <typename func>
void filter (func f , vector <int > arr )
{
    for (auto i : arr)
    {
        if(f(i))
        {
            cout << i << endl;
        }
    }
}

int main()
{
    cout << "Hello World" <<endl;

    cout << [](int x, int y ) {return x+y;} (3,4) << endl;
    auto f = [] (int x, int y ) { return x+y; };
    cout << f(10,20)<< endl;

    vector <int > v = {1,2,3,4,5,6};

    // functional programming
    filter([](int x) {return x > 3 ;}, v);
    filter([](int x) {return (x > 2 && x < 5);}, v);

    // Access local variable in side the function in lambda function.

    int y = 4;
    filter([&](int x) {return (x > y);}, v);

    return 0;
}
