// Multithreading and MultiProcessing all syntax and explaination
// This program may not even compile.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int main()
{
    // Create an object of pthread
    pthead_t  thread1, thread2;


    // Create new thread
    int pthread_create(pthread_t *thread,               // Thread Indentifier variable
            const pthread_attr_t *attr,      /* attr argument points to a  pthread_attr_t 
                                                structure whose contents are used at thread creation time to determine attributes for 
                                                the new thread; this structure is initialized using pthread_attr_init(3) and  related  
                                                functions. If attr is NULL, then the thread is created with default attributes. */
            void *(*start_routine) (void *), // New thread starts executing by invoking this method.
            void *arg);                      // This are arguements for start_routine function.

    /* To terminate thread, use any one of following methods.  
       1.It calls pthread_exit(3), specifying an exit status value that is available to another thread in the
       same  process that calls pthread_join(3).
       2.It returns from start_routine(). This is equivalent to calling pthread_exit(3) with the value 
       supplied in the return statement.
       3.It is canceled (see pthread_cancel(3)).
       */   
    // Return values by pthread_create
    //  EAGAIN      -   Insufficient resources to create another thread.
    //  EINVAL      -   Invalid seting in attr.
    //  EPERM       -   No permission to set the scheduling policy and paramters specified in attr.


    pthread_exit(3);

    pthread_cancel(3);


    // exit(3) function;
    /*
       Any of the threads in the process calls exit(3), or the main thread performs a return from main().  
       This causes the termination of all threads in the process.
       */


    /* 
       pthreads POSIX threads man page, some important points
       - Threads share the same global memory (data and heap segment), but each thread has its own stack(automatic variables).
       - Threads also share some attributes with process.
       - Following are thread specific attibutes, different for each thread.
       - thread ID
       - signal mask
       - the errno variable
       - alternate signal stack
       - real-time scheduling policy and priority

       - Thread IDs are guaranteed to be unique only within the process.
       - A thread ID can be reused after a terminated thread has been joined or detached thread has been terminated.

       Thread safe functions
       - A thread safe function is one that can be safely called from multiple threads at the same time.
       - It will deliever the same results regardless of whether it is called from multiple threads at the same time.

*/
    pthread_attr_init(3);  /*  There are two functions */
    int pthread_attr_init(pthread_attr_t *attr); // Initlize thread attribute objects
    // This function will initilize thread attribute object with default attribute, use following functions to change attributes.
        pthread_attr_setaffinity_np(3) 
        pthread_attr_setdetachstate(3) 
        pthread_attr_setguardsize(3),
        pthread_attr_setinheritsched(3) 
        pthread_attr_setschedparam(3) 
        pthread_attr_setschedpolicy(3)
        pthread_attr_setscope(3) 
        pthread_attr_setstack(3) 
        pthread_attr_setstackaddr(3) 
        pthread_attr_setstacksize(3)
        pthread_getattr_np(3)
    // Same object can be used to create one or more threads.
    // Calling pthread_attr_init() on thread a thread attribute object that has been initilized results in undefined behaviour.
    // When object is not required, it should be destroyed using pthread_attr_destroy().
    // Destroying a thread attribute object has no effect on threads that were created using the object.
    // Destroyed object, only pthread_attr_init operation is permitted, everything else has undefined behaviour.

        int pthread_attr_destroy(pthread_attr_t *attr); // destroy thread attribute objects



        pthread_atfork(3), 
        pthread_cancel(3);
        /*  This will cancel the execution of the thread.
         *  Thread cancellation depends on cancellablity state and type.
         * */

        pthread_cleanup_push(3)
        // This is used to call some clean up routine when thread is cancelled. 
        // example - unlock a mutex.


        pthread_cond_signal(3), 
        pthread_cond_wait(3), 
        pthread_create(3), 
        pthread_detach(3),
        pthread_equal(3), 
        pthread_exit(3), 
        pthread_key_create(3),
        pthread_kill(3), 
        pthread_mutex_lock(3),
        pthread_mutex_unlock(3), 
        pthread_once(3), 
        pthread_setcancelstate(3), 
        pthread_setcanceltype(3), 
        pthread_setspecific(3),
        pthread_sigmask(3), 
        pthread_sigqueue(3), 
        pthread_testcancel(3)

}













