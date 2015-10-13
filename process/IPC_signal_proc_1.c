// Inter process communication with help of Signals


#include <stdio.h>
#include <signal.h>

// Declaration 
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
/* Purpose of function : 

    signal() sets the disposition of the signal signum to handler, which is either SIG_IGN, SIG_DFL, 
    or the address  of  a programmer-defined function (a "signal handler").
    If the signal signum is delivered to the process, then one of the following happens:
    *  If the disposition is set to SIG_IGN, then the signal is ignored.
    *  If the disposition is set to SIG_DFL, then the default action associated with the signal 
    *  If  the  disposition  is set to a function, then first either the disposition is reset to SIG_DFL, 
       or the signal is blocked (see Portability below), and then handler is called with argument signum.  
       If  invocation  of  the  handler caused the signal to be blocked, then the signal is unblocked upon 
       return from the handler.
    The signals SIGKILL and SIGSTOP cannot be caught or ignored.
*/

void sigproc()
{
    printf("you have pressed ctrl-c \n");
}

void quitproc()
{
    printf("ctrl-\\ pressed to quit\n");
    exit(0); /* normal exit status */
}

main()
{
    signal(SIGINT, sigproc);
    signal(SIGQUIT, quitproc);
    printf("ctrl-c disabled use ctrl-\\ to quit\n");
    for(;;); /* infinite loop */
}
