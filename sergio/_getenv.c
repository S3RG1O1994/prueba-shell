#include "shell.h"
/*
*
*
*
*/

char *_getenv(char *words)
{
    extern char **environ;
    char *other;
    unsigned int cnt1, cnt2, cnt3;

    //Verificar si el words existe

    if (words == NULL)
        return(0);
    
    for (cnt1 = 0; words[cnt1]; cnt1++)
    {}

    for (cnt2 = 0; environ[cnt2]; cnt2++)
    {
        other = environ[cnt2];
        for (cnt3 = 0; other[cnt3] == words[cnt3]; cnt3++)
        {}
        if (cnt3 == cnt1)
        {
            printf("[%d] %s\n", cnt2, other);
            return (other);
        }
        else
        {
                cnt3 = 0;
        }
    }

    return ("NO ENCONTRO NI MIERDA");
}

int main(void)
{
    char *p = _getenv("PATH");
    printf("%S", p);
}


/use/sbin/ls -> ls