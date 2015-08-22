
#include <iostream>

using namespace std;

typedef const int * IteratorType;

IteratorType find (IteratorType begin, IteratorType end, const int & Value)
{
    while (begin != end  && *begin != Value  )
    {
        ++ begin;
    }
    return begin;
}

int main()
{
    const int Count = 100;
    int aContainer[Count];

    IteratorType begin  = aContainer ;
    IteratorType end = aContainer + Count;

    // Fill the array with even numbers.
    for (int i = 0; i < Count ; i ++) 
    {
        aContainer [i] = 2*i;
    }
    
    int Number = 0;
    while(Number != -1)
    {
        cout << "Enter required number (-1 for end) : " ;
        cin >> Number;
        if(Number != -1 )
        {
            IteratorType position  = find (begin, end, Number);

            if(position != end)
            {
                cout << " Found at position  "<< (position - begin)<<end;
            }
            else
            {
                cout <<" Number not found " << Number << endl;
            }
        }
    }
}


























