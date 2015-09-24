// --------------------------------------------------------------//
// File : merge-main.cpp                                         //
// PROGRAM DISCRIPTION                                           //
//    This program uses multithreaded programming to merge two   //
//    sorted arrays                                              //
// ------------------------------------------------------------- //
#include <iostream>
#include "merge.h"

#define MAX_SIZE  50    // maximum array size

//---------------------------------------------------------------//
//  the main program 
//---------------------------------------------------------------//

int main(int argc, char *argv[])
{
     int  a[MAX_SIZE],                  // sorted array a
          b[MAX_SIZE],                  // sorted array b
          result[MAX_SIZE * 2];         // result array
     int m;                             // no. of elements of a[]
     int n;                             // no. of elements of b[]
     int i;
     MergeThread *Group_A[MAX_SIZE];    // find the position of a[i] in b[]
     MergeThread *Group_B[MAX_SIZE];    // find the position of b[j] in a[]

     cout << "Please input size for array a: " << endl;
     cin >> m; 
     cout << "Please input the elements of array a: " << endl;
     for (i = 0; i < m; i++)
          cin >> a[i]; 

     cout << "Please input size for array b: " << endl;
     cin >> n;
     cout << "Please input the elements of array b: " << endl;
     for (i = 0; i < n; i++)
          cin >> b[i]; 

     // print out array before merging
     cout << "Before merging: array a is:" << endl;
     for (i = 0; i < m; i++)
          cout << a[i] << "   "; 
     cout << endl;
     cout << "Before merging: array b is:" << endl;
     for (i = 0; i < n; i++)
          cout << b[i] << "   ";
     cout << endl;

     for (i = 0; i < m; i++) {  // fire up merging threads for a[i]'s
          Group_A[i] = new MergeThread('A', a[i], i, b, result, n);
          Group_A[i]->Begin();
     }

     for (i = 0; i < n; i++) {  // fire up merging threads for b[i]'s
          Group_B[i] = new MergeThread('B', b[i], i, a, result, m);
          Group_B[i]->Begin();
     }

     // wait for all the child threads
     for (i = 0; i < m; i++)
          Group_A[i]->Join();
     for (i = 0; i < n; i++)
          Group_B[i]->Join();

     // print out the merged array
     cout << "After merging, the result array is:" << endl;
     for (i = 0; i < m + n; i++)
          cout << result[i] << "   "; 
     cout << endl;

     Exit();
     
     return 0;
}

