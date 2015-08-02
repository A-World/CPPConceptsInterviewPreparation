
#include <cassert>
#include <cerrno>
#include <pthread.h>
#include <iostream>
#include <queue>

// Forward Declaration
class MutexHelper;

class Mutex
{
    public:
        Mutex();
        ~Mutex();

        bool Create();
        void Destroy();

        void Lock();
        bool Unlock();
        bool Try();

    private:
        pthread_mutex_t m_mutexHandle;
        bool            m_created;

        friend class MutexHelper;
        //  template <typename T> friend class MessageQueue;
};


class MutexHelper
{
    Mutex& m_mutex;    // What exactly is this declaration?

    public:
    MutexHelper(Mutex& mutex);
    ~MutexHelper();
};

MutexHelper::MutexHelper(Mutex& mutex):
    m_mutex(mutex)
{
    assert(true == m_mutex.m_created);
    m_mutex.Lock();
}

MutexHelper::~MutexHelper()
{
    assert(true == m_mutex.m_created);
    if(false == m_mutex.Unlock())
    {
    }
}


Mutex::Mutex():
    m_mutexHandle(),
    m_created(false)
{
}

Mutex::~Mutex()
{
    assert(false == m_created);
}

bool Mutex::Create()
{
    assert(false == m_created);

    pthread_mutexattr_t mutexAttr;

    errno = 0;
    if(pthread_mutexattr_init(&mutexAttr))
    {
        return false;
    }

    if(pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE))
    {
        pthread_mutexattr_destroy(&mutexAttr);
        return false;
    }

    errno = 0;
    if(pthread_mutex_init(&m_mutexHandle, &mutexAttr))
    {
        pthread_mutexattr_destroy(&mutexAttr);
        return false;
    }

    if(pthread_mutexattr_destroy(&mutexAttr))
    {
    }

    m_created = true;
    return true;
}

void Mutex::Destroy()
{
    assert(true == m_created);
    errno = 0;
    if(pthread_mutex_destroy(&m_mutexHandle))
    {
    }

    m_created = false;
}

void Mutex::Lock()
{
    assert(true == m_created);
    errno = 0;
    if(pthread_mutex_lock(&m_mutexHandle))
    {
    }
}

bool Mutex::Unlock()
{
    assert(true == m_created);
    errno = 0;
    if(pthread_mutex_unlock(&m_mutexHandle))
    {
        return false;
    }
    return true;
}

bool Mutex::Try()
{
    assert(true == m_created);
    errno = 0;
    if(0 == pthread_mutex_trylock(&m_mutexHandle))
    {
        return true;
    }
    else
    {
        if(errno == EBUSY)
        {
            return false;
        }
    }
    return false;
}

template <class _ty>
class MessageQueue
{
    private : 
        bool m_created;
        std::queue <_ty> m_queue;
        Mutex m_mutex;
        pthread_cond_t m_cond;

    public:
        MessageQueue() : m_created(false) {}
        ~MessageQueue() { assert(false == m_created);}

        bool Create()
        {
            assert(false == m_created);
            if(false == m_mutex.Create())
            {
                return false;
            }
            if(pthread_cond_init(&m_cond,0))
            {
                m_mutex.Destroy();
                return false;
            }
            m_created = true;
            return true;        
        }
        
        void Destroy()
        {
            assert(true == m_created);

            m_mutex.Lock();
            if(pthread_cond_destroy(&m_cond))
            {
                // Error in destroying cond variable
            }
            m_mutex.Unlock();
            m_mutex.Destroy();
        }

        bool Send (const _ty &val)
        {
            assert (true == m_created);
            return true;
        }
};


int main()
{
    std::cout <<"Hello World" <<std::endl;
}


