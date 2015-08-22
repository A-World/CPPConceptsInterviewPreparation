/*
    Algorithms : on basic C array
    
*/
#include <algorithm>
#include <stddef.h>
#include <iostream>

using namespace std;

int main()
{
    int arr[] = {55,33,22,11,44};
    
    int *begin = &arr[0];
    int *end = &arr[0] + 5;
    

    sort (begin,end);
    for (int * i = begin ; i != end; i++)
    {
        std::cout << *i<<std::endl;
    }
}



