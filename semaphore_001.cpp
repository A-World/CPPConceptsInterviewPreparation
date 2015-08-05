/*  Problem 1 : Simple serialization
 *  Thread 1                Thread
 * Statement a1         Statement b1
 *
 *  Requirement is such that, statement a1 shall be executed before statement b1. WHow do you ensure the same, with use of semaphore.
 */


#include <iostream>
#include <semaphore.h>
#include <thread>
#include <cassert>
#include <cerrno>

using namespace std;

class Semaphore
{
    public:
        Semaphore() :
            m_semaphore(),
            m_created(false)
        {
        }

        ~Semaphore()
        {
            assert(false == m_created);       
        }

        bool Create(int count)
        {
            assert(false == m_created);
            errno = 0;

            if(sem_init(&m_semaphore, 0, count))
            {
                cout << "Error : sem_init ()"<<endl;
                return false;
            }

            m_created = true;
            return true;
        }

        void Destroy()
        {
            assert(true == m_created);
            errno = 0;
            if(sem_destroy(&m_semaphore))
            {
                cout <<"Error : sem_destroy()"<<endl;
            }
            m_created = false;
        }

        void Take()
        {
            assert (true == m_created);

            errno = 0;
            if(sem_wait(&m_semaphore))
            {
                cout << "Error : sem_wait()" <<endl;
            }
        }

        void Give()
        {
            assert (true == m_created);

            errno = 0;
            if(sem_post(&m_semaphore))
            {
                cout << "Error : sem_post()"<<endl;
            }
        }

        bool Try()
        {
            assert (true == m_created);

            errno = 0;
            if(sem_trywait(&m_semaphore))
            {
                if(EAGAIN == errno )
                {
                    return false;
                }
                cout << "Error : sem_trywait()" <<endl;
                return false;
            }
            return true;        
        }
        
    private:
        sem_t m_semaphore;
        bool  m_created;
};


Semaphore sem;

void function1()
{
  cout << "This is first statement, and shall be executed by thread t1 initially."<<endl;
  sem.Give();
}

void function2()
{
    sem.Take();
    cout << "This is Second statement, and shall be executed by thread t2 after first statement is executed."<<endl;
    sem.Give();
}


int main()
{
    cout << "Simple Serialization Illustration."<<endl;
    
    sem.Create(0);
    
    std::thread t1 (function1);
    std::thread t2 (function2);
    
    t1.join();
    t2.join();

    sem.Destroy();
    cout << "Thank you executing my implementaion © to ashish modi. "<<endl;

}

/*
 *  Command to compile and execute the program.
 *
 *  rm -f  a.out ; g++ semaphore_001.cpp -std=c++11 -pthread ; ./a.out
 *
 */

