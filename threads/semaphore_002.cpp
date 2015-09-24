/*  Problem 2 : Reader Writer Problem
 * 
 *		Assume a shared buffer, where only one writer is present and 3 readers are present, with following conditions.
 *		- When any reader is reading, writer can not write.
 *		- When writer is writing, no reader can read.
 *		- Any number of reader can read at a given time.
 *		Write a program, as per above requirements.
 */


#include <iostream>
#include <semaphore.h>
#include <thread>
#include <cassert>
#include <cerrno>
#include <chrono>

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


string s;

void READ()
{
	while (1)
	{
		cout << "Thread ID ["<<std::this_thread::get_id()<<"]Reading buffer contains ("<< s <<")"<<endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void WRITE()
{
	while(1)
	{
		cout << "Thread ID ["<<std::this_thread::get_id()<<"]Writing buffer"<<endl;
		s += " ashish " ;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int main()
{
    cout << "Reader Writer Problem Part - 1"<<endl;
    s = "Default String";
    sem.Create(0);
    
    std::thread read1 (READ);
    std::thread read2 (READ);
    std::thread read3 (READ);
    std::thread write1 (WRITE);
    
    read1.join();
    read2.join();
    read3.join();
    write1.join();

    sem.Destroy();
    cout << "Thank you executing my implementaion © to ashish modi. "<<endl;

}

/*
 *	This checkin is without solution, if you this, you can observe the undefined behaviour.
 *
 *
 *  Command to compile and execute the program.
 *
 *  rm -f  a.out ; g++ semaphore_002.cpp -std=c++11 -pthread ; ./a.out
 *
 */

