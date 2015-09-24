//------------------------------------------------------------------------
// Filename: Philosopher.h
//   Interface file for class Philosopher
//------------------------------------------------------------------------
 
#ifndef _PHILOSOPHER_H
#define _PHILOSOPHER_H

#include "ThreadClass.h"

#define PHILOSOPHERS     5

class Philosopher: public Thread 
{
     public:
          Philosopher(int Number, int iter);
     private:
          int No;
          int Iterations;
          void ThreadFunc();
};

#endif

