//  Variation 3 : a container as STL template

#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> :: const_iterator IteratorType;

    template <class IteratorType , class T>
IteratorType find(IteratorType begin, IteratorType end, T Value)
{
    while (begin != end && *begin != Value)
        ++begin;
    return begin;
}

int main()
{

    const int Count  = 100;
    vector <int > aContainer (Count);
    for (int i= 0;  i < Count ; i++)
    {
        aContainer[i] = 2*i;
    }
    int Number = 0;
    while(Number != -1) 
    {

        cout << " enter required number (-1 = end):";
        cin >> Number;
        if(Number != -1) 
        {
            // use global find() defined above
            IteratorType position =
                ::find(aContainer.begin(), // use of container methods:
                        aContainer.end(), Number);
            if (position != aContainer.end())
                cout << "found at position "  << (position - aContainer.begin()) << endl;
            else
                cout << Number << " not found!" << endl;
        }
    }
}



























