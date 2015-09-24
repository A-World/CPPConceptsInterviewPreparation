//------------------------------------------------------------------------
// Filename: Philosopher.cpp
//   The implementation file of the philosopher program
// PROGRAM DISCRIPTION
//   This program uses mutex locks to implement the philosopher
//   problem.  It could cause deadlock.
//------------------------------------------------------------------------

#include <iostream>
#include "Philosopher.h"

extern Mutex *Chopstick[PHILOSOPHERS];  // locks for chopsticks

// -----------------------------------------------------------------------
// FUNCTION  Filler():                                              
//    This function fills a strstream with spaces.                 
// -----------------------------------------------------------------------

static strstream *Filler(int n)
{
     int  i;
     strstream *Space;

     Space = new strstream;
     for (i = 0; i < n; i++)
          (*Space) << ' ';
     (*Space) << '\0';
     return Space;
}

//------------------------------------------------------------------------
// Philosopher:: constructor
//------------------------------------------------------------------------

Philosopher::Philosopher(int Number, int iter)
                        : No(Number), Iterations(iter)
{
     ThreadName.seekp(0, ios::beg);
     ThreadName << "Philosopher" << Number << '\0';
}

//------------------------------------------------------------------------
// Philosopher::ThreadFunc()
//      Philosopher thread.  Each philosopher picks his left followed
// by his right chopsticks.  Each chopstick is protected by a Mutex
// lock, and, as a result, deadlock could happen
//------------------------------------------------------------------------

void Philosopher::ThreadFunc() 
{
     Thread::ThreadFunc();
     strstream *Space;
     int i;

     Space = Filler(No*2);
     for (i = 0; i < Iterations; i++) {
          Delay();                                     // think for a while
          Chopstick[No]->Lock();                       // get left chopstick
          Chopstick[(No+1) % PHILOSOPHERS]->Lock();    // gets right chopstick
          cout << Space->str() << ThreadName.str() 
               << " begin eating." << endl;            
          Delay();                                     // eat for a while
          cout << Space->str() << ThreadName.str()
               << " finish eating." << endl;            
          Chopstick[No]->Unlock();                     // release left chopstick
          Chopstick[(No+1) % PHILOSOPHERS]->Unlock();  // release right chopstick                       
     }
     Exit();
}



