// --------------------------------------------------------------//
// File : quicksort.h                                            //
//        head file for class QuickSortThread definition         //
// PROGRAM DISCRIPTION                                           //
//    This program use multithreaded programming to              //
//    implement the quicksort algorithm                          //
// ------------------------------------------------------------- //

#ifndef _QUICKSORT_H
#define _QUICKSORT_H

// header file
#include "ThreadClass.h"

//---------------------------------------------------------------//
//  Process Thread Class: 
//     each thread applies quicksort algorithm to divide the given
//     array and sorts them recursively
//---------------------------------------------------------------//

class QuickSortThread : public Thread
{
     public:
          // constructor
          QuickSortThread(int Lowerbound, int Upperbound, int Array[]); 

     private:
          void ThreadFunc();  // thread body
          int  lowerbound;    // lower bound of the sub-array to be sorted
          int  upperbound;    // upper bound of the sub-array to be sorted
          int  *a;            // pointing to array to be sorted
};

#endif

