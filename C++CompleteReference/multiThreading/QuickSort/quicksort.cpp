// --------------------------------------------------------------//
// File : quicksort.cpp                                          //
// PROGRAM DISCRIPTION                                           //
//    Class implemention file for the QuickSortThread class      //
// ------------------------------------------------------------- //

#include <iostream>
#include "quicksort.h"

//---------------------------------------------------------------//
//  QuickSort Class: 
//     constructor
//---------------------------------------------------------------//

QuickSortThread::QuickSortThread(int Lowerbound, int Upperbound, int Array[]) 
                :lowerbound(Lowerbound), upperbound(Upperbound), a(Array)
{
     ThreadName.seekp(0, ios::beg);
     ThreadName << "Sorting" 
                << '(' << Lowerbound << ':' << Upperbound << ')'
                << '\0';
}

//---------------------------------------------------------------//
//  QuickSort Thread Class body: 
//     each thread sort half of the a
//---------------------------------------------------------------//

void QuickSortThread::ThreadFunc()
{
     Thread::ThreadFunc();
     int pivot = a[upperbound];         // pick up pivot value
     int left = lowerbound - 1,         // scan index from left side
         right = upperbound,            // scan index from right side
         tmp, pivotIndex;
     QuickSortThread  *leftSortThread,  // recursive sorting threads
                     *rightSortThread;


     if (lowerbound >= upperbound)
          Exit();                       //return and recursion ends

     while (left < right) {             // partition loop
          do { left++;} while (a[left] < pivot);
          do { right--;} while (a[right] > pivot);
          if (left < right ) {          
               tmp = a[left];
               a[left] = a[right];
               a[right] = tmp;
          }
     }

     pivotIndex = left;                 // put the  pivot back
     tmp = a[pivotIndex];
     a[pivotIndex] = pivot;
     a[upperbound] = tmp;

     // start the "recursive threads"
     leftSortThread = new QuickSortThread(lowerbound, pivotIndex - 1, a);
     leftSortThread->Begin();
     rightSortThread = new QuickSortThread(pivotIndex + 1, upperbound, a);
     rightSortThread->Begin();

     leftSortThread->Join();            // wait for the child threads
     rightSortThread->Join();
     
     Exit();                            // done and exit
}

// end of QuickSort.cpp

