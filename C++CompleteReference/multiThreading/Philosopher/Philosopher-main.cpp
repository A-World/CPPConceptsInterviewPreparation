//------------------------------------------------------------------------
// main() function
//------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>

#include "Philosopher.h"

Mutex *Chopstick[PHILOSOPHERS];  // locks for chopsticks

int main(int argc, char *argv[]) 
{
     Philosopher *Philosophers[PHILOSOPHERS];
     int i, iter;
     strstream name;

     if (argc != 2) {
          cout << "Use " << argv[0] << " #-of-iterations." << endl;
          exit(0);          
     }      
     else
          iter = abs(atoi(argv[1]));

     for (i=0; i < PHILOSOPHERS; i++) {  // initialize chopstick mutex locks
          name.seekp(0, ios::beg);
          name << "ChopStick" << i << '\0';
          Chopstick[i] = new Mutex(name.str());
     }

     for (i=0; i < PHILOSOPHERS; i++) {  // initialize and run philosopher threads
          Philosophers[i] = new Philosopher(i, iter);
          Philosophers[i]->Begin();
     }

     for (i=0; i < PHILOSOPHERS; i++) 
          Philosophers[i]->Join();

     Exit();
     
     return 0;
}


