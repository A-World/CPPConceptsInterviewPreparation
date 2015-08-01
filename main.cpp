#include "iostream"
#include "cerrno"
#include <semaphore.h>
#include "cassert"

class Semaphore
{
public:
	Semaphore() : m_semaphore(), m_created(false)
    {
		std::cout << " Constructor "<<std::endl;
    }
	virtual ~Semaphore()
    {		
        assert(false == m_created);
		std::cout << "Destructor"<<std::endl;
    }

	bool Create(int count)
    {    
        assert(false == m_created);

        errno = 0;
        if(sem_init(&m_semaphore, 0, count))
        {
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
        }
        m_created = false;    
    }

	void Take()
    {
        assert(true == m_created);

        errno = 0;
        if(sem_wait(&m_semaphore))
        {
        }    
    }
	void Give()
    {
        assert(true == m_created);

        errno = 0;
        if(sem_post(&m_semaphore))
        {
        }    
    }
	bool Try()
    {
        assert(true == m_created);
        errno = 0;
        if(sem_trywait(&m_semaphore))
        {
            if(errno == EAGAIN)
            {
                return false;
            }
            return false;
        }
        return true;    
    }
private:
	sem_t	m_semaphore;
	bool	 m_created;
};

int main()
{
		std::cout << "Hello World"<<std::endl;
		Semaphore s;	
}