#include "shell.h"
/*
*
*
*
*/

int check_exit(char *string, char exit[])
{
    unsigned int cnt = 0;
    
    if (!string || !exit)
        return (-1);

    while (string[cnt] && exit[cnt])
    {
        if (string[cnt] != exit[cnt])
            return (-1);
        cnt++;
    }
    
    return (string[cnt] - exit[cnt]);
}
