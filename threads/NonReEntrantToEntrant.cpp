#include <stdio.h>


/* non-reentrant function */
char lowercase_c(char *string)
{
    static char *buffer;
    static int index;
    char c = 0;

    /* stores the string on first call */
    if (string != NULL) 
    {
        buffer = string;
        index = 0;
    }

    /* searches a lowercase character */
    for (; c = buffer[index]; index++) {
        if (islower(c)) 
        {
            index++;
            break;
        }
    }
    return c;
}