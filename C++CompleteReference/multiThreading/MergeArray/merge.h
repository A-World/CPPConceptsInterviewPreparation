// --------------------------------------------------------------//
// File : merge_array.cpp                                        //
//    Header file for class MergeThread definition               //
// PROGRAM DISCRIPTION                                           //
//    This program uses multithreaded programming to merge two   //
//    sorted arrays                                              //
// ------------------------------------------------------------- //

#ifndef _MERGE_ARRAY_H
#define _MERGE_ARRAY_H

// Header files
#include "ThreadClass.h"

//---------------------------------------------------------------//
//  Process Thread Class: 
//     each merging thread determines the position of a given
//     element in the merged array
//---------------------------------------------------------------//

class MergeThread : public Thread
{
     public:
          // constructor
          MergeThread(char whicharray, int Value, int Index, int Array[],
                      int Result[], unsigned No_elements); 

     private:
          void ThreadFunc();       // thread body
          int  value;              // a[i]: value of element index of array a[]
          int  index;              // i   : index in the array a[]
          int  *array;             // another array b[]
          int  *result;            // result array
          char id;                 // identify thread name
          unsigned no_of_elements; // number of elments of array B[]
};

#endif

