#include "shell.h"

char *contac(char **dir, char **parameters)
{
    int cnt1, cnt2, cnt3, cnt4 = 0, sum;
    char concatenate;

    if (dir == NULL || parameters == NULL)
        return (0);
    for (cnt1 = 0; dir[cnt1]; cnt1++)
    {}
    for (cnt2 = 0; parameters[cnt2]; cnt2++)
    {}

    sum = cnt1 + cnt2;
    
    concatenate = malloc(sizeof(char) * sum + 1);

    for (cnt3 = 0; dir[cnt3] != '\0' || parameters[cnt3] != '\0'; cnt3++)
    {
        if (dir[cnt3])
            concatenate = dir[cnt3];
        else
            
            concatenate = parameters[cnt4];
            cnt4++;
    }
    return (concatenate);
}