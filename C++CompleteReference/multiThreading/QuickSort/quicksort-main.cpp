// --------------------------------------------------------------//
// File : quicksort_main.cpp                                     //
// PROGRAM DISCRIPTION                                           //
//    This program uses multithreaded programming to             //
//    implement the quicksort algorithm                          //
// ------------------------------------------------------------- //
#include <iostream>
#include "quicksort.h"

//---------------------------------------------------------------//
//  main program 
//---------------------------------------------------------------//

int main(int argc, char *argv[])
{
     QuickSortThread *quicksortthread;
     int *array;
     int arraySize,          // number of elements in the array to be sorted
         i;

     // get the array from user 
     cout << "Please input array size:" << endl;
     cin >> arraySize;

     array = new int[arraySize]; // create the array

     cout << "Please input the array elements: " << endl;
     for (i = 0; i < arraySize; i++)
          cin >> array[i]; 

     cout << "Before quicksort, the array is:" << endl;
     for (i = 0; i < arraySize; i++)
          cout << array[i] << "   ";
     cout << endl;

     // start the quicksort thread
     quicksortthread = new QuickSortThread(0, arraySize - 1, array);
     quicksortthread->Begin();

     // wait for the quicksort thread to finish
     quicksortthread->Join();

     cout << "After quicksort, the array is:" << endl;
     for (i = 0; i < arraySize; i++)
          cout << array[i] << "   "; 
     cout << endl;
     
     Exit();
     
     return 0; 
}

